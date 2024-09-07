# Kenwood TS830S Digital VFO

![PXL_20240907_211404065 PORTRAIT ORIGINAL](https://github.com/user-attachments/assets/91802eb5-43af-45fe-80af-069eaa523328)

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

## Installation

1. Download the Arduino.ino code
2. Download the Encoder library
3. Upload code to the arduino
4. Have fun testing it :)
