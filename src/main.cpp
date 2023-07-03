#include <unistd.h>

#include <iostream>

#include "Socket.hpp"

int main() {
    Socket socket(80);

    while (1) {
        if (!socket.pending())
            continue;
        std::cout << "Pending socket" << std::endl;
        int client_fd = socket.accept();
        std::cout << "Accepted connection" << std::endl;

        if (close(client_fd) < 0) {
            std::cerr << "Failed to close client socket" << std::endl;
            return 1;
        }
        std::cout << "Closed connection" << std::endl;
    }

    // optional
    socket.close();
    std::cout << "Closed socket" << std::endl;
    return 0;
}
