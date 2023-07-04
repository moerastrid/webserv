#pragma once

#include <string>

class Connection {
   public:
    Connection(int connection_fd);
    Connection(const Connection &other) = delete;
    ~Connection();

    void close();
    bool pending() const;
    std::string read();
    void write(const std::string &data);

    Connection &operator=(const Connection &other) = delete;

   private:
    int _connection_fd = -1;
};
