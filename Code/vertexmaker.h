

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
  vertexmaker(const std::string & filename);
  

  const Graph & getGraph() const;

private:
  Graph g_;
  Vertex startingVertex_;
};
