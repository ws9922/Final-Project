#include "fileToVector.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>

/*
This is a function that only read the name and the ID
@param    filename  file containing the abpve information
@return   the map outputs Airport's ID when name is given
*/
std::map<std::string, std::string> name_map_to_ID(const std::string & filename) {
    std::ifstream text(filename);
    std::map<std::string, std::string> ret;
    std::string word;
    std::string name;
    std::string ID;

    if (text.is_open()) {
		while (getline(text, word)) {
            std::vector<std::string> info = split(word, ",");
            ID = info[0];
            name = info[1];
            int a = name.length();
            name = info[1].substr(1,a - 2);
            ret[name] = ID;
        }
	}

	return ret;
}
/*
* this is a function that will read from file and
* store the airport ID, name, it's longitude and altitude in the vector
* @param    filename  file containing above information
*/
std::map<std::string, std::vector<std::string>> airport_file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::map<std::string, std::vector<std::string>> ret;
	std::string word;
	std::string name;
    std::string ID;
	std::string latitude;
	std::string longitude;

	if (text.is_open()) {
		while (getline(text, word)) {
            std::vector<std::string> info = split(word, ",");
            ID = info[0];
            name = info[1];
            int a = name.length();
            name = info[1].substr(1,a - 2);
            latitude = info[6];
			longitude = info[7];
            std::vector<std::string> input;
            input.push_back(name);
            input.push_back(latitude);
            input.push_back(longitude);
            ret[ID] = input;
        }
	}

	return ret;
}
/*
* this is a function that will read from file and
* store the two airports' ID in the same place, which will represent
* the source and destination Airport's ID
* @param    filename  file containing above information
*/
std::vector<std::pair<std::string, std::string>> route_file_to_pair(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::pair<std::string, std::string>> ret;
    std::string word;
	std::string source;
	std::string destination;

	if (text.is_open()) {
		while (getline(text, word)) {
            std::vector<std::string> info = split(word, ",");
            source = info[3];
            destination = info[5];
            ret.push_back(std::make_pair(source, destination));
        }
	}
	return ret;
}
/*
* this is a helper function,
* which will let us read from file and take out the things between two comma
* and put it in a vector in order.
* @param    str       one line of text in the file
* @return   pattern   split base on what
*/
std::vector<std::string> split(std::string str,std::string pattern) {
     std::string::size_type pos;
     std::vector<std::string> result;
     str+=pattern;
     int size=str.size();

     for(int i=0; i<size; i++)
     {
         pos=str.find(pattern,i);
         if((int)pos<size){
             std::string s=str.substr(i,pos-i);
             result.push_back(s);
             i=pos+pattern.size()-1;
         }
     }
     return result;
}
