#pragma once

#include <string>

#include "FileDescriptor.hpp"

class Connection : public FileDescriptor {
   public:
    Connection();
    Connection(int connection_fd);
    Connection(const Connection &other) = delete;
    ~Connection();

    bool pending() const;
    std::string read(std::size_t length);
    void write(const std::string &data);

    Connection &operator=(const Connection &other) = delete;
};
