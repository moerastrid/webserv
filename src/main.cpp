#include <unistd.h>

#include <iostream>

#include "Socket.hpp"
#include "Connection.hpp"

int main() {
    Socket socket(53433);

    while (1) {
        if (!socket.pending())
            continue;
        std::cout << "Pending socket" << std::endl;
        Connection connection = socket.accept();
        std::cout << "Accepted connection" << std::endl;

        connection.write("Hello, world!\n");

        connection.close();
        std::cout << "Closed connection" << std::endl;
    }

    // optional
    socket.close();
    std::cout << "Closed socket" << std::endl;
    return 0;
}
