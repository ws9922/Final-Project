#include "../cs225/catch/catch.hpp"

#include "../fileToVector.h"
#include "../GetDistance.h"
#include "../vertexmaker.h"
#include "../edge.h"
#include "../graph.h"


#include <iostream>


TEST_CASE("file to vector working properly", "[weight=1][part=1]") {
  this->info = airport_file_to_vector("airports.dat.txt");
  string str = to_string(int i = 99);
  REQUIRE( info[99][0] == str );
}


TEST_CASE("GetDistance working properly with given altitude and longtitude(simple)", "[weight=1][part=1]") {
  double distance = GetDistance(0.0, 0.0, 0.0, 0.0);
  REQUIRE( distance == 0 );
}

TEST_CASE("GetDistance working properly with given altitude and longtitude(not simple)", "[weight=1][part=1]") {
  double distance = GetDistance(93.79216800, 118.73820100, 33.79214700, 259.50227700);
  REQUIRE( distance == 5934.03 );
}


TEST_CASE("constructor creates the correct edges", "[weight=1][part=1]") {
  vertexmaker vertexmaker("airports.dat.txt","routes.dat.txt");

  const Graph & g = vertexmaker.getGraph();
  REQUIRE( g.edgeExists("Astrakhan Airport", "Kazan International Airport"));
}

TEST_CASE("constructor creates the correct edges", "[weight=1][part=1]") {
  vertexmaker vertexmaker("airports.dat.txt","routes.dat.txt");

  const Graph & g = vertexmaker.getGraph();
  REQUIRE( g.edgeExists("Domodedovo International airport", "Kazan International Airport"));
}

/*
first test case
2966
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

TEST_CASE(" Updates the edge weight correctly", "[weight=1][part=3]") {
  vertexmaker vertexmaker("airports.dat.txt","routes.dat.txt");

  const Graph & g = vertexmaker.getGraph();
  REQUIRE( g.getEdgeWeight("Astrakhan Airport", "Kazan International Airport") == 716.451);
}

TEST_CASE(" Updates the edge weight correctly", "[weight=1][part=3]") {
  vertexmaker vertexmaker("airports.dat.txt","routes.dat.txt");

  const Graph & g = vertexmaker.getGraph();
  REQUIRE( g.getEdgeWeight("Domodedovo International Airpor", "Kazan International Airport") == 1041.6);
}
