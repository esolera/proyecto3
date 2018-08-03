
#include "escalador.h"
#include <cmath>                                      // for M_PI and std::sin

/*void sin_source::set_attributes()                     // Set TDF attributes
{
  out.set_timestep(10, SC_MS);                       // Set time step of output port
}*/
void Escalador1::processing()                         // Describe time-domain behaviour
{
  double t = in.read();             // Get current time of the sample
  double x = 0.15*t-0.5;
  out.write(x);                                      // Write sample to the output
}

