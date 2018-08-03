
#include <systemc-ams>
#include "escalador.h"
#include "sin_source.h"
#include "integrador.h"
#include "escalador2.h"
#include "adc.h"
#include "convertidor_centigrados.h"
#include "kelvin.h"
#include "faren.h"
#include "alarma.h"
#include "display.h"
int sc_main(int argn, char* argc[])          // SystemC main program
{
 sca_tdf::sca_signal<double> sigInput; //Cable entrada
 sca_tdf::sca_signal<double> esclador_integrador;
 sca_tdf::sca_signal<double> integrador_escalador2;
 sca_tdf::sca_signal<double> sigOutput; //Cable salidas
 sca_tdf::sca_signal< sc_int<NBitsADC> > sigOutputADC;
 sca_tdf::sca_signal< sc_int<NBitsADC> > centigrad;
 sca_tdf::sca_signal< sc_int<NBitsADC> > kelvins;
 sca_tdf::sca_signal< sc_int<NBitsADC> > fareni;
 sca_tdf::sca_signal< bool > centi_alarm;


 sin_source fuente("fuente");
    fuente.out(sigInput);

 Escalador1 escalador1("escalador1");//Instacia de mi fuente
 	escalador1.in(sigInput);
 	escalador1.out(esclador_integrador);

 Integrador integrador("integrador");
    integrador.in(esclador_integrador);
    integrador.out(integrador_escalador2);

 Escalador2 escalador2("escalador2");
 	escalador2.in(integrador_escalador2);
 	escalador2.out(sigOutput);

 adc ADC1("ADC1");
	ADC1.in_sig(sigOutput);
	ADC1.out_d(sigOutputADC);

 convertidor_centigrados cel1("cel1");
 	cel1.in(sigOutputADC);
 	cel1.out(centigrad);

 kelvin kelvin("kelvins");
 	kelvin.in(sigOutputADC);
 	kelvin.out(kelvins);

 faren faren("faren");
 	faren.in(sigOutputADC);
 	faren.out(fareni);

alarma alarma("alarma");
	alarma.in(centigrad);
	alarma.alert(centi_alarm);

display display("display");
	display.in_centi(centigrad);
	display.in_kelvin(kelvins);
	display.in_fare(fareni);




 sca_trace_file *tdf = sca_create_tabular_trace_file("testbench");
 	sca_trace(tdf, sigInput, "sigInput");
 	sca_trace(tdf, esclador_integrador, "esclador_integrador");
 	sca_trace(tdf, integrador_escalador2, "integrador_escalador2");
 	sca_trace(tdf, sigOutput, "sigOutput");
 	sca_trace(tdf, sigOutputADC, "sigOutputADC");
 	sca_trace(tdf, centigrad, "centigrad");
 	sca_trace(tdf, kelvins, "kelvins");
 	sca_trace(tdf, fareni, "fareni");
 	sca_trace(tdf, centi_alarm, "centi_alarm");

 	sc_start(5000,SC_US);
 	sca_close_tabular_trace_file(tdf);


 	return 0; 

}
 