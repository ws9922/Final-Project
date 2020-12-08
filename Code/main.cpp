
#include <vector>
#include "edge.h"
#include <iostream>
#include "fileToVector.h"
#include "GetDistance.h"
#include "vertexmaker.h"


using namespace std;
int main() {
  // auto v = airport_file_to_vector("airports.dat.txt");
  // for(int i = 0; i < 5; i++) {
  //   cout << "this is ID  " << v[i][0]<< endl;
  //   cout << "this is name " << v[i][1]<< endl;
  //   cout << "this is longitude " << v[i][2]<< endl;
  //   cout << "this is latitude " << v[i][3]<< endl;
  // }
  auto info = route_file_to_pair("routes.dat.txt");
  cout << info[1].second << endl;
  double d = GetDistance(33.79216800, 118.50230100, 33.79214700, 118.50227700);
  cout << d << endl;
  return 0;
}
