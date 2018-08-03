#include <systemc-ams.h>
#define NBitsADC 12                   // SystemC AMS header

SCA_TDF_MODULE(alarma)                 // Declare a TDF module
{
  sca_tdf::sca_in< sc_dt::sc_int<NBitsADC> > in;
  sca_tdf::sca_out< bool > alert; 
  
           

  void processing();                       // Describe time-domain behaviour

  SCA_CTOR(alarma)                     // Constructor of the TDF module
  : in("in"), alert("alert"){

  }                // Initial values for ampl and freq

};