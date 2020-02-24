/* OttoDIY_IRControl.ino */

#include <Otto9.h>
Otto9 Otto;  //This is Otto!

#define PIN_YL 2 //servo[0]  left leg
#define PIN_YR 3 //servo[1]  right leg
#define PIN_RL 4 //servo[2]  left foot
#define PIN_RR 5 //servo[3]  right foot
#define PIN_Trigger  8  //TRIGGER pin (8)
#define PIN_Echo     9  //ECHO pin (9)
#define PIN_Buzzer  13 //BUZZER pin (13)

// 0.1 by pmalmsten http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1176098434
// 0.2 by farkinga
// 0.3 by farkinga - adds cool behaviors
/* 0.4 by pstrobl
   changed the original program to use on IR Kit For Arduino Model: DFR0107 32 bit controller.
   All keypresses are sent to the serial monitor at 9600 baud.
   pulseIn is always HIGH. The phototransistor in the kit does not invert the signal.
   uses pin 13 for heartbeat debug
   32 bits requires a long variable, so divided up into two 15 bit so can use integer variables
   use the first 15 bits of the 32 bits for remote and data stream verification. This code is always the same for every button press
   use the last 15 of the 32 bits for button press selection. This code changes for each button.
   ignore the middle 2 bits, it never changes.
*/

#define IR_BIT_LENGTH 32    // number of bits sent by IR remote
#define FirstLastBit 15     // divide 32 bits into two 15 bit chunks for integer variables. Ignore center two bits. they are all the same.
#define BIT_1 1500          // Binary 1 threshold (Microseconds)
#define BIT_0 450           // Binary 0 threshold (Microseconds)
#define BIT_START 4000      // Start bit threshold (Microseconds)

#define IR_PIN 11            // IR Sensor pin
// #define LED_PIN 13          // LED goes off when signal is received

int debug = 0;              // flag as 1 to output raw IR pulse data stream length in microseconds
int output_verify = 0;      // flag as 1 to print decoded verification integers. same number for all buttons
int output_key = 0;         // flag as 1 to print decoded key integers
int remote_verify = 16128;  // verifies first bits are 11111100000000 different remotes may have different start codes

void setup() {
  // pinMode(LED_PIN, OUTPUT); //This shows when ready to recieve
  pinMode(IR_PIN, INPUT);
  // digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true, A6, PIN_Buzzer, PIN_Trigger, PIN_Echo); //Set the servo pins and ultrasonic pins and Buzzer pin
  Otto.sing(S_connection); //Otto wake up!
  Otto.home();
  delay(50);
}

void loop() {
  // digitalWrite(LED_PIN, HIGH);
  int key = get_ir_key();

  // digitalWrite(LED_PIN, LOW);  // turn LED off while processing response
  do_response(key);
  delay(130);                  // 2 cycle delay to cancel duplicate keypresses
}

/*
  wait for a keypress from the IR remote, and return the
  integer mapping of that key (e.g. power button on remote returns
  the integer 1429)
*/

int get_ir_key()
{
  int pulse[IR_BIT_LENGTH];
  int bits[IR_BIT_LENGTH];

  do {} //Wait for a start bit
  while(pulseIn(IR_PIN, HIGH) < BIT_START);

  read_pulse(pulse);
  pulse_to_bits(pulse, bits);
  RemoteVerify(bits);
  return bits_to_int(bits);
}


/*
  use pulseIn to receive IR pulses from the remote.
  Record the length of these pulses (in ms) in an array
*/

void read_pulse(int pulse[])
{
  for (int i = 0; i < IR_BIT_LENGTH; i++)
  {
    pulse[i] = pulseIn(IR_PIN, HIGH);
  }
}

/*
  IR pulses encode binary "0" as a short pulse, and binary "1"
  as a long pulse.  Given an array containing pulse lengths,
  convert this to an array containing binary values
*/

void pulse_to_bits(int pulse[], int bits[])
{
  if (debug) { Serial.println("-----"); }
  for(int i = 0; i < IR_BIT_LENGTH; i++)
  {
    if (debug) { Serial.println(pulse[i]); }
    if(pulse[i] > BIT_1) //is it a 1?
    {
      bits[i] = 1;
    }
    else if(pulse[i] > BIT_0) //is it a 0?
    {
      bits[i] = 0;
    }
    else //data is invalid...
    {
      Serial.println("Error");
    }
  }
}

/*
  check returns proper first 14 check bits
*/

void RemoteVerify(int bits[])
{
  int result = 0;
  int seed = 1;

  //Convert bits to integer
  for(int i = 0 ; i < (FirstLastBit) ; i++)
  {
    if(bits[i] == 1)
    {
    result += seed;
    }

    seed *= 2;
  }
        if (output_verify)
      {
        Serial.print("Remote ");
        Serial.print(result);
        Serial.println(" verification code");
      }
 if (remote_verify != result) {delay (60); get_ir_key();} //verify first group of bits. delay for data stream to end, then try again.
}


/*
  convert an array of binary values to a single base-10 integer
*/

int bits_to_int(int bits[])
{
  int result = 0;
  int seed = 1;

  //Convert bits to integer
  for(int i = (IR_BIT_LENGTH-FirstLastBit) ; i < IR_BIT_LENGTH ; i++)
  {
    if(bits[i] == 1)
    {
    result += seed;
    }
    seed *= 2;
  }
  return result;
}


/*
  respond to specific remote-control keys with different behaviors
*/

