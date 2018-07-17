#pragma once
#include "ResponseFactory.h"
#include <Ethernet.h>
#include <WString.h>

void ResponseFactory::Handle(EthernetClient client, String responseContent)
{
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json;charset=utf-8");
    client.println("Connection: close"); // the connection will be closed after completion of the response
    client.println();
    client.println(responseContent);
}

// void ResponseFactory::GetNotFound(EthernetClient client)
// {
//     client.println("HTTP/1.1 404 NOT FOUND");
//     client.println("Content-Type: application/json;charset=utf-8");
//     client.println("Connection: close"); // the connection will be closed after completion of the response
// }