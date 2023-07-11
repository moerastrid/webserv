#include "webserv.hpp"

#include <iostream>

#include <cpplog.hpp>

CPPLog logger(CPPLog::INFO);

int main(void)
{
	logger.log(CPPLog::DEBUG, "Parsing config file...");
	logger.logInfo("Launching server...");
}
