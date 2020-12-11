
#include "vertexmaker.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "fileToVector.h"
#include "graph.h"
#include <cmath>
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "GetDistance.h"
#include <map>
#include <queue>
#include <limits>
using namespace cs225;
using namespace std;

/*
* In this function we created the graph, through read from file we first created all the nodes
* in the second part of the function we inserted edge, by traverse through info, to see match source and destination ID
* After finding the two nodes we insert edge between them, and by using the get distance function we update the edge weights
* @param filename1       airport dataset
* @param filename2       route dataset
*/
/*To make Vertex based on the information from the text*/
vertexmaker::vertexmaker(const std::string & filename1,const std::string & filename2): g_(true, true) {
  /*to get the full information from file*/
    this->info = airport_file_to_vector(filename1);
    this->route = route_file_to_pair(filename2);
    this->name_to_ID = name_map_to_ID(filename1);

  /* insert Vertex one by one*/
    for(std::pair<std::string, std::vector<std::string>> airport : info) {
      string name = airport.second[0];
      connected[name] = false;
      g_.insertVertex(name);
    }
  //insert edge
    for (int i = 0; i < (int)route.size(); i++) {
      string sourceID = route[i].first;
      string destinationID = route[i].second;
      if(info.find(sourceID) != info.end() && info.find(destinationID) != info.end()){
        g_.insertEdge(info[sourceID][0], info[destinationID][0]);
        double source_latitude = atof(info[sourceID][1].c_str());
        double dest_latitude = atof(info[destinationID][1].c_str());
        double source_longitude = atof(info[sourceID][2].c_str());
        double dest_longitude = atof(info[destinationID][2].c_str());
        int distance = (int)GetDistance(source_latitude, source_longitude, dest_latitude, dest_longitude);
        g_.setEdgeWeight(info[sourceID][0], info[destinationID][0], distance);
      }
   }
}
/*
 * Helper function，calculating the shortest path between the source and dest airports
 * @param   source    source airport's name
 * @param   dest      destination airport's name
 * @param   g         input graph
 * @return  shortestPath_(g_, source, dest)    g_is the graph created, the vertex include source, destination, and stop's airportname
 */
std::pair<int, std::vector<Vertex> > vertexmaker::shortestPath(Vertex source, Vertex dest){
  return shortestPath_(g_, source, dest);
}

/*
 * Helper function，calculating the shortest path between the source and dest airports
 * @param   source    source airport's name
 * @param   dest      destination airport's name
 * @param   g         input graph
 * @return  pair<int,vertex>    int says the path length, the vertex include source, destination, and stop's airportname
 */