int mode = 0;
void do_response(int key)
{

  if (output_key)
   {
      Serial.print("Key ");
      Serial.println(key);
   }

  switch (key)
  {
    case 32640:  // turns on UUT power
      Serial.println("POWER");
      Otto.home();
      break;

    case 32385:  // FUNC/STOP turns off UUT power
      Serial.println("FUNC/STOP");
      mode = mode + 1;
      if (mode == 1) {
        Otto.sing(S_mode2);
      }
      else if (mode == 2){
        Otto.sing(S_mode3);
      }
      else {
        mode = 0;
        Otto.sing(S_mode1);
      }
      break;

    case 32130:  // |<< ReTest failed Test
      Serial.println("|<<");
      if (mode == 0) {
        Otto.sing(S_cuddly);
      }
      else if (mode == 1){
        Otto.turn(2, 1000, 1);
      }
      else {
        Otto.playGesture(OttoHappy);
      }
      break;

    case 32002:  // >|| Test
      Serial.println(">||");
      if (mode == 0) {
        Otto.sing(S_OhOoh);
      }
      else if (mode == 1){
        Otto.turn(2, 1000, -1);
      }
      else {
        Otto.playGesture(OttoSuperHappy);
      }
      break;

    case 31875:  // >>| perform selected test number
      Serial.println(">>|");
      if (mode == 0) {
        Otto.sing(S_OhOoh2);
      }
      else if (mode == 1){
        Otto.bend(1, 500, 1);
      }
      else {
        Otto.playGesture(OttoSad);
      }
      break;

    case 32512:  // VOL+ turns on individual test beeper
      Serial.println("VOL+");
      break;

    case 31492:  // VOL- turns off individual test beeper
      Serial.println("VOL-");
      if (mode == 0) {
        Otto.sing(S_buttonPushed);
      }
      else if (mode == 1){
        Otto.shakeLeg(1, 1500, 1);
      }
      else {
        Otto.playGesture(OttoAngry);
      }
      break;

    case 31620:  // v scroll down tests
      Serial.println("v");
      if (mode == 0) {
        Otto.sing(S_surprise);
      }
      else if (mode == 1){
        Otto.bend(1, 2000, -1);
      }
      else {
        Otto.playGesture(OttoVictory);
      }
      break;

    case 31365:  // ^ scroll up tests
      Serial.println("^");
      if (mode == 0) {
        Otto.sing(S_sleeping);
      }
      else if (mode == 1){
        Otto.shakeLeg(1, 2000, -1);
      }
      else {
        Otto.playGesture(OttoSleeping);
      }
      break;

    case 30982:  // EQ negative tests internal setup
      Serial.println("EQ");
      if (mode == 0) {
        Otto.sing(S_fart2);
      }
      else if (mode == 1){
        Otto.moonwalker(3, 1000, 25, -1);
      }
      else {
        Otto.playGesture(OttoLove);
      }
      break;

    case 30855:  // ST/REPT Positive tests Select Test and Repeat Test
      Serial.println("ST/REPT");
      if (mode == 0) {
        Otto.sing(S_fart3);
      }
      else if (mode == 1){
        Otto.crusaito(2, 1000, 20, 1);
      }
      else {
        Otto.playGesture(OttoConfused);
      }
      break;

    case 31110:  // 0
      Serial.println("0");
      if (mode == 0) {
        Otto.sing(S_fart1);
      }
      else if (mode == 1){
        Otto.moonwalker(3, 1000, 25, 1);
      }
      else {
        Otto.playGesture(OttoFretful);
      }
      break;

    case 30600:  // 1
      Serial.println("1");
      if (mode == 0) {
        Otto.sing(S_happy);
      }
      else if (mode == 1){
        Otto.crusaito(2, 1000, 20, -1);
      }
      else {
        Otto.playGesture(OttoFart);
      }
      break;

    case 30472:  // 2
      Serial.println("2");
      if (mode == 0) {
        Otto.sing(S_happy_short);
      }
      else if (mode == 1){
        Otto.flapping(2, 1000, 20, 1);
      }
      else {
        Otto.playGesture(OttoWave);
      }
      break;

    case 30345:  // 3
      Serial.println("3");
      if (mode == 0) {
        Otto.sing(S_superHappy);
      }
      else if (mode == 1){
        Otto.flapping(2, 1000, 20, -1);
      }
      else {
        Otto.playGesture(OttoMagic);
      }
      break;

    case 30090:  // 4
      Serial.println("4");
      if (mode == 0) {
        Otto.sing(S_sad);
      }
      else if (mode == 1){
        Otto.swing(2, 1000, 20);
      }
      else {
        Otto.playGesture(OttoFail);
      }
      break;

    case 29962:  // 5
      Serial.println("5");
      if (mode == 0) {
        Otto.sing(S_confused);
      }
      else if (mode == 1){
        Otto.tiptoeSwing(2, 1000, 20);
      }
      break;

    case 29835:  // 6
      Serial.println("6");
      if (mode == 0) {
        Otto.sing(S_connection);
      }
      else if (mode == 1){
        Otto.jitter(2, 1000, 20);
      }
      break;

    case 29580:  // 7
      Serial.println("7");
      if (mode == 0) {
        Otto.sing(S_disconnection);
      }
      else if (mode == 1){
        Otto.updown(2, 1500, 20);
      }
      break;

    case 29452:  // 8
      Serial.println("8");
      if (mode == 0) {
        Otto.walk(2, 1000, 1);
      }
      else if (mode == 1){
        Otto.ascendingTurn(2, 1000, 50);
      }
      break;

    case 29325:  // 9
      Serial.println("9");
      if (mode == 0) {
        Otto.walk(2, 1000, -1);
      }
      else if (mode == 1){
        Otto.jump(1, 2000);
      }
      break;

    default:
      {
        Serial.print("Key ");
        Serial.print(key);
        Serial.println(" not programmed");
      }
    break;
  }
}
