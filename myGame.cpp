#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int joyY = A1;
const int buzzer = 8;

int playerRow = 0;

int obstacleCol = 15;
int obstacleRow = 0;

unsigned long lastMove = 0;
int gameSpeed = 250;

bool gameOver = false;

// NEW
int score = 0;
int highScore = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);

  randomSeed(analogRead(0));

  // Load high score from EEPROM
  highScore = EEPROM.read(0);

  if(highScore == 255){
    highScore = 0;
    EEPROM.write(0, 0);
    }
}

void loop() {

  if (gameOver) {
    lcd.clear();
    bool newRecord = false;
    if (score > highScore) {
      newRecord = true;
      }
     
    lcd.setCursor(3, 0);
    lcd.print("GAME OVER");
    tone(buzzer, newRecord ? 1500 : 800, 600);
    delay(2500);
   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Score:");
    lcd.print(score);

    lcd.setCursor(0, 1);
    lcd.print("High:");
    lcd.print(highScore);

    //tone(buzzer, 1000, 500);
    delay(2500);

    // Reset
    score = 0;
    gameOver = false;
    obstacleCol = 15;
    obstacleRow = random(0, 2);
    playerRow = 0;
    lcd.clear();
    return;
  }

  // ---- Read joystick ----
  int yValue = analogRead(joyY);

  if (yValue < 400) playerRow = 0;
  if (yValue > 600) playerRow = 1;

  // ---- Move obstacle ----
  if (millis() - lastMove > gameSpeed) {
    lastMove = millis();

    obstacleCol--;

    if (obstacleCol < 0) {
      obstacleCol = 15;
      obstacleRow = random(0, 2);

      // Increase score when obstacle passes
      score++;

      //add short ding for increased score
      tone(buzzer, 1200, 80);

      //Increase difficulty (speed up game)
      if(gameSpeed > 80){
        gameSpeed -=5;
        }

      // Update high score
      if (score > highScore) {
        highScore = score;
        EEPROM.write(0, highScore);
      }
    }
  }

  // ---- Collision ----
  if (obstacleCol == 0 && obstacleRow == playerRow) {
    gameOver = true;
  }

  // ---- Draw ----
  lcd.clear();

  lcd.setCursor(0, playerRow);
  lcd.print(">");

  lcd.setCursor(obstacleCol, obstacleRow);
  lcd.print("X");

  // Show score in corner
  lcd.setCursor(15, 0);
  if(score > 9){
      lcd.setCursor(14, 0);

    }
   if(score > 100){
      lcd.setCursor(13, 0);
    }
  lcd.print(score);
}
