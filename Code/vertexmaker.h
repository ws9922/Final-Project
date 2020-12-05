

#pragma once

#include <vector>
#include <algorithm>

#include "fileToString.h"
#include "graph.h"
#include "edge.h"

/**
 * Represents a algorithm to learn the game of Nim.
 */
class vertexmaker {
public:
  int total_Airport = fileToVector.size();
  vertexmaker(unsigned total_Airport);
  void updateEdgeWeights(const std::vector<Edge> & path);

  const Graph & getGraph() const;

private:
  Graph g_;
  Vertex startingVertex_;
};
