#include "webserv.hpp"

void	errorMessage(std::string	str) {
	std::cerr << "\033[1;31m" << "Error - " << str << "\033[0m" << std::endl;
}

void	warningMessage(std::string	str) {
	std::cerr << "\033[1;33m" << "Warning - " << str << "\033[0m" << std::endl;
}
