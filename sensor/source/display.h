#include <systemc-ams.h>
#define NBitsADC 12                   // SystemC AMS header

SCA_TDF_MODULE(display)                 // Declare a TDF module
{
  sca_tdf::sca_in< sc_dt::sc_int<NBitsADC> > in_centi;
  sca_tdf::sca_in< sc_dt::sc_int<NBitsADC> > in_kelvin;
  sca_tdf::sca_in< sc_dt::sc_int<NBitsADC> > in_fare;
           

  void processing();                       // Describe time-domain behaviour

  SCA_CTOR(display)                     // Constructor of the TDF module
  : in_centi("in_centi"),in_kelvin("in_kelvin"), in_fare("in_fare"){

  }                // Initial values for ampl and freq

};