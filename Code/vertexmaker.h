

#pragma once

#include <vector>
#include <algorithm>

#include "fileToVector.h"
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "graph.h"
#include "edge.h"
using namespace std;
/**
 * class created for the vertexmaker
 */
class vertexmaker {
public:
  std::map<std::string, std::vector<std::string>> info;
  std::vector<pair<string,string>> route;
  map<string,bool> connected;
  std::map<std::string, std::string> name_to_ID;

  /*
  * In this function we created the graph, through read from file we first created all the nodes
  * in the second part of the function we inserted edge, by traverse through info, to see match source and destination ID
  * After finding the two nodes we insert edge between them, and by using the get distance function we update the edge weights
  * @param  filename1       airport dataset
  * @param  filename2       route dataset
  */
  vertexmaker(const std::string & filename1,const std::string & filename2);

  /*
   * Helper function，calculating the shortest path between the source and dest airports
   * @param   source    source airport's name
   * @param   dest      destination airport's name
   * @param   g         input graph
   * @return  shortestPath_(g_, source, dest)    g_is the graph created, the vertex include source, destination, and stop's airportname
   */
  std::pair<int, std::vector<Vertex> > shortestPath(Vertex source, Vertex dest);
  const Graph & getGraph() const;

  /*
  * This function will draw the route on the graph, from the helper funtion shortestPath_ above,
  * we found the the two airports, and get the latitude and longitude of those two airports,
  * convert it into scale and mark it with red dot.
  * @param    inputFile     base picture
  * @param    source        source name of the airport
  * @param    dest          destination name of the airport
  * @return   inputpicture  the final PNG created
  */
  cs225::PNG drawPNG(std::string inputFile, string source, string dest);

  /*
  * if path exist between the two airports
  * @param    source        source name of the airport
  * @param    dest          destination name of the airport
  * @return   bool          if path exist or not
  */
  bool ifPath(Vertex source, Vertex dest);

  class myComparator{
    public:
      int operator() (std::pair<Vertex, int> p1, std::pair<Vertex, int> p2){
            return p1.second > p2.second;
      }
  };

private:
  Graph g_;
  /*change latitude and longitude into scale that would fit the base pic
  * @param    a     latitude or longitude
  * @return   a     scaled
  */
  int latitude(int a);
  int longitude(int a);

  /*
   * Helper function，calculating the shortest path between the source and dest airports
   * @param   source    source airport's name
   * @param   dest      destination airport's name
   * @param   g         input graph
   * @return  pair<int,vertex>    int says the path length, the vertex include source, destination, and stop's airportname
   */
  std::pair<int, std::vector<Vertex> > shortestPath_(Graph g, Vertex source, Vertex dest);
};
