#pragma once
#include <cmath>
#include <math.h>

/*
* this is a function calculating the distance between two airports,
* take both of its latitude and longitude,and first convert it using the function rad
* then by applying the equation we found online to calculate the linear distance between two point
* finally we scale it and return the distance
*/

double rad(double d);
  
double GetDistance(double lat1, double lng1, double lat2, double lng2);
