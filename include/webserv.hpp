#pragma once

//#include <iostream>
#include <string>
//#include <map>
//#include <array>
#include "Config.hpp"

// function prototypes
int		parse(int argc, char **argv, Config &config);
void	errorMessage(std::string str);
