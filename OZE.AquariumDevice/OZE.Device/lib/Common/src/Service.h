#pragma once
#include "Result.h"
#include "Request.h"

class Service{
    public:
        virtual Result Execute(Request request);
};