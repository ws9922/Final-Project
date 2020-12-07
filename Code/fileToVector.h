#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <tuple>
#include <map>


std::vector<std::tuple<std::string, std::string, std::string>> airport_file_to_vector(const std::string & filename);
std::map<std::tuple<std::string, std::string, std::string>> route_file_to_map(const std::string & filename);
std::vector<std::string> split(std::string str,std::string pattern);