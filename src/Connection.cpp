#include "Connection.hpp"

#include <unistd.h>

#include <stdexcept>

#include <iostream>

Connection::Connection(int connection_fd) : _connection_fd(connection_fd) {
	
	std::cout << "Connection constructor with connection_fd: " << connection_fd << std::endl;
	if (_connection_fd < 0) {
		throw std::runtime_error("Invalid connection fd");
	}
}

Connection::~Connection() {
	std::cout << "Connection destructor with connection_fd: " << _connection_fd << std::endl;
	if (_connection_fd < 0)
		return;
	::close(_connection_fd);
}

void Connection::close() {
	std::cout << "Connection close with connection_fd: " << _connection_fd << std::endl;
	if (_connection_fd < 0) {
		return;
	}
	if (::close(_connection_fd) < 0) {
		throw std::runtime_error("Failed to close connection");
	}
	_connection_fd = -1;
}

void Connection::write(const std::string &data) {
	std::cout << "Connection write with connection_fd: " << _connection_fd << std::endl;
	if (_connection_fd < 0) {
		throw std::runtime_error("Invalid connection fd");
	}
	if (::write(_connection_fd, data.c_str(), data.size()) < 0) {
		throw std::runtime_error("Failed to write to connection");
	}
}
