#include <iostream>

#include "hello-world.hpp"
#include "Config.hpp"

int main()
{
	std::cout << hello_world() << std::endl;
	try {
		parse(argc, argv, config);
		std::cout << "parse result : " << config << std::endl;
	}
	catch	(ConfigException::exception &e) {
		errorMessage(e.what());
		return (1);
	}
	return 0;
}
