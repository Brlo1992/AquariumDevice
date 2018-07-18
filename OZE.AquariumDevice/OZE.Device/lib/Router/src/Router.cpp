#include "Router.h"
#include "WString.h"
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
    }
    else if (route.equals("turnOff"))
    {
        Serial.println("Turn off leds");
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
    }
    else if ((route.substr(0,11)).equals("turnOnLedSet"))
    {
        String id = route.substr(12, route.length() - 1)
        Serial.println("Turn on single led set");
        digitalWrite(atoi(id.c_str());, HIGH);
    }

    else if ((route.substr(0,12)).equals("turnOffLedSet"))
    {
        String id = route.substr(13, route.length() - 1)
        Serial.println("Turn off single led set");
        digitalWrite(atoi(id.c_str(), LOW);
    }
    else if (route.equals("getLedPins"))
    {
        String id = route.substr(13, route.length() - 1)
        Serial.println("Get led pins");
        body = "[13,14,15]";
    }

    else
    {
        body = "{ \"status\": \"Invalid request\"}";
    }

    return service.Execute(request);
}

String Router::ExtractAddressData(String request){
    String addressRoutePart = request.substring(request.indexOf(" "), request.indexOf("HTTP"));

    addressRoutePart.replace("/", "");
    addressRoutePart.replace(" ", "");

    return addressRoutePart;
}