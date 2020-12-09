
#include "vertexmaker.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "fileToVector.h"
#include "graph.h"
#include "GetDistance.h"

using namespace std;

/*To make Vertex based on the information from the text*/
vertexmaker::vertexmaker(const std::string & filename1,const std::string & filename2): g_(true, true) {
  /*to get the full information from file*/
    this->info = airport_file_to_vector(filename1);
    this->route = route_file_to_pair(filename2);

  /* insert Vertex one by one*/
    for(int i = 0; i < (int)info.size(); i++) {
      string word = info[i][1];
      g_.insertVertex(word);
    }
  //insert edge
    for (int i = 0; i < (int)route.size(); i++) {
       string source = route[i].first;
       string destination = route[i].second;
       int sourceid = stoi(source);
       int destid = stoi(destination);
       if (!g_.edgeExists(info[sourceid - 1][1], info[destid - 1][1])) {
          g_.insertEdge(info[sourceid - 1][1], info[destid - 1][1]);
          int source_latitude = stoi(info[sourceid - 1][2]);
          int dest_latitude = stoi(info[destid - 1][2]);
          int source_longitude = stoi(info[sourceid - 1][3]);
          int dest_longitude = stoi(info[destid - 1][3]);
          int distance = GetDistance(source_latitude, source_longitude, dest_latitude, dest_longitude);
          g_.setEdgeWeight(info[sourceid - 1][1], info[destid - 1][1], distance);
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
