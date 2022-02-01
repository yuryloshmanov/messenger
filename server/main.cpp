#include <iostream>
#include <zmqpp/zmqpp.hpp>


int main() {
    std::cout << "Hello, World!" << std::endl;
    zmqpp::context context;
    context.terminate();
    return 0;
}
