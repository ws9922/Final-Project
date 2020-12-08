

#pragma once

#include <vector>
#include <algorithm>

#include "fileToVector.h"
#include "graph.h"
#include "edge.h"

/**
 * Represents a algorithm to learn the game of Nim.
 */
class vertexmaker {
public:
  
  vertexmaker();
  void updateEdgeWeights(const std::vector<Edge> & path);

  const Graph & getGraph() const;

private:
  Graph g_;
  Vertex startingVertex_;
};
