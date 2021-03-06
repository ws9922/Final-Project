#pragma once
#include <cmath>
#include <math.h>

/*
* this is a function changing the latitude and longtitude in to radius
* @param  d   longitude or latitude inputed
* @return The changed longitude or latitude value
*/

double rad(double d);
/*
* this is a function calculating the distance between two airports,
* take out both of its latitude and longitude,and first convert it using the above function
* then by applying the equation we found online to calculate the linear distance between two point
* finally we scale it and return the distance
* @param  lat1    latitude of the source airport
* @param  lng1    longitude of the source airport
* @param  lat2    latitude of the destination airport
* @param  lng2    longitude of the destination airport
* @return s       the distance between two points in Kilometer 
*/
double GetDistance(double lat1, double lng1, double lat2, double lng2);
