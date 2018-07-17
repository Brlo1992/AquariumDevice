#include <SPI.h>
#include <Ethernet.h>
#include <WebServer.h>
#include <Common.h>

WebServer webServer;
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
//192.168.8.133
IPAddress ip(192, 168, 8, 133);
EthernetServer server = EthernetServer(80);
Common helper = Common();

void setup()
{
    helper.InitSerialPort();
    pinMode(4, OUTPUT); 
    pinMode(5, OUTPUT); 
    pinMode(6, OUTPUT); 
    webServer = WebServer(mac, ip, 80);
    server = webServer.Init();
}

void loop()
{
    webServer.Run(server);
}
