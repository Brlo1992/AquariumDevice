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
        body = "{ \"alive\": \"true\"}";
        Serial.println("Turn on leds");
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
    }
    else if (route.equals("turnOff"))
    {
        body = "{ \"data\": {\"setInterval\": \"5000\", \"logErrors\": \"true\"}}";
        Serial.println("Turn off leds");
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
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