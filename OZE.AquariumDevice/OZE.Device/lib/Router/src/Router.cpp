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

    int pingOne = 4;
    int pingTwo = 5;
    int pingThree = 6;

    if (route.equals(""))
    {
        service = InfoService();
    }
    else if (route.equals("turnOn"))
    {
        Serial.println("Turn on leds");
        digitalWrite(pingOne, HIGH);
        digitalWrite(pingTwo, HIGH);
        digitalWrite(pingThree, HIGH);
        body = "{\"status\": \"on\" }";
    }
    else if (route.equals("turnOff"))
    {
        Serial.println("Turn off leds");
        digitalWrite(pingOne, LOW);
        digitalWrite(pingTwo, LOW);
        digitalWrite(pingThree, LOW);
        body = "{\"status\": \"off\" }";
    }
    else if ((route.substring(0,12)).equals("turnOnLedSet"))
    {
        String id = route.substring(12);
        Serial.println("Turn on single led set");
        Serial.println(id);
        digitalWrite(atoi(id.c_str()), HIGH);
        body = "{\"status\": \"on\",  \"id\" :\"" + id "\" }";
    }
 
    else if ((route.substring(0,13)).equals("turnOffLedSet"))
    {
        String id = route.substring(13);
        Serial.println("Turn off single led set");
        Serial.println(id);
        digitalWrite(atoi(id.c_str()), LOW);
        body = "{\"status\": \"off\",  \"id\" :\"" + id "\" }";
    }
    else if (route.equals("getLedPins"))
    {
        String id = route.substring(13, route.length() - 1);
        Serial.println("Get led pins");
        body = "[4,5,6]";
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