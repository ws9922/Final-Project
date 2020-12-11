#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../fileToVector.h"
#include "../GetDistance.h"
#include "../vertexmaker.h"
#include "../edge.h"
#include "../graph.h"


#include <iostream>





TEST_CASE("file to vector working properly", "[weight=1][part=1]") {
  auto info = airport_file_to_vector("airports.dat.txt");
  REQUIRE( info["1"][0] == "Goroka Airport" );
  REQUIRE( info["3364"][0] == "Beijing Capital International Airport");
  REQUIRE(info["3364"][1] == "40.080101013183594");
  REQUIRE( info["3364"][2] == "116.58499908447266");
  REQUIRE( info["3370"][0] == "Guangzhou Baiyun International Airport");
  REQUIRE(info["3370"][1] == "23.39240074157715");
  REQUIRE( info["3370"][2] == "113.29900360107422");

  auto name_to_ID = name_map_to_ID("airports.dat.txt");
  REQUIRE( name_to_ID["Goroka Airport"] == "1" );
  REQUIRE( name_to_ID["Beijing Capital International Airport"] == "3364");
  REQUIRE( name_to_ID["Guangzhou Baiyun International Airport"] == "3370");


}


TEST_CASE("GetDistance working properly with given altitude and longtitude(simple)", "[weight=1][part=1]") {
  double distance = GetDistance(0.0, 0.0, 0.0, 0.0);
  REQUIRE( distance == 0 );
}

TEST_CASE("GetDistance working properly with given altitude and longtitude(not simple)", "[weight=1][part=1]") {
  double distance = GetDistance(93.79216800, 118.73820100, 33.79214700, 259.50227700);
  REQUIRE( distance == 5934.0345 );
}

TEST_CASE("Set edge weight working properly with given altitude and longtitude(not simple)", "[weight=1][part=1]") {
  double distance = (int)GetDistance(40.080101013183594, 116.58499908447266, 23.39240074157715, 113.29900360107422);
  vertexmaker myVertex("airports.dat.txt","routes.dat.txt");
  const Graph & g = myVertex.getGraph();
  REQUIRE( g.getEdgeWeight("Beijing Capital International Airport", "Guangzhou Baiyun International Airport") == distance);
  REQUIRE( g.edgeExists("Beijing Capital International Airport", "Guangzhou Baiyun International Airport") == true);
  REQUIRE( g.getEdgeWeight("Beijing Capital International Airport", "Guangzhou Baiyun International Airport") == distance);
}


TEST_CASE("constructor creates the correct edges", "[weight=1][part=1]") {
  vertexmaker vertexmaker("airports.dat.txt","routes.dat.txt");

  const Graph& g = vertexmaker.getGraph();
  REQUIRE( g.vertexExists("Beijing Capital International Airport"));
  REQUIRE( g.vertexExists("Pope Field"));
  REQUIRE( g.vertexExists("Huron Regional Airport"));
  REQUIRE( g.vertexExists("Boeing Field King County International Airport"));
  REQUIRE( g.vertexExists("Yakima Air Terminal McAllister Field"));
  REQUIRE( g.vertexExists("Islita Airport"));
  REQUIRE( g.vertexExists("Yakima Air Terminal McAllister Field"));
  REQUIRE( g.vertexExists("Vanua Balavu Airport"));
  REQUIRE( g.vertexExists("Valesdir Airport"));
  REQUIRE( g.vertexExists("Milingimbi Airport"));
  REQUIRE( g.vertexExists("Allstedt Airport"));
  REQUIRE( g.edgeExists("Astrakhan Airport","Kazan International Airport") == true);
  REQUIRE( g.edgeExists("Domodedovo International Airport", "Kazan International Airport") == true);
}

TEST_CASE("Test Dijkstra's Algorithm works properly", "[weight=1][part=1]") {
  vertexmaker myVertex("airports.dat.txt","routes.dat.txt");
  auto shortestPath = myVertex.shortestPath("Beijing Capital International Airport", "Guangzhou Baiyun International Airport");
  REQUIRE(shortestPath.first == (int)GetDistance(40.080101013183594, 116.58499908447266, 23.39240074157715, 113.29900360107422));

}


TEST_CASE("Test Connected Algorithm works properly", "[weight=1][part=1]") {
  vertexmaker myVertex("airports.dat.txt","routes.dat.txt");
  bool path = myVertex.ifPath("Beijing Capital International Airport", "Guangzhou Baiyun International Airport");
  bool track =  myVertex.ifPath("Keflavik International Airport" ,  "Patreksfjörður Airport");
  bool a = myVertex.ifPath("Santa Barbara Municipal Airport", "Chicago O'Hare International Airport");
  bool b = myVertex.ifPath("Surat Thani Airport","Funafuti International Airport");
  REQUIRE(a == true);
  REQUIRE(b == true);
  REQUIRE(path == true);
  REQUIRE(track == false);
}




