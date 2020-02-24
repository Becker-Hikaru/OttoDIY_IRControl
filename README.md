# OttoDIY_IRControl
Arduino Nanoを使ったオープンソースロボットOtto DIYにDFRobotの赤外線キットを追加して、Otto DIYを赤外線リモコンで操作するスケッチを公開しています。
## 使用パーツ
1. Otto DIY（[公式](https://www.ottodiy.com/)）
2. DFRobot IR Kit for Arduino（[秋月電子通商](http://akizukidenshi.com/catalog/g/gM-07042/), [メーカー公式](https://wiki.dfrobot.com/IR_Kit_SKU_DFR0107_)）
## 割り当て
| Button | MODE: 0 | MODE: 1 | MODE:2 |
|  | sing function | move function | play Gesture function |
| ---- | ---- | ---- | ---- |
| POWER | Otto.home(); |
| VOL- |   | 
| FUNC/STOP | Change Function Mode (Otto.sing(S_mode1); / Otto.sing(S_mode2); / Otto.sing(S_mode3); |
| \|<< | Otto.sing(S_cuddy); | Otto.turn(2, 1000, 1); | Otto.playGesture(OttoHappy); |
