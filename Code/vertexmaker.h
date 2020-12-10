

#pragma once

#include <vector>
#include <algorithm>

#include "fileToVector.h"
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "graph.h"
#include "edge.h"
using namespace std;
/**
 * Represents a algorithm to learn the game of Nim.
 */
class vertexmaker {
public:
  std::map<std::string, std::vector<std::string>> info;
  std::vector<pair<string,string>> route;
  map<string,bool> verify;
  map<string,bool> connected;
  std::vector<int> index;
  std::map<std::string, std::string> name_to_ID;
  

  vertexmaker(const std::string & filename1,const std::string & filename2);
  std::pair<int, std::vector<Vertex> > shortestPath(Vertex source, Vertex dest);
  const Graph & getGraph() const;

  cs225::PNG drawPNG(std::string inputFile, string sourceID, string destID);
  bool ifPath(Vertex source, Vertex dest);
  
  class myComparator{
    public:
      int operator() (std::pair<Vertex, int> p1, std::pair<Vertex, int> p2){
            return p1.second > p2.second;
      }
  }; 

private:
  Graph g_;
  int latitude(int a);
  int longitude(int a);
  std::pair<int, std::vector<Vertex> > shortestPath_(Graph g, Vertex source, Vertex dest);
};
