#pragma once
#include <WString.h>
#include "Result.h"

class Router
{
    public:
        Result SelectAction(String route);
        String ExtractAddressData(String request);
}; 