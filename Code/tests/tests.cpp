#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../fileToVector.h"
#include "../GetDistance.h"
#include "../vertexmaker.h"
#include "../edge.h"
#include "../graph.h"


#include <iostream>

/*
first test case
2965
2990
first"Astrakhan Airport"
first46.2832984924
first48.0063018799
"Kazan International Airport"
55.606201171875
49.278701782227
---------
second test case
4029
2990
"Kazan International Airport"
55.606201171875
49.278701782227
first"Domodedovo International Airport"
first55.40879821777344
first37.90629959106445
515.851
*/



TEST_CASE("file to vector working properly", "[weight=1][part=1]") {
  auto info = airport_file_to_vector("airports.dat.txt");
  REQUIRE( info[99][0] == "100" );
}


TEST_CASE("GetDistance working properly with given altitude and longtitude(simple)", "[weight=1][part=1]") {
  double distance = GetDistance(0.0, 0.0, 0.0, 0.0);
  REQUIRE( distance == 0 );
}

TEST_CASE("GetDistance working properly with given altitude and longtitude(not simple)", "[weight=1][part=1]") {
  double distance = GetDistance(93.79216800, 118.73820100, 33.79214700, 259.50227700);
  REQUIRE( distance == 5934.0345 );
}


TEST_CASE("constructor creates the correct edges", "[weight=1][part=1]") {
  vertexmaker vertexmaker("airports.dat.txt","routes.dat.txt");

  const Graph& g = vertexmaker.getGraph();
  REQUIRE( g.edgeExists("Astrakhan Airport","Kazan International Airport"));
  REQUIRE( g.edgeExists("Domodedovo International Airport", "Kazan International Airport"));
}


// TEST_CASE("Testing simple backflow", "[valgrind][weight=1]") {
//   Graph g = Graph(true,true);

//   g.insertEdge("a","b");
//   g.setEdgeWeight("a","b",10);
//   g.insertEdge("a","c");
//   g.setEdgeWeight("a","c",10);
//   g.insertEdge("b","c");
//   g.setEdgeWeight("b","c",5);
//   g.insertEdge("b","d");
//   g.setEdgeWeight("b","d",15);
//   g.insertEdge("c","d");
//   g.setEdgeWeight("c","d",10);
//   vertexmaker vertexmaker("airports.dat.txt","routes.dat.txt");
//   pair<int,vector<Vertex>> p = vertexmaker.shortestpath(g, "a", "b");
//   int result = 20;
//   vector<Vertex> v;
//   v.push_back("a");
//   v.push_back("c");
//   v.push_back("d");
//   REQUIRE(result = p.fisrt);
//   REQUIRE(v = p.second);
// }

/*
first test case
2965
2990
first"Astrakhan Airport"
first46.2832984924
first48.0063018799
"Kazan International Airport"
55.606201171875
49.278701782227
---------
second test case
4029
2990
"Kazan International Airport"
55.606201171875
49.278701782227
first"Domodedovo International Airport"
first55.40879821777344
first37.90629959106445
515.851
*/

