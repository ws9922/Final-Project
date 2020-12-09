
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

//using namespace std;

/*To make Vertex based on the information from the text*/
vertexmaker::vertexmaker(const std::string & filename1,const std::string & filename2): g_(true, true) {
  /*to get the full information from file*/
    this->info = airport_file_to_vector(filename1);
    this->route = route_file_to_pair(filename2);

  /* insert Vertex one by one*/
    for(int i = 0; i < (int)info.size(); i++) {
      string word = info[i][0];
      g_.insertVertex(word);
    }
    std::vector<int> index = IDToindex(filename1);
  //insert edge
    for (int i = 0; i < (int)route.size(); i++) {
       string source = route[i].first;
       string destination = route[i].second;
       int sourceid = atoi(source.c_str());
       int destid = atoi(destination.c_str());
       sourceid = index[sourceid];
       destid = index[destid];
       if(sourceid != 0 && destid != 0) {
          g_.insertEdge(info[sourceid - 1][1], info[destid - 1][1]);
          int source_latitude = atoi(info[sourceid - 1][2].c_str());
          int dest_latitude = atoi(info[destid - 1][2].c_str());
          int source_longitude = atoi(info[sourceid - 1][3].c_str());
          int dest_longitude = atoi(info[destid - 1][3].c_str());
          int distance = (int)GetDistance(source_latitude, source_longitude, dest_latitude, dest_longitude);
          g_.setEdgeWeight(info[sourceid - 1][1], info[destid - 1][1], distance);
   }
  }
}

/**
 * Helper function
 */
std::pair<int, std::vector<Vertex> > vertexmaker::shortestPath(Graph g, Vertex source, Vertex dest){
  int distances = 0;
  std::map<Vertex, Vertex> previous;
  priority_queue<std::pair<Vertex, int>, vector<std::pair<Vertex, int>>, myComparator> q;
  std::map<Vertex, int> node_to_dist;
  std::vector<Vertex> vertices = g.getVertices();
  for(Vertex & v : vertices){
    if(v != source){
      node_to_dist[v] = std::numeric_limits<double>::infinity();
    }else{
      node_to_dist[v] = 0;
    }
  }
  q.push(std::make_pair(source, 0));
  std::vector<Vertex> visited;
  while (q.top().first != dest){
    std::pair<Vertex, int> cur = q.top();
    std::vector<Vertex> neighbors = g.getAdjacent(cur.first);
    for(Vertex & v : neighbors){
      if(std::find(visited.begin(), visited.end(), v) == visited.end()){
        int cur_distance = node_to_dist[cur.first] + g.getEdgeWeight(cur.first, v);
        if(cur_distance < node_to_dist[v]){
          node_to_dist[v] = cur_distance;
          auto it = node_to_dist.find(v);
          q.push(*it);
          previous[v] = cur.first;
        }
      }
    }
    visited.push_back(cur.first);
  }
  distances = node_to_dist[dest];
  Vertex cur = dest;
  vector<Vertex> path;
  path.push_back(dest);
  while (previous[cur] != source){
    cur = previous[cur];
    path.push_back(cur);
  }
  std::reverse(path.begin(),path.end());
  return std::make_pair(distances, path);
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & vertexmaker::getGraph() const {
  return g_;
}
