#include <WString.h>

class Response {
    public:
        String Get();
    private:
};

String Response::Get(){
    return "<!DOCTYPE HTML><html><p>To jest customowa odpowiedz z serwera</p></html>";
}