#include "Socket.hpp"

#include <netinet/in.h>
#include <poll.h>
#include <sys/socket.h>
#include <unistd.h>

#include <stdexcept>

Socket::Socket(int port, int backlog) {
    _socket();
    _bind(port);
    _listen(backlog);
}

Socket::~Socket() {
    if (_socket_fd >= 0) {
        ::close(_socket_fd);
    }
}

Connection Socket::accept() {
    int client_fd = ::accept(_socket_fd, NULL, NULL);
    if (client_fd < 0) {
        throw std::runtime_error("Failed to accept connection");
    }
    return client_fd;
}

bool Socket::pending() const {
    static const int fd_count = 1;
    struct pollfd fds[fd_count];

    fds[0].fd = _socket_fd;
    fds[0].events = POLLIN;

    return (poll(fds, fd_count, 0) > 0);
}

void Socket::_socket() {
    _socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (_socket_fd < 0) {
        throw std::runtime_error("Failed to create socket");
    }
}

void Socket::_bind(int port) {
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(_socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        throw std::runtime_error("Failed to bind socket");
    }
}

void Socket::_listen(int backlog) {
    if (listen(_socket_fd, backlog) < 0) {
        throw std::runtime_error("Failed to listen on socket");
    }
}

void Socket::close() {
    if (_socket_fd < 0) {
        return;
    }
    if (::close(_socket_fd) < 0) {
        throw std::runtime_error("Failed to close file descriptor");
    }
    _socket_fd = -1;
}
