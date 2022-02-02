#include <iostream>


class Server {
public:
    static Server get() {
        return instance;
    }

private:
    Server() = default;
    static Server instance;
};


int main() {

    return 0;
}
