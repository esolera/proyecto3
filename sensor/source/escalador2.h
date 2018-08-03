#include <systemc-ams.h>                   // SystemC AMS header

SCA_TDF_MODULE(Escalador2)                 // Declare a TDF module
{
  sca_tdf::sca_in<double> in;
  sca_tdf::sca_out<double> out; 
           // TDF output port

  void processing();                       // Describe time-domain behaviour

  SCA_CTOR(Escalador2)                     // Constructor of the TDF module
  : in("in"), out("out"){

  }                // Initial values for ampl and freq

};
