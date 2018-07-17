#pragma once
#include <SPI.h>
#include <Common.h>

void Common::InitSerialPort()
{
    Serial.begin(9600);
    while (!Serial) { }
}

bool Common::IsCarrigeCharacter(char character)
{
    return character == '\n' ? true : false;
}

bool Common::IsNewLineCharacter(char character)
{
    return character == '\r' ? true : false;
}