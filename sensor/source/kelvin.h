#include <systemc-ams.h>
#define NBitsADC 12                   // SystemC AMS header

SCA_TDF_MODULE(kelvin)                 // Declare a TDF module
{
  sca_tdf::sca_in< sc_dt::sc_int<NBitsADC> > in;
  sca_tdf::sca_out< sc_dt::sc_int<NBitsADC> > out; 
           

  void processing();                       // Describe time-domain behaviour

  SCA_CTOR(kelvin)                     // Constructor of the TDF module
  : in("in"), out("out"){

  }                // Initial values for ampl and freq

};