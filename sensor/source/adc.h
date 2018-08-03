#include <systemc-ams.h>                   // SystemC AMS header
#define NBitsADC 12
SCA_TDF_MODULE(adc) // Very simple AD converter
{
 sca_tdf::sca_in<double> in_sig; // TDF port
 sca_tdf::sca_out< sc_dt::sc_int<NBitsADC> > out_d; // converter port to discrete-event domain

 void processing();

 SCA_CTOR(adc) : in_sig("in_sig"), out_d("out_d") { }

};