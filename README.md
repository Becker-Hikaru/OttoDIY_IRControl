# OttoDIY_IRControl
Arduino Nanoを使ったオープンソースロボットOtto DIYにDFRobotの赤外線キットを追加して、Otto DIYを赤外線リモコンで操作するスケッチを公開しています。
## 使用パーツ
1. Otto DIY（[公式](https://www.ottodiy.com/)）
2. DFRobot IR Kit for Arduino（[秋月電子通商](http://akizukidenshi.com/catalog/g/gM-07042/), [メーカー公式](https://wiki.dfrobot.com/IR_Kit_SKU_DFR0107_)）
## ボタンの割り当て
| Button | MODE\: 0<br>sing function | MODE\: 1<br>move function | MODE\:2<br>playGesture function |
| --- | --- | --- | --- |
| POWER | Otto.home(); |
| VOL- |
| FUNC/STOP | Change Function Mode (Otto.sing(S_mode1); / Otto.sing(S_mode2); / Otto.sing(S_mode3); |
| \|<< | Otto.sing(S_cuddy); | Otto.turn(2, 1000, 1); | Otto.playGesture(OttoHappy); |
| >\|\|	| Otto.sing(S_OhOoh);	| Otto.turn(2, 1000, -1);	| Otto.playGesture(OttoSuperHappy); |
| >>\| | Otto.sing(S_OhOoh2); | Otto.bend(1, 500, 1); | Otto.playGesture(OttoSad); |
|V | Otto.sing(S_surprise);	| Otto.bend(1, 2000, -1);	| Otto.playGesture(OttoVictory); |
| VOL- | Otto.sing(S_buttonPushed); |	Otto.shakeLeg(1, 1500, 1); | Otto.playGesture(OttoAngry); |
| ^	| Otto.sing(S_sleeping); | Otto.shakeLeg(1, 2000, -1); | Otto.playGesture(OttoSleeping); |
| 0	| Otto.sing(S_fart1); | Otto.moonwalker(3, 1000, 25, 1); | Otto.playGesture(OttoFretful); |
| EQ | Otto.sing(S_fart2); | Otto.moonwalker(3, 1000, 25, -1); | Otto.playGesture(OttoLove); |
| ST/REPT | Otto.sing(S_fart3); | Otto.crusaito(2, 1000, 20, 1); | Otto.playGesture(OttoConfused); |
| 1 | Otto.sing(S_happy);	| Otto.crusaito(2, 1000, 20, -1); | Otto.playGesture(OttoFart); |
| 2	| Otto.sing(S_happy_short); | Otto.flapping(2, 1000, 20, 1); | Otto.playGesture(OttoWave); |
| 3	| Otto.sing(S_superHappy); | Otto.flapping(2, 1000, 20, -1); | Otto.playGesture(OttoMagic); |
| 4	| Otto.sing(S_sad); | Otto.swing(2, 1000, 20); | Otto.playGesture(OttoFail); |
| 5	| Otto.sing(S_confused); | Otto.tiptoeSwing(2, 1000, 20); |
| 6 | Otto.sing(S_connection); | Otto.jitter(2, 1000, 20); |
| 7 | Otto.sing(S_disconnection); | Otto.updown(2, 1500, 20); |
| 8	| Otto.walk(2, 1000, 1); | Otto.ascendingTurn(2, 1000, 50); |	
| 9 |	Otto.walk(2, 1000, -1); | Otto.jump(1, 2000); |
