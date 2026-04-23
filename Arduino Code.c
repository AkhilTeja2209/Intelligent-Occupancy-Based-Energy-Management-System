#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
const int PIR_PIN   = 7;
const int LDR_PIN   = A0;
const int RELAY_PIN = 8;

// Settings
const int  LDR_THRESHOLD  = 600;
const long AUTO_OFF_DELAY = 2000;

// State
bool lightState = false;
long lastMotionTime = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relay OFF initially

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Energy Mgmt Sys");
  lcd.setCursor(0, 1);
  lcd.print("Initialising...");
  delay(2000);
  lcd.clear();
}

void loop() {
  int pirValue = digitalRead(PIR_PIN);
  int ldrValue = analogRead(LDR_PIN);

  bool isOccupied = (pirValue == HIGH);
  bool isDark = (ldrValue < LDR_THRESHOLD);

  long currentTime = millis();

  // Track motion time
  if (isOccupied) {
    lastMotionTime = currentTime;
  }

  bool motionRecent = (currentTime - lastMotionTime < AUTO_OFF_DELAY);

  // Control logic
  if (isDark && motionRecent) {
    lightState = true;
    digitalWrite(RELAY_PIN, LOW);   // ON
  } else {
    lightState = false;
    digitalWrite(RELAY_PIN, HIGH);  // OFF
  }

  // LCD display
  lcd.setCursor(0, 0);
  if (isOccupied)
    lcd.print("Room: Occupied  ");
  else
    lcd.print("Room: Empty     ");

  lcd.setCursor(0, 1);
  if (isDark && motionRecent)
    lcd.print("Light: ON (Dark)");
  else if (isDark && !motionRecent)
    lcd.print("Dark + Empty    ");
  else
    lcd.print("Bright - OFF    ");

  delay(1000);

  // Serial output (for Python)
  Serial.print(isOccupied);
  Serial.print(",");
  Serial.print(isDark);
  Serial.print(",");
  Serial.println(lightState);
}