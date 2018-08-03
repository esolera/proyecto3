
#include "integrador.h"
#include <cmath>                                      // for M_PI and std::sin

/*void sin_source::set_attributes()                     // Set TDF attributes
{
  out.set_timestep(10, SC_MS);                       // Set time step of output port
}*/
void Integrador::processing()                         // Describe time-domain behaviour
{
double Vin= in.read();
double deltat=10e-6;
Int0=(Vin-Vout)*deltat;
Vout=K*(Int0+Int1);
Int1=Int0;
out.write(Vout);                                    // Write sample to the output
}

