#include "display.h"
#include <cmath>                                      // for M_PI and std::sin

void display::processing()                         // Describe time-domain behaviour
{
  sc_dt::sc_int<NBitsADC> centi = in_centi.read();
  sc_dt::sc_int<NBitsADC> kelvin = in_kelvin.read();
  sc_dt::sc_int<NBitsADC> fare = in_fare.read();
  bool sel_cen = false;
  bool sel_fare = false;
  bool sel_kelvin = true;

  if(sel_cen){
    std::cout<<"centigrados:" << (centi/10)%10 << centi%10  << std::endl;

  }
  if(sel_kelvin){

    std::cout <<"kelvin:-" << (-1*kelvin/100)%10 << (-1*kelvin/10)%10 << -1*kelvin%10 << std::endl;
  } 
  if(sel_fare){
    std::cout <<"faren:"<< (fare/100)%10 << (fare/10)%10 << fare%10  << std::endl;
  }
}
