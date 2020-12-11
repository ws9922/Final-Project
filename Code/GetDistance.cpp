#include "GetDistance.h"
#include <cmath>
#include <math.h>
/*
* this is a function changing the latitude and longtitude in to radius
* @param  d   longitude or latitude inputed
* @return The changed longitude or latitude value
*/
const double EARTH_RADIUS = 6378.137;//地球半径,radius of the earth
double rad(double d)
{
   return d * M_PI / 180.0;
}
/*
* this is a function calculating the distance between two airports,
* take out both of its latitude and longitude,and first convert it using the above function
* then by applying the equation we found online to calculate the linear distance between two point
* finally we scale it and return the distance
* @param  lat1    latitude of the source airport
* @param  lng1    longitude of the source airport
* @param  lat2    latitude of the destination airport
* @param  lng2    longitude of the destination airport
* @return s       the distance between two points
*/
double GetDistance(double lat1, double lng1, double lat2, double lng2)
{
   double radLat1 = rad(lat1);
   double radLat2 = rad(lat2);
   double a = radLat1 - radLat2;
   double b = rad(lng1) - rad(lng2);

   double s = 2 * asin(sqrt(pow(sin(a/2),2) +
    cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
   s = s * EARTH_RADIUS;
   s = round(s * 10000) / 10000;
   return s;
}