std::pair<int, std::vector<Vertex> > vertexmaker::shortestPath_(Graph g, Vertex source, Vertex dest){
  if(!ifPath(source, dest)){
    std::vector<Vertex> empty;
    empty.clear();
    return make_pair(0, empty);
  }
  int distances = 0;
  std::map<Vertex, Vertex> previous;
  priority_queue<std::pair<Vertex, int>, vector<std::pair<Vertex, int>>, vertexmaker::myComparator> q;
  std::map<Vertex, int> node_to_dist;
  std::vector<Vertex> vertices = g.getVertices();
  for(Vertex & v : vertices){
    if(v != source){
      node_to_dist[v] = std::numeric_limits<int>::max();
    }else{
      node_to_dist[v] = 0;
    }
  }
  q.push(std::make_pair(source, 0));
  std::vector<Vertex> visited;
  while (q.top().first != dest){
    std::pair<Vertex, int> cur = q.top();
    q.pop();
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
   if(path.back() != source){
    path.push_back(source);
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

/*
* This function will draw the route on the graph, from the helper funtion shortestPath_ above,
* we found the the two airports, and get the latitude and longitude of those two airports,
* convert it into scale and mark it with red dot.
* @param    inputFile     base picture
* @param    source        source name of the airport
* @param    dest          destination name of the airport
* @return   inputpicture  the final PNG created
*/
PNG vertexmaker::drawPNG(std::string inputFile, Vertex source, Vertex dest) {
    cs225::PNG inputpicture;
    inputpicture.readFromFile(inputFile);
    HSLAPixel redPixel(0, 1, 0.5, 1);
    HSLAPixel blackPixel(0, 0.5, 300, 1);
    auto v = shortestPath(source, dest);
    for(int i = 0; i < (int)v.second.size() - 1; i++) {
         Vertex first = v.second[i];
         Vertex second = v.second[i + 1];
         string firstid = name_to_ID[first];
         string secondid = name_to_ID[second];
         int firstLatitude = (int)(atof(info[firstid][1].c_str()));
         int firstLongitude = (int)(atof(info[firstid][2].c_str()));
         int secondLatitude = (int)(atof(info[secondid][1].c_str()));
         int secondLongitude = (int)(atof(info[secondid][2].c_str()));
         firstLatitude = latitude(firstLatitude);
         secondLatitude = latitude(secondLatitude);
         firstLongitude = longitude(firstLongitude);
         secondLongitude = longitude(secondLongitude);
         for(int i = firstLatitude - 5; i < firstLatitude + 5; i++) {
           for(int j = firstLongitude - 5; j < firstLongitude + 5; j++) {
           inputpicture.getPixel(j, i) = redPixel;
         }
         }
         for(int i = secondLatitude - 5; i < secondLatitude+ 5; i++) {
           for(int j = secondLongitude - 5; j < secondLongitude + 5; j++) {
           inputpicture.getPixel(j, i) = redPixel;
         }
         }

         int latitudesmall = min(firstLatitude,secondLatitude);
         int longitudesmall = min(secondLongitude, firstLongitude);
         int latitudebig = max(firstLatitude, secondLatitude);
         int longitudebig = max(secondLongitude, firstLongitude);
         if (latitudesmall == firstLatitude) {
         for(int i = latitudesmall; i < latitudebig; i++) {
           for(int j = firstLongitude; j < firstLongitude + 5; j++) {
           inputpicture.getPixel(j, i)= blackPixel;
           }
         }
         for(int i = longitudesmall; i < longitudebig; i++) {
           for (int j = secondLatitude; j < secondLatitude + 5; j++) {
           inputpicture.getPixel(i, j)= blackPixel;
           }
         }
         } else {
           for(int i = latitudesmall; i < latitudebig; i++) {
           for(int j = secondLongitude; j < secondLongitude +  5; j++) {
           inputpicture.getPixel(j, i)= blackPixel;

           }
           }
           for(int i = longitudesmall; i < longitudebig; i++) {
           for (int j = firstLatitude; j < firstLatitude + 5; j++) {
           inputpicture.getPixel(i, j)= blackPixel;
           }
         }
         }

    }
    inputpicture.writeToFile("out.png");
    return inputpicture;
}

/*change latitude and longitude into scale that would fit the base pic
* @param    a     latitude ro longitude
* @return   a     scaled
*/
int vertexmaker::latitude(int a) {
  if (a < 0) {
     a = (90 - a) * 10;
  } else {
     a = (90 - a) * 10;
  }
  return a;
}
int vertexmaker::longitude(int a) {
  if (a < 0) {
    a  = (180 + a) * 8.5;
  } else {
    a = (180 + a) * 9.7;
  }
  return a;
}

/*
* if path exist between the two airports
* @param    source        source name of the airport
* @param    dest          destination name of the airport
* @return   bool          if path exist or not
*/
bool vertexmaker::ifPath(Vertex source, Vertex dest) {
  queue<Vertex> q;
  for(std::pair<std::string, std::vector<std::string>> airport : info) {
      string name = airport.second[0];
      connected[name] = false;
    }
  q.push(source);
  connected[source] = true;
  while(!q.empty()) {
    Vertex v = q.front();
    if(dest == v) {return true;}
    q.pop();
    for(Vertex ele: g_.getAdjacent(v)) {
        connected[v] = true;
        if(connected[ele] == false) {
          q.push(ele);
        }
    }
  }
  return false;
}
