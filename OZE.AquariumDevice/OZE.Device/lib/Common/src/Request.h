#pragma once
#include <WString.h>

class Request{
    public:
        String GetRequest();
        void SetRequest(String value);
    private:
        String request;
};