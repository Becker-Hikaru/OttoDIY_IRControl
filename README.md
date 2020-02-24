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
      <td align="center">POWER</td>
      <td align="center" colspan="3">Otto.home();</td>
  </tr>
  <tr>
      <td align="center">VOL-</td>
      <td colspan="3"></td>
  </tr>
  <tr>
      <td align="center">FUNC / STOP</td>
      <td align="center" colspan="3">Change Function Mode (Otto.sing(S_mode1); / Otto.sing(S_mode2); / Otto.sing(S_mode3);</td>
  </tr>
  <tr>
    <td align="center">|<<</td>
    <td>Otto.sing(S_cuddy);</td>
    <td>Otto.turn(2, 1000, 1);</td>
    <td>Otto.playGesture(OttoHappy);</td>
  </tr>  
  <tr>
    <td align="center">>||</td>
    <td>Otto.sing(S_OhOoh);</td>
    <td>Otto.turn(2, 1000, -1);</td>
    <td>Otto.playGesture(OttoSuperHappy);</td>
  </tr>
  <tr>
    <td align="center">>>|</td>
    <td>Otto.sing(S_OhOoh2);</td>
    <td>Otto.bend(1, 500, 1);</td>
    <td>Otto.playGesture(OttoSad);</td>
  </tr>
  <tr>
    <td align="center">V</td>
    <td>Otto.sing(S_surprise);</td>
    <td>Otto.bend(1, 2000, -1);</td>
    <td>Otto.playGesture(OttoVictory);</td>
  </tr>
  <tr>
    <td align="center">VOL+</td>
    <td>Otto.sing(S_buttonPushed);</td>
    <td>Otto.shakeLeg(1, 1500, 1);</td>
    <td>Otto.playGesture(OttoAngry);</td>
  </tr>
  <tr>
    <td align="center">^</td>
    <td>Otto.sing(S_sleeping);</td>
    <td>Otto.shakeLeg(1, 2000, -1);</td>
    <td>Otto.playGesture(OttoSleeping);</td>
  </tr>
  <tr>
    <td align="center">0</td>
    <td>Otto.sing(S_fart1);</td>
    <td>Otto.moonwalker(3, 1000, 25, 1);</td>
    <td>Otto.playGesture(OttoFretful);</td>
  </tr>
  <tr>
    <td align="center">EQ</td>
    <td>Otto.sing(S_fart2);</td>
    <td>Otto.moonwalker(3, 1000, 25, -1);</td>
    <td>Otto.playGesture(OttoLove);</td>
  </tr>
  <tr>
    <td align="center">ST / REPT</td>
    <td>Otto.sing(S_fart3);</td>
    <td>Otto.crusaito(2, 1000, 20, 1);</td>
    <td>Otto.playGesture(OttoConfused);</td>
  </tr>
  <tr>
    <td align="center">1</td>
    <td>Otto.sing(S_happy);</td>
    <td>Otto.crusaito(2, 1000, 20, -1);</td>
    <td>Otto.playGesture(OttoFart);</td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td>Otto.sing(S_happy_short);</td>
    <td>Otto.flapping(2, 1000, 20, 1);</td>
    <td>Otto.playGesture(OttoWave);</td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td>Otto.sing(S_superHappy);</td>
    <td>Otto.flapping(2, 1000, 20, -1);</td>
    <td>Otto.playGesture(OttoMagic);</td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td>Otto.sing(S_sad);</td>
    <td>Otto.swing(2, 1000, 20);</td>
    <td>Otto.playGesture(OttoFail);</td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td>Otto.sing(S_confused);</td>
    <td>Otto.tiptoeSwing(2, 1000, 20);</td>
    <td></td>
  <tr>
  <tr>
    <td align="center">6</td>
    <td>Otto.sing(S_connection);</td>
    <td>Otto.jitter(2, 1000, 20);</td>
    <td></td>
  </tr>
  <tr>
    <td align="center">7</td>
    <td>Otto.sing(S_disconnection);</td>
    <td>Otto.updown(2, 1500, 20);</td>
    <td></td>
  </tr>
  <tr>
    <td align="center">8</td>
    <td>Otto.walk(2, 1000, 1);<br>* move function</td>
    <td>Otto.ascendingTurn(2, 1000, 50);</td>
    <td></td>	
  </tr>
  <tr>
    <td align="center">9</td>
    <td>Otto.walk(2, 1000, -1);<br>* move function</td>
    <td>Otto.jump(1, 2000);</td>
    <td></td>
  </tr>
</table>
