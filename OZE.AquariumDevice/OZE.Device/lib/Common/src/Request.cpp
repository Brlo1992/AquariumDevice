#include <WString.h>
#include "Request.h"

String Request::GetRequest()
{
    return this->request;
}

void Request::SetRequest(String value)
{
    this->request = value;
}
