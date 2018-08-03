#include "kelvin.h"
#include <cmath>                                      // for M_PI and std::sin

void kelvin::processing()                         // Describe time-domain behaviour
{
  double a =(double) in.read();
  double salida = (a*0.03257+3.3224)-273;
  sc_dt::sc_int<NBitsADC> salida2 = lround(salida);
  out.write(salida2);                                      // Write sample to the output
}
