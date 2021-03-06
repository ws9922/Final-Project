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

/*
* this is a function that will read from file and
* store the airport ID, name, it's longitude and altitude in the vector
* @param    filename  file containing above information
*/
std::map<std::string, std::vector<std::string> > airport_file_to_vector(const std::string & filename);

/*
* this is a function that will read from file and
* store the two airports' ID in the same place, which will represent
* the source and destination Airport's ID
* @param    filename  file containing above information
*/
std::vector<std::pair<std::string, std::string> > route_file_to_pair(const std::string & filename);

/*
* this is a helper function,
* which will let us read from file and take out the things between two comma
* and put it in a vector in order.
* @param    str       one line of text in the file
* @return   pattern   split base on what
*/
std::vector<std::string> split(std::string str,std::string pattern);

/*
This is a function that only read the name and the ID
@param    filename  file containing the abpve information
@return   Airport's ID when name is given
*/
std::map<std::string, std::string> name_map_to_ID(const std::string & filename);
