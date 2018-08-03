#include <systemc-ams.h>                   // SystemC AMS header

SCA_TDF_MODULE(Integrador)                 // Declare a TDF module
{
  sca_tdf::sca_in<double> in;
  sca_tdf::sca_out<double> out; 
           // TDF output port
  double K;
  double Int0;
  double Int1;
  double Vout;

  void processing();                       // Describe time-domain behaviour

  SCA_CTOR(Integrador)                     // Constructor of the TDF module
  : in("in"), out("out"),K(10),Int0(0),Int1(0),Vout(0){

  }                // Initial values for ampl and freq

};

