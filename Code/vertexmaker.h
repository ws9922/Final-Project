

#pragma once

#include <vector>
#include <algorithm>

#include "fileToVector.h"
#include "graph.h"
#include "edge.h"
using namespace std;
/**
 * Represents a algorithm to learn the game of Nim.
 */
class vertexmaker {
public:
  std::vector<std::vector<std::string>> info;
  std::vector<pair<string,string>> route;
  vertexmaker(const std::string & filename1,const std::string & filename2);
  std::pair<int, std::vector<Vertex> > shortestPath(Vertex source, Vertex dest);
  const Graph & getGraph() const;
  class myComparator{
    public:
      int operator() (std::pair<Vertex, int> p1, std::pair<Vertex, int> p2){
            return p1.second > p2.second;
      }
  }; 

private:
  Graph g_;
  std::pair<int, std::vector<Vertex> > shortestPath(Graph g, Vertex source, Vertex dest);
};
