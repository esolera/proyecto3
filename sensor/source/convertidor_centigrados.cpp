#include "convertidor_centigrados.h"
#include <cmath>                                      // for M_PI and std::sin

void convertidor_centigrados::processing()                         // Describe time-domain behaviour
{
  double a =(double) in.read();
  double salida = a*0.03257+3.3224;
  sc_dt::sc_int<NBitsADC> salida2 = lround(salida);
  out.write(salida2);                                      // Write sample to the output
}
