#include "fileToVector.h"
#include <fstream>

std::vector<std::vector<std::string>> airport_file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::vector<std::string>> ret;
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
            latitude = info[6];
			longitude = info[7];
            std::vector<std::string> input;
            input.push_back(ID);
            input.push_back(name);
            input.push_back(latitude);
            input.push_back(longitude);
            ret.push_back(input);
        }
	}

	return ret;
}

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