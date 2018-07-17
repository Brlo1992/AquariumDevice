#pragma once
#include "Service.h"
#include "Result.h"
#include "Request.h"

Result Service::Execute(Request request){
    Result actionResult = Result();
    actionResult.SetResult("To jest testowy rezultat");

    return actionResult;
}