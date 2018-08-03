#include "alarma.h"
#include <cmath>                                      // for M_PI and std::sin

void alarma::processing()                         // Describe time-domain behaviour
{
  double a =(double) in.read();
  bool alerto;
  if (a>=60){
  	alerto=true;
  }
  else{
  	alerto=false;
  }
  alert.write(alerto);
                                      // Write sample to the output
}
