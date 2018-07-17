#pragma once
#include <WString.h>

class Result{
    public:
        String GetResult();
        void SetResult(String value);
    private:
        String result;
};