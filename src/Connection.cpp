#include "Connection.hpp"

#include <unistd.h>

#include <stdexcept>

Connection::Connection() : FileDescriptor() {}

Connection::Connection(int connection_fd) : FileDescriptor(connection_fd) {}

Connection::~Connection() {}

// TODO Implement stream
std::string Connection::read(std::size_t length) {
    char buffer[length];
    ssize_t bytes_read = ::read(this->getFD(), buffer, sizeof(buffer));
    if (bytes_read < 0) {
        throw std::runtime_error("Failed to read from connection");
    }
    return std::string(buffer, bytes_read);
}

void Connection::write(const std::string &data) {
    if (::write(this->getFD(), data.c_str(), data.size()) < 0) {
        throw std::runtime_error("Failed to write to connection");
    }
}
