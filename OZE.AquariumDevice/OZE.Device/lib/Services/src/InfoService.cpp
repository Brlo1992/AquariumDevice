#include "InfoService.h"
#include "Result.h"
#include "Request.h"

Result Service::Execute(Request request){
    Result result = Result();

    result.SetResult("{ \"service\": \"InfoService\"}");

    return result;
}

