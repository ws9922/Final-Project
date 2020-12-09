
#include <vector>
#include "edge.h"
#include <iostream>
#include "fileToVector.h"
#include "GetDistance.h"
#include "vertexmaker.h"


using namespace std;
int main() {
  //auto v = airport_file_to_vector("airports.dat.txt");
  // for(int i = 0; i < 5; i++) {
  //   cout << "this is ID  " << v[i][0]<< endl;
  //   cout << "this is name " << v[i][1]<< endl;
  //   cout << "this is longitude " << v[i][2]<< endl;
  //   cout << "this is latitude " << v[i][3]<< endl;
  // }
  /*
  auto info = route_file_to_pair("routes.dat.txt");
  cout << info[5].first << endl;
  cout << info[5].second << endl;
  for(unsigned long i = 0; i < v.size()-1;i++){
    if(info[5].first == v[i][0]){
      cout << "first" << v[i][1]<< endl;
      cout << "first" << v[i][2]<< endl;
      cout << "first" << v[i][3]<< endl;
    }
    if(info[5].second == v[i][0]){
      cout << v[i][1]<< endl;
      cout << v[i][2]<< endl;
      cout << v[i][3]<< endl;
    }
  }
  */
  double d = GetDistance(55.40879821777344,37.90629959106445,55.606201171875,49.278701782227);
  cout << d << endl;
  double d2 = GetDistance(46.2832984924,48.0063018799,55.606201171875,49.278701782227);
  cout << d2 << endl;
  return 0;
}
