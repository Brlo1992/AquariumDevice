#include "Router.h"
#include "Result.h"
#include "Service.h"
#include "InfoService.h"
#include "Arduino.h"

Result Router::SelectAction(String route)
{
    Service service = InfoService();
    String body = "";
    Result result = Result();
    Request request = Request();

    if (route.equals(""))
    {
        service = InfoService();
    }
    else if (route.equals("turnOn"))
    {
        Serial.println("Turn on leds");
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        body = "{\"status\": \"on\" }";
    }
    else if (route.equals("turnOff"))
    {
        Serial.println("Turn off leds");
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        body = "{\"status\": \"off\" }";
    }
    else if ((route.substring(0,12)).equals("turnOnLedSet"))
    {
        String id = route.substring(12);
        Serial.println("Turn on single led set");
        Serial.println(id);
        digitalWrite(atoi(id.c_str()), HIGH);
        body = "{\"status\": \"on\" }";
    }
 
    else if ((route.substring(0,13)).equals("turnOffLedSet"))
    {
        String id = route.substring(13);
        Serial.println("Turn off single led set");
        Serial.println(id);
        digitalWrite(atoi(id.c_str()), LOW);
        body = "{\"status\": \"off\" }";
    }
    else if (route.equals("getLedPins"))
    {
        String id = route.substring(13, route.length() - 1);
        Serial.println("Get led pins");
        body = "[13,14,15]";
    }

    else
    {
        body = "{ \"status\": \"Invalid request\"}";
    }

    result.SetResult(body);

    return result;
}

String Router::ExtractAddressData(String request){
    Serial.println(request); 
    String addressRoutePart = request.substring(request.indexOf(" "), request.indexOf("HTTP"));

    addressRoutePart.replace("/", "");
    addressRoutePart.replace(" ", "");

    return addressRoutePart;
}