
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define POT_PIN 34
#define RELAY_PIN 25
#define RED_LED 26
#define GREEN_LED 27

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation");
  delay(2000);
  lcd.clear();
}


void loop() {
  int value = analogRead(POT_PIN);
  int moisture = map(value, 0, 4095, 0, 100);

  bool dry = moisture < 35;

  digitalWrite(RELAY_PIN, dry ? HIGH : LOW);
  digitalWrite(RED_LED, dry ? HIGH : LOW);
  digitalWrite(GREEN_LED, dry ? LOW : HIGH);

  // LCD output
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisture);
  lcd.print("%   ");

  lcd.setCursor(0, 1);
  if (dry) {
    lcd.print("PUMP: ON  SOIL:DRY");
  } else {
    lcd.print("PUMP: OFF SOIL:WET");
  }

  // Serial Monitor output
  Serial.println("--------------------");
  Serial.print("Soil Moisture: ");
  Serial.print(moisture);
  Serial.println("%");

  if (dry) {
    Serial.println("Soil Status: DRY");
    Serial.println("Water Pump: ON");
    Serial.println("Action: Watering Started");
  } else {
    Serial.println("Soil Status: WET");
    Serial.println("Water Pump: OFF");
    Serial.println("Action: Soil Moisture Sufficient");
  }

  delay(1500);
}

