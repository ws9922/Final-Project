
#include "vertexmaker.h"
#include <ctime>

vertexmaker::vertexmaker() : g_(true, true) {
    /* Your code goes here! */
    std::vector<std::tuple<std::string, std::string, std::string>> info = file_to_vector(filename);
    for(int i = 0; i < info.size(); i++) {
      g_.insertVertex(v[i]);
    }
}
void vertexmaker::updateEdgeWeights(const std::vector<Edge> & path) {
   
}


/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & vertexmaker::getGraph() const {
  return g_;
}
