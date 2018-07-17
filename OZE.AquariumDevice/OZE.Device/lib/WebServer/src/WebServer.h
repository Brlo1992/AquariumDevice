#include <SPI.h>
#include <Ethernet.h>
#include "Common.h"
#include "ResponseFactory.h"
#include "Router.h"

class WebServer
{
  public:
    WebServer();
    WebServer(byte *mac, IPAddress ipAddress, int serverPort);
    void Run(EthernetServer server);
    EthernetServer Init();

  private:
    byte *mac;
    int serverPort;
    IPAddress ipAddress;
    Common common;
    ResponseFactory responseFactory;
    Router router;
};