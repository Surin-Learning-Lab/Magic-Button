#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <base64.h>

int ledPin = D4;

const char* ssid = "*********";
const char* password = "********";

const char* accountSID = "*****************************";
const char* authToken = "******************************";
const char* fromNumber = "+***********";
const char* toNumber = "+****************";

const char *twilioServer = "api.twilio.com";
const int twilioPort = 443;

WiFiClientSecure client;

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    delay(10);

    Serial.println();
    Serial.println("Connecting to WiFi...");

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");

    // Initialize secure client
    client.setInsecure();
}

void loop()
{
    if (digitalRead(D1) == LOW)
    {
        makeVoiceCall();
        digitalWrite(ledPin, HIGH);
        delay(1000); // Debounce delay
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }
}

void makeVoiceCall()
{
    Serial.println("Making voice call...");

    if (client.connect(twilioServer, twilioPort))
    {
        digitalWrite(ledPin, HIGH);
        // Prepare Twilio credentials in base64 format
        String credentials = accountSID;
        credentials += ":";
        credentials += authToken;
        String base64Credentials = base64::encode(credentials);

        // Construct the POST request body
        String postBody = "Url=https://demo.twilio.com/docs/voice.xml&To=";
        postBody += toNumber;
        postBody += "&From=";
        postBody += fromNumber;

        // HTTP request
        client.println("POST /2010-04-01/Accounts/" + String(accountSID) + "/Calls.json HTTP/1.1");
        client.println("Host: api.twilio.com");
        client.print("Authorization: Basic ");
        client.println(base64Credentials);
        client.println("Content-Type: application/x-www-form-urlencoded");
        client.print("Content-Length: ");
        client.println(String(postBody.length()));
        client.println();
        client.println(postBody);

        // Wait for response
        while (client.connected())
        {
            if (client.available())
            {
                char c = client.read();
                Serial.print(c);
            }
        }
        client.stop();
        Serial.println();
        Serial.println("Voice call made.");
    }
    else
    {
        Serial.println("Connection to Twilio failed");
    }
}
