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
@return   Airport's ID
*/
std::map<std::string, std::string> name_map_to_ID(const std::string & filename) {//create a map that have the airports' name and ID
    std::ifstream text(filename);//set up
    std::map<std::string, std::string> ret;
    std::string word;
    std::string name;
    std::string ID;

    if (text.is_open()) {//read from file
		while (getline(text, word)) {
            std::vector<std::string> info = split(word, ",");//split by ","
            ID = info[0];//ID is the first object in fil
            name = info[1];//name is the second object in file
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
* @param    filename  file containing the abpve information
*/
std::map<std::string, std::vector<std::string>> airport_file_to_vector(const std::string & filename) {//create a vector that have the ID, airports' name and it's longitude and altitude
	std::ifstream text(filename);//set up
	std::map<std::string, std::vector<std::string>> ret;
	std::string word;
	std::string name;
    std::string ID;
	std::string latitude;
	std::string longitude;

	if (text.is_open()) {
		while (getline(text, word)) {//loop through the file
            std::vector<std::string> info = split(word, ",");//split by ","
            ID = info[0];//0th object in file
            name = info[1];//1st
            int a = name.length();
            name = info[1].substr(1,a - 2);
            latitude = info[6];//6th
			longitude = info[7];//7th
            std::vector<std::string> input;//push what we need into the vector
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
* @param    filename  file containing the abpve information
*/
std::vector<std::pair<std::string, std::string>> route_file_to_pair(const std::string & filename) {//create a vector that have the source and destination ID
	std::ifstream text(filename);//set up
	std::vector<std::pair<std::string, std::string>> ret;
    std::string word;
	std::string source;
	std::string destination;

	if (text.is_open()) {
		while (getline(text, word)) {//loop through the file
            std::vector<std::string> info = split(word, ",");//split by ",", look for airport ID
            source = info[3];//3th object in file
            destination = info[5];//5th object in filr
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
	std::ifstream text(filename);//set up
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

// std::vector<int> IDToindex(const std::string & filename) {
//     std::ifstream text(filename);
//     std::vector<int> v;
// 	std::string word;
//     std::string ID;

//     int counter = 0;
//     v.resize(14110);
//     for(int i = 0; i < 14111; i++) {
//         v[i] = 0;
//     }
// 	if (text.is_open()) {
// 		while (getline(text, word)) {
//             std::vector<std::string> info = split(word, ",");
//             counter++;
//             int a = atoi(info[0].c_str());
//             v[a] = counter;
//         }
// 	}

// 	return v;
// }
