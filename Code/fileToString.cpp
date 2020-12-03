#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <tuple>

std::vector<std::tuple<std::string, std::string, std::string>> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::tuple<std::string, std::string, std::string>> ret;
	std::string word;
	std::string name;
	std::string latitude;
	std::string longitude;

	if (text.is_open()) {
		while (getline(text, word)) {
            std::vector<std::string> info = split(word, ",");
            name = info[1];
            latitude = info[6];
			longitude = info[7];
            std::tuple<std::string, std::string, std::string> input = std::make_tuple(name, latitude, longitude);
            ret.push_back(input);
        }
	}

	return ret;
}

std::vector<std::string> split(std::string str,std::string pattern) {
     std::string::size_type pos;
     std::vector<std::string> result;
     str+=pattern;
     int size=str.size();
 
     for(int i=0; i<size; i++)
     {
         pos=str.find(pattern,i);
         if(pos<size){
             std::string s=str.substr(i,pos-i);
             result.push_back(s);
             i=pos+pattern.size()-1;
         }
     }
     return result;
}