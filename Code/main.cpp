
#include <vector>
#include "edge.h"
#include <iostream>
#include "fileToVector.h"
#include "GetDistance.h"
#include "vertexmaker.h"
#include <map>
#include "vertexmaker.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "fileToVector.h"
#include "graph.h"
#include "GetDistance.h"
#include <map>
#include <queue>
#include <limits>

using namespace std;



int main() {
  cout << "Welcome to our Find Shortest Path Between two Airports Program" << endl;
  cout << "First please put your dataset file into our Code folder" << endl;
  cout << "Let's start!" << endl;
  string airport_filename;
  cout << "Please input your Airports dataset file name: " ;
	cin >> airport_filename;
  string route_filename;
  cout << "Please input your Routes dataset file name: ";
  cin >> route_filename;
  vertexmaker myVertex = vertexmaker(airport_filename, route_filename);

  string mystr = "\n";
  getline(cin, mystr);

  string source_name;
  cout << "Please input your source airport's name: ";
  getline (cin, source_name);
  cout << "Your source airport is " << source_name << endl;
  
  string dest_name;
  cout << "Please input your destination airport's name: ";
  getline (cin, dest_name);
  cout << "Your destiname airport is " << dest_name << endl;

  bool pathExists = myVertex.ifPath(source_name, dest_name);
  if(pathExists){
    cout << "There is a path from " << source_name << " to " << dest_name << endl;
  } else{
    cout << "Sorry, there is no path from " << source_name << " to " << dest_name << endl;
    return 0;
  }

  auto shortestPath = myVertex.shortestPath(source_name, dest_name);
  int distance = shortestPath.first;
  vector<Vertex> path = shortestPath.second;
  cout<< "The shortest path's distance from " << source_name << " to " << dest_name << " is " << distance << endl;
  cout<< "The shortest path is ";
  for (Vertex & v : path){
    if(v == dest_name){
      cout<< v << endl;
      break;
    }
    cout<< v << " -> ";
  }
  
  cs225::PNG png = myVertex.drawPNG("worldmap.png", source_name , dest_name);

  cout<< "The graphic output of the shortest path is saved as out.png file" << endl;


  return 0;
}
