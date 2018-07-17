#pragma once

class Common
{
  public:
    void InitSerialPort();
    bool IsCarrigeCharacter(char character);
    bool IsNewLineCharacter(char character);
};