# arduino-dodging-game
An obstacle dodging mini game built for a **16x2 LCD screen, a joystick module, and an active buzzer**!
Control your player and dodge incoming obstacles while your score increases and the game speeds up over time!
This project also saves your high score permanently using EEPROM, so it stays even after power is removed!

## Gameplay
You control the player (>) on the left side of the screen.

Obstacles (X) move from right to left.

Move up/down using the joystick to avoid collisions.

Every obstacle you survive increases your score.

The game gradually speeds up as your score increases.

A short buzzer sound plays when you score.

A different buzzer tone plays on game over (higher if you beat the high score).



## Components Needed

| Component | Quantity |
|----------|----------|
| Arduino Uno / Nano | 1 |
| 16x2 LCD (HD44780) | 1 |
| Joystick Module | 1 |
| Active Buzzer | 1 |
| 10k Potentiometer (LCD contrast) | 1 |
| Breadboard + jumper wires | as needed |



## Wiring

### LCD 16x2 (Parallel Mode)

| LCD Pin | Arduino Pin |
|--------|-------------|
| RS | 12 |
| E  | 11 |
| D4 | 5 |
| D5 | 4 |
| D6 | 3 |
| D7 | 2 |
| VSS | GND |
| VDD | 5V |
| RW | GND |
| VO (contrast) | Potentiometer middle pin |
| A (backlight +) | 5V (or through resistor) |
| K (backlight -) | GND |



### Joystick

| Joystick Pin | Arduino Pin |
|-------------|-------------|
| VRy | A1 |
| VCC | 5V |
| GND | GND |

**Only the Y-axis is used in this game.**



### Buzzer

| Buzzer Pin | Arduino Pin |
|------------|-------------|
| + | 8 |
| - | GND |



## Libraries Used

This project uses only built-in Arduino libraries:

- `LiquidCrystal.h`
- `EEPROM.h`
