#include "webserv.hpp"

void	errorMessage(std::string	str) {
	std::cerr << "\033[1;31m" << "Error - " << str << "\033[0m" << std::endl;
}
