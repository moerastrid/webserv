#ifndef PARSE_HEADERS_HPP
#define PARSE_HEADERS_HPP

#include <string>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <iostream>

std::unordered_map<std::string, std::string> parse_headers(const std::string message);

#endif