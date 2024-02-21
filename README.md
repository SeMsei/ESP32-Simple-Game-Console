# ESP32-GameConsole
Game console with 2 games: "Snake" and "Racing" using ESP32 and 2 accelerometers MPU6050 for "Racing" game.

## Required components:
* ESP32
* MPU6050 - x2
* OLED SH1106
* Tact Switches - x5
* Dupont Lines

## Connections:
### MPU6050

| ESP32 | MPU6050 |
| ----- | ------- |
| GPIO21 | SDA |
| GPIO22 | SCL |
| 3V3 | VCC |
| GND | GND |

### Additional MPU6050
| ESP32 | MPU6050 |
| ----- | ------- |
| GPIO21 | SDA |
| GPIO22 | SCL |
| 3V3 | VCC |
| 3V3 | AD0 |
| GND | GND |

### SH1106
| ESP32 | SH1106 |
| ----- | ------- |
| GPIO26 | SDA |
| GPIO27 | SCL |
| 3V3 | VCC |
| GND | GND |

### Tact Switches
| ESP32 | Tact Switch |
| ----- | ------- |
| GND | A |
| GPIO4/32/2/17/23 | B |

All GPIO pins can be changed to anyone you want using code. See section below.

## Setup

### Tact Switches
```
int btn_pin1 = 4;   //left
int btn_pin2 = 32;  //up
int btn_pin3 = 2;   //down
int btn_pin4 = 17;  //right
int btn_pin5 = 23;  //ok
```

You can change pins to any convenient, just change the value of variables above.

### OLED SH1106
```
display.init(26, 27);
```

You can change pins to any convenient, just change the value of the 1st argument to the pin you will connect SDA of OLED and the value of the 2nd argument to the pin you will connect SCL of OLED.

### MPU6050
```
Wire1.begin(21, 22);  
```

You can change pins to any convenient, just change the value of the 1st argument to the pin you will connect SDA of OLED and the value of the 2nd argument to the pin you will connect SCL of OLED.

## Dependencies:
* [EncButton](https://github.com/GyverLibs/EncButton) — used for tact switches.
* [GyverOLED](https://github.com/GyverLibs/GyverOLED) - used for oled display.
* [ArduinoSTL](https://github.com/mike-matera/ArduinoSTL) - used for stl vectors.
* [EEPROM](https://github.com/arduino/ArduinoCore-avr/tree/master/libraries/EEPROM) - used for EEPROM.

## Usage
Upload main.ino file into your ESP32 board using ArduinoIDE and enjoy!
