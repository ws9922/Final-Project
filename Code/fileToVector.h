#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>


std::vector<std::vector<std::string> > airport_file_to_vector(const std::string & filename);
std::map<std::string, std::vector<std::string> > route_file_to_map(const std::string & filename);
std::vector<std::string> split(std::string str,std::string pattern);