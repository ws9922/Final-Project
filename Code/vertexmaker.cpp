
#include "vertexmaker.h"
#include <ctime>

vertexmaker::vertexmaker(unsigned total_Airport) : g_(true, true) {
    /* Your code goes here! */
    for (unsigned int i = 0; i <= total_Airport; i++) {
      auto airportname = file_to_vector(i);
     Vertex vtx1 = "p1-" +std::get<0>(airportname);
     Vertex vtx2 = "p2-" +std::get<0>(airportname);;
     g_.insertVertex(vtx1);
     g_.insertVertex(vtx2);
   }
   for(unsigned int i=total_Airport;(int)i>=0;i--)
    {
      if((int)i-2>=0)
      {
        bool temp = g_.insertEdge("p1-"+std::to_string(i),"p2-"+std::to_string(i-2));
        g_.setEdgeWeight("p1-"+std::to_string(i),"p2-"+std::to_string(i-2),0);
        bool temp1 = g_.insertEdge("p2-"+std::to_string(i),"p1-"+std::to_string(i-2));
        g_.setEdgeWeight("p2-"+std::to_string(i),"p1-"+std::to_string(i-2),0);
      }
      if((int)i-1>=0)
      {
        bool temp2 = g_.insertEdge("p1-"+std::to_string(i),"p2-"+std::to_string(i-1));
        g_.setEdgeWeight("p1-"+std::to_string(i),"p2-"+std::to_string(i-1),0);
        bool temp3 = g_.insertEdge("p2-"+std::to_string(i),"p1-"+std::to_string(i-1));
        g_.setEdgeWeight("p2-"+std::to_string(i),"p1-"+std::to_string(i-1),0);
      }
    }
}
void vertexmaker::updateEdgeWeights(const std::vector<Edge> & path) {
 /* Your code goes here! */
 if (path[path.size()-1].dest == "p2-0") {
   for (size_t i = 0; i < path.size(); i++) {
     if(i%2 != 0) {
       g_.setEdgeWeight(path[i].source, path[i].dest, g_.getEdgeWeight(path[i].source, path[i].dest)-1);
     } else {
       g_.setEdgeWeight(path[i].source, path[i].dest, g_.getEdgeWeight(path[i].source, path[i].dest)+1);
     }
   }
 }
 if (path[path.size()-1].dest == "p1-0") {
   for (size_t i = 0; i < path.size(); i++) {
     if(i%2 == 0) {
       g_.setEdgeWeight(path[i].source, path[i].dest, g_.getEdgeWeight(path[i].source, path[i].dest)-1);
     } else {
       g_.setEdgeWeight(path[i].source, path[i].dest, g_.getEdgeWeight(path[i].source, path[i].dest)+1);
     }
   }
 }
}


/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & vertexmaker::getGraph() const {
  return g_;
}
