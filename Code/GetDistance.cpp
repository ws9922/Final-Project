#include "GetDistance.h"
#include <cmath>
#include <math.h>


const double EARTH_RADIUS = 6378.137;//地球半径
double rad(double d)
{
   return d * M_PI / 180.0;
}

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