#include <WiFi.h>
#include <ThingESP.h>
#include <ESP32Servo.h>
#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

Servo soilServo;
Servo seedServo;

ThingESP32 thing("Kiran", "FarmPulse", "farmpulse_by_kiran");

const int soilServoPin = 12;
const int seedServoPin = 14;
const int moisturePin = 27;

const int irrigateRelayPin = 25;
const int weedRelayPin = 26;

const int moistureThreshold = 50;

// Function declaration (needed for compilation safety)
String HandleResponse(String query);

void setup() {
    Serial.begin(115200);

    thing.SetWiFi("username", "password"); //Your network credentials
    thing.initDevice();

    dht.begin();

    soilServo.attach(soilServoPin);
    seedServo.attach(seedServoPin);

    pinMode(irrigateRelayPin, OUTPUT);
    digitalWrite(irrigateRelayPin, HIGH);

    pinMode(weedRelayPin, OUTPUT);
    digitalWrite(weedRelayPin, HIGH);
}

// Function to handle WhatsApp commands via Twilio
String HandleResponse(String query) {
    query.trim();
    Serial.println("Received Command: " + query);

    if (query.equalsIgnoreCase("Start Irrigation")) {
        digitalWrite(irrigateRelayPin, LOW);
        return "Irrigation Started ✅";
    } 
    else if (query.equalsIgnoreCase("Stop Irrigation")) {
        digitalWrite(irrigateRelayPin, HIGH);
        return "Irrigation Stopped ⛔";
    } 
    else if (query.equalsIgnoreCase("Start Weed Cutting")) {
        digitalWrite(weedRelayPin, LOW);
        return "Weed Cutting Started ✅";
    } 
    else if (query.equalsIgnoreCase("Stop Weed Cutting")) {
        digitalWrite(weedRelayPin, HIGH);
        return "Weed Cutting Stopped ⛔";
    } 
    else if (query.equalsIgnoreCase("Check Soil")) {
        soilServo.write(90);
        delay(3000);

        int rawMoisture = analogRead(moisturePin);
        int moistureValue = map(rawMoisture, 4095, 0, 0, 100);

        soilServo.write(0);

        float temperature = dht.readTemperature();
        float humidity = dht.readHumidity();

        String response = "🌱 Soil Details:\nMoisture: " + String(moistureValue) +
                          "% (Raw: " + String(rawMoisture) + ")";

        if (moistureValue < moistureThreshold) {
            response += " - LOW ⚠️. Irrigating...";
            digitalWrite(irrigateRelayPin, LOW);
            delay(5000);
            digitalWrite(irrigateRelayPin, HIGH);
        }

        response += "\n🌡 Temperature: " + String(temperature) + "°C\n💧 Humidity: " + String(humidity) + "%";
        return response;
    } 
    else if (query.equalsIgnoreCase("Dispense Seed")) {
        for (int i = 0; i < 4; i++) {
            seedServo.write(45);
            delay(200);
            seedServo.write(0);
            delay(200);
        }
        return "🌾 Seed Dispensing Completed ✅";
    } 
    else if (query.equalsIgnoreCase("temperature")) {
        float temperature = dht.readTemperature();
        float fahrenheit = dht.readTemperature(true);
        return "🌡 Temperature: " + String(temperature) + "°C, " + String(fahrenheit) + "°F";
    } 
    else if (query.equalsIgnoreCase("humidity")) {
        float humidity = dht.readHumidity();
        return "💧 Humidity: " + String(humidity) + " %";
    } 
    else {
        return "⚠️ Invalid Command. Try again!";
    }
}

void loop() {
    thing.Handle();
}
