#include <iostream>
#include <stdlib.h>
#include <alerror/alerror.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <alproxies/altexttospeechproxy.h>
#include "NaoConnection.h"

int main(){
    std::cout << "Hello world" << std::endl;
    NaoConnection* testInstance = (NaoConnection*) malloc(sizeof(NaoConnection));
    testInstance->testDefinition();
    return 0;
}