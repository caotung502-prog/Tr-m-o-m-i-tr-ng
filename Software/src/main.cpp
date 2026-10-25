#include <Arduino.h>
#include <DHT.h>
#include <liquidcrystal_I2C.h>
#define DHTPIN 4    // ESp32 pin GPIO4 connected to the DHT sensor

DHT dht(DHTPIN, DHT11); // Initialize DHT sensor for normal 16mhz Arduino
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address to 0x27 for a 16 chars and 2 line display

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  lcd.clear();
  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed to read");
    lcd.setCursor(0, 1);
    lcd.print("from DHT sensor!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Nhiet Do: ");
    lcd.print(temperature);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    lcd.print("Do Am: ");
    lcd.print(humidity);
    lcd.print(" %");
  }
  delay(2000); 
}