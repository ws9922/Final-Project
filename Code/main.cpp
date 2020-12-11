
#include <vector>
#include "edge.h"
#include <iostream>
#include "fileToVector.h"
#include "GetDistance.h"
#include "vertexmaker.h"
#include <map>
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

using namespace std;

class myComparator{
    public:
      int operator() (std::pair<Vertex, int> p1, std::pair<Vertex, int> p2){
            return p1.second > p2.second;
      }
  };

std::pair<int, std::vector<Vertex> >shortestPath_(Graph g, Vertex source, Vertex dest){
  int distances = 0;
  std::map<Vertex, Vertex> previous;
  priority_queue<std::pair<Vertex, int>, vector<std::pair<Vertex, int>>, myComparator> q;
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

int main() {
  // auto v = airport_file_to_vector("airports.dat.txt");
  // for(int i = 1; i < 6; i++) {
  //   cout << "this is ID  " << i << endl;
  //   std::string ID = std::to_string(i);
  //   cout << "this is name " << v[ID][0]<< endl;
  //   cout << "this is longitude " << v[ID][1]<< endl;
  //   cout << "this is latitude " << v[ID][2]<< endl;
  // }

  // auto info = route_file_to_pair("routes.dat.txt");
  // for(int i = 1; i < 6; i++) {
  //   cout << "this is source ID  " << info[i].first << endl;
  //   std::string sourceID = info[i].first;
  //   cout << "this is source name " << v[sourceID][0]<< endl;
  //   cout << "this is souce longitude " << v[sourceID][1]<< endl;
  //   cout << "this is source latitude " << v[sourceID][2]<< endl;
  // }
  // cout << info[171].first << endl;
  // cout << info[171].second << endl;
  // cout<< v[info[171].second][0] << endl;


  // Graph g = Graph(true,false);
  // g.insertVertex("Siebel");
  // g.insertVertex("Rantoul");
  // g.insertVertex("Bloomington");
  // g.insertVertex("Kankakee");
  // g.insertVertex("Pontiac");
  // g.insertVertex("Chicago");
  // g.insertVertex("Joliet");
  // g.insertVertex("Cloudgate");

  // g.insertEdge("Siebel", "Rantoul");
  // g.setEdgeWeight("Siebel", "Rantoul", 21);

  // g.insertEdge("Siebel", "Bloomington");
  // g.setEdgeWeight("Siebel", "Bloomington", 50);

  // g.insertEdge("Rantoul", "Kankakee");
  // g.setEdgeWeight("Rantoul", "Kankakee", 57);

  // g.insertEdge("Bloomington", "Pontiac");
  // g.setEdgeWeight("Bloomington", "Pontiac", 45);

  // g.insertEdge("Kankakee", "Pontiac");
  // g.setEdgeWeight("Kankakee", "Pontiac", 53);

  // g.insertEdge("Kankakee", "Chicago");
  // g.setEdgeWeight("Kankakee", "Chicago", 63);

  // g.insertEdge("Pontiac", "Chicago");
  // g.setEdgeWeight("Pontiac", "Chicago", 40);

  // g.insertEdge("Pontiac", "Joliet");
  // g.setEdgeWeight("Pontiac", "Joliet", 57);

  // g.insertEdge("Joliet", "Chicago");
  // g.setEdgeWeight("Joliet", "Chicago", 51);

  // g.insertEdge("Chicago", "Cloudgate");
  // g.setEdgeWeight("Chicago", "Cloudgate", 1);


  // pair<int,vector<Vertex>> p = shortestPath_(g, "Siebel", "Rantoul");
  // cout<<p.first<<endl;
  // for(Vertex & v : p.second){
  //   cout<<v<<endl;
  //  }


  vertexmaker myVertex("airports.dat.txt","routes.dat.txt");
  auto shortestPath = myVertex.shortestPath("Keflavik International Airport", "Patreksfjörður Airport");
  cout<< shortestPath.first<<endl;
  cout<< shortestPath.second.size()<<endl;
  // for(std::string & s : shortestPath.second){
  //   cout<<s<<endl;
  // }
  Graph g = myVertex.getGraph();
  // cout<<g.getEdgeWeight("Beijing Capital International Airport", "Chicago O'Hare International Airport")<<endl;
  // cout<<g.getEdgeWeight("Beijing Capital International Airport", "Naha Airport")<<endl;
  // cout<<g.getEdgeWeight("Naha Airport", "Sam Ratulangi Airport")<<endl;
  // cout<<g.getEdgeWeight("Sam Ratulangi Airport", "Hasanuddin International Airport")<<endl;
  // cout<<g.getEdgeWeight("Hasanuddin International Airport", "Ngurah Rai (Bali) International Airport")<<endl;
  // cout<<g.getEdgeWeight("Ngurah Rai (Bali) International Airport", "Melbourne International Airport")<<endl;
  // cout<<g.getEdgeWeight("Melbourne International Airport", "Hartsfield Jackson Atlanta International Airport")<<endl;
  // cout<<g.getEdgeWeight("Hartsfield Jackson Atlanta International Airport", "Chicago O'Hare International Airport")<<endl;



  return 0;
}
