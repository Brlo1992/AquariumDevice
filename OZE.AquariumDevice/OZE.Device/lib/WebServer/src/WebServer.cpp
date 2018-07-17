#include <WebServer.h>
#include <ResponseFactory.h>
#include "Result.h"

EthernetServer WebServer::Init()
{
    Serial.println("Configure Web Server");
    auto server = EthernetServer(this->serverPort);
    Ethernet.begin(mac, ipAddress);
    server.begin();

    Serial.print("Web Server is at ");
    Serial.println(Ethernet.localIP());

    Serial.println("Run Web Server");
    return server;
}

void WebServer::Run(EthernetServer server)
{
    auto client = server.available();

    if (client)
    {
        while (client.connected())
        {
            if (client.available())
            {
                String request = client.readString();
                
                String route = router.ExtractAddressData(request);

                Result result = router.SelectAction(route);

                Serial.println(result.GetResult());

                responseFactory.Handle(client, result.GetResult());
                
                break;
            }
        }

        delay(10);

        client.stop();

        Serial.println("client disconnected");
    }
}

WebServer::WebServer()
{
    Serial.println("Creating Web Server");
}

WebServer::WebServer(byte *mac, IPAddress ipAddress, int serverPort)
{
    Serial.println("Creating Web Server");
    Serial.println("Assign values to variables");

    this->mac = mac;
    this->ipAddress = ipAddress;
    this->serverPort = serverPort;
    this->responseFactory = ResponseFactory();
    this->common = Common();
    this->router = Router();
} 