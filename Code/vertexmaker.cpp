
#include "vertexmaker.h"
#include <ctime>

vertexmaker::vertexmaker() : g_(true, true) {

    std::vector<std::vector<std::string>> info = airport_file_to_vector(filename);
    std::map<std::string, std::vector<std::string>> map = route_file_to_map(filename);
    auto v = file_to_vector("airports.dat.txt");
    for(int i = 0; i < info.size()-1; i++) {
      Vertex vtx = get<1>(v[i]);
      g_.insertVertex(vtx);
    }
    for(int i = 0; i < info.size()-1; i++){// insertEdge if route exist
      string temp = x;
      while(!map.end()){
        if(info<0>[i] == map.front() && temp != map.front()){
          bool temp = g_.insertEdge(info<0>[i],map.front());
        }
        temp = map.front();
        map.pop();
      }
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
