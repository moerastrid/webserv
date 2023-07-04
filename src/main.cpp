#include <unistd.h>

#include <iostream>

#include "Connection.hpp"
#include "Socket.hpp"

int main() {
    Socket socket(53433);

    while (1) {
        if (!socket.pending())
            continue;
        std::cout << "Pending socket" << std::endl;
        Connection connection = socket.accept();
        std::cout << "Accepted connection" << std::endl;

        std::cout << "Writing to connection" << std::endl;
        connection.write("Hello, world!\n");

        std::cout << "Reading from connection" << std::endl;
        std::string data = connection.read(1024);
        std::cout << data;
        if (*(data.end() - 1) != '\n') {
            std::cout << std::endl;
        }
        connection.close();
        std::cout << "Closed connection" << std::endl;
    }

    socket.close();
    std::cout << "Closed socket" << std::endl;
    return 0;
}
