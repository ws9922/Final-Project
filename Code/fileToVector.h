#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib> 


std::map<std::string, std::vector<std::string> > airport_file_to_vector(const std::string & filename);
std::vector<std::pair<std::string, std::string> > route_file_to_pair(const std::string & filename);
std::vector<std::string> split(std::string str,std::string pattern);
std::map<std::string, std::string> name_map_to_ID(const std::string & filename);