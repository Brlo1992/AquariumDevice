#include <WString.h>
#include "Result.h"

String Result::GetResult()
{
    return this->result;
}

void Result::SetResult(String value)
{
    this->result = value;
}
