#include "fileToVector.h"
#include <fstream>

std::vector<std::tuple<std::string, std::string, std::string, std::string>> airport_file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::tuple<std::string, std::string, std::string>> ret;
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
            std::tuple<std::string, std::string, std::string, std::string> input = std::make_tuple(ID, name, latitude, longitude);
            ret.push_back(input);
        }
	}

	return ret;
}

std::map<std::string, std::vector<std::string>> route_file_to_map(const std::string & filename) {
	std::ifstream text(filename);
	std::map<std::string, std::vector<std::string>> ret;
    std::vector<std::pair<std::string, std::string>> input;
	std::string source;
	std::string destination;

	if (text.is_open()) {
		while (getline(text, word)) {
            std::vector<std::string> info = split(word, ",");
            source = info[3];
            destination = info[5];
            input.push_back(std::make_pair(source, destination));
        }
	}
    for(size_t i = 0; i < input.size() - 1; i++){
        std::vector<std::string> dests;
        dests.push_back(input[i].second);
        if(input[i].first != input[i + 1].first){
            ret[input[i].first] = dests;
            dests.clear();
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