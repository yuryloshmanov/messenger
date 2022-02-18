#include <iostream>

#include "include/console_client.hpp"


int main() {
    ConsoleClient consoleClient;

    consoleClient.connectToServer("tcp://192.168.1.5:4040");
    consoleClient.run();

    return 0;
}
