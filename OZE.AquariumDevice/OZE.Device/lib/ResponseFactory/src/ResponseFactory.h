#pragma once
#include <SPI.h>
#include <Ethernet.h>
#include "Common.h"
#include <WString.h>

class ResponseFactory
{
  public:
    void Handle(EthernetClient client, String responseContent);
  private:
};