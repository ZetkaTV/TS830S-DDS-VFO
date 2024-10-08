# Kenwood TS830S Digital VFO

![PXL_20240907_211404065 PORTRAIT ORIGINAL](https://github.com/user-attachments/assets/91802eb5-43af-45fe-80af-069eaa523328)



https://github.com/user-attachments/assets/b747c562-86cc-4725-a8f5-eb4e93015a33



## AD9833 based digital VFO for kenwood TS830/530/other radios :)

### Pinout:

| Arduino   | AD9833 |    
|-----------|--------|
| 5V        | VCC    |
| GND       | DGND   |
| 11 (MOSI) | SDATA  |
| 13 (SCK)  | SCLK   |
| 10 (SS)   | FSYNC  |

| Arduino | Encoder |
|---------|---------|
|   2     |   CLK   |
|   3     |   DT    |
|   4     |   SW    |


### Kenwood VFO connector
![image](https://github.com/user-attachments/assets/731ca900-91f8-4690-ba3e-0c194500833d)


## Parts List:
1. [AD9833](https://www.analog.com/media/en/technical-documentation/data-sheets/ad9833.pdf)
2. Arduino Uno/Nano/Leonardo/Mega (basically any, you just need to check the pinouts)
3. Any Encoder
4. Some jumper cables :)

## Installation

1. Download the Arduino.ino code
2. Download the [Encoder](https://www.arduino.cc/reference/en/libraries/encoder/) library
3. Download the [AD9833](https://github.com/RobTillaart/AD9833) library by Rob Tillaart
4. Upload code to the arduino
5. Have fun testing it :)

### If you have any problems or need help, open a issue thread on github :)
