# OttoDIY_IRControl
Arduino Nanoを使ったオープンソースロボットOtto DIYにDFRobotの赤外線キットを追加して、Otto DIYを赤外線リモコンで操作するスケッチを公開しています。
## 使用パーツ
1. Otto DIY（[公式](https://www.ottodiy.com/)）
2. DFRobot IR Kit for Arduino（[秋月電子通商](http://akizukidenshi.com/catalog/g/gM-07042/), [メーカー公式](https://wiki.dfrobot.com/IR_Kit_SKU_DFR0107_)）
## ボタンの割り当て
<table border="1">
  <tr>
      <th>Button</th>
      <th>MODE: 0<br>sing function</th>
      <th>MODE: 1<br>move function</th>
      <th>MODE: 2<br>playGesture function</th>
  </tr>
  <tr>
      <td>POWER</td>
      <td colspan="3">Otto.home();</td>
  </tr>
  <tr>
      <td>VOL-</td>
      <td colspan="3"></td>
  </tr>
  <tr>
      <td>FUNC/STOP</td>
      <td colspan="3">Change Function Mode (Otto.sing(S_mode1); / Otto.sing(S_mode2); / Otto.sing(S_mode3);</td>
  </tr>
  <tr>
    <td>|<<</td>
    <td>Otto.sing(S_cuddy);</td>
    <td>Otto.turn(2, 1000, 1);</td>
    <td>Otto.playGesture(OttoHappy);</td>
  </tr>  
  <tr>
    <td>>||</td>
    <td>Otto.sing(S_OhOoh);</td>
    <td>Otto.turn(2, 1000, -1);</td>
    <td>Otto.playGesture(OttoSuperHappy);</td>
  </tr>
  <tr>
    <td>>>|</td>
    <td>Otto.sing(S_OhOoh2);</td>
    <td>Otto.bend(1, 500, 1);</td>
    <td>Otto.playGesture(OttoSad);</td>
  </tr>
  <tr>
    <td>V</td>
    <td>Otto.sing(S_surprise);</td>
    <td>Otto.bend(1, 2000, -1);</td>
    <td>Otto.playGesture(OttoVictory);</td>
  </tr>
  <tr>
    <td>VOL+</td>
    <td>Otto.sing(S_buttonPushed);</td>
    <td>Otto.shakeLeg(1, 1500, 1);</td>
    <td>Otto.playGesture(OttoAngry);</td>
  </tr>
  <tr>
    <td>^</td>
    <td>Otto.sing(S_sleeping);</td>
    <td>Otto.shakeLeg(1, 2000, -1);</td>
    <td>Otto.playGesture(OttoSleeping);</td>
  </tr>
  <tr>
    <td>0</td>
    <td>Otto.sing(S_fart1);</td>
    <td>Otto.moonwalker(3, 1000, 25, 1);</td>
    <td>Otto.playGesture(OttoFretful);</td>
  </tr>
  <tr>
    <td>EQ</td>
    <td>Otto.sing(S_fart2);</td>
    <td>Otto.moonwalker(3, 1000, 25, -1);</td>
    <td>Otto.playGesture(OttoLove);</td>
  </tr>
ST/REPT
Otto.sing(S_fart3);
Otto.crusaito(2, 1000, 20, 1);
Otto.playGesture(OttoConfused);

1
Otto.sing(S_happy);
Otto.crusaito(2, 1000, 20, -1);
Otto.playGesture(OttoFart);

2
Otto.sing(S_happy_short);
Otto.flapping(2, 1000, 20, 1);
Otto.playGesture(OttoWave);

3
Otto.sing(S_superHappy);
Otto.flapping(2, 1000, 20, -1);
Otto.playGesture(OttoMagic);

4
Otto.sing(S_sad);
Otto.swing(2, 1000, 20);
Otto.playGesture(OttoFail);

5
Otto.sing(S_confused);
Otto.tiptoeSwing(2, 1000, 20);

6
Otto.sing(S_connection);
Otto.jitter(2, 1000, 20);

7
Otto.sing(S_disconnection);
Otto.updown(2, 1500, 20);

8
Otto.walk(2, 1000, 1);
Otto.ascendingTurn(2, 1000, 50);	

9
Otto.walk(2, 1000, -1);
Otto.jump(1, 2000);

</table>
