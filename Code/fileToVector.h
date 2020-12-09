#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <cstdlib> 


std::vector<std::vector<std::string> > airport_file_to_vector(const std::string & filename);
std::vector<std::pair<std::string, std::string> > route_file_to_pair(const std::string & filename);
std::vector<std::string> split(std::string str,std::string pattern);
std::vector<int> IDToindex(const std::string & filename);