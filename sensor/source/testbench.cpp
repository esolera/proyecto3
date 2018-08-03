//----------------------------------------------------------------------
//   Copyright 2010-2014 Fraunhofer IIS/EAS
//   Copyright 2014 NXP B.V.
//   Copyright 2014 Université Pierre et Marie Curie
//   All Rights Reserved
//
//   Licensed under the Apache License, Version 2.0 (the
//   "License"); you may not use this file except in
//   compliance with the License.  You may obtain a copy of
//   the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in
//   writing, software distributed under the License is
//   distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
//   CONDITIONS OF ANY KIND, either express or implied.  See
//   the License for the specific language governing
//   permissions and limitations under the License.
//----------------------------------------------------------------------
//
//   Original Author: Karsten Einwich Fraunhofer IIS/EAS Dresden
//
//   Created on: 16.02.2010
//
//----------------------------------------------------------------------
#include <systemc-ams>
#include "escalador.h"
#include "sin_source.h"
#include "integrador.h"
#include "escalador2.h"
#include "adc.h"
#include "convertidor_centigrados.h"
int sc_main(int argn, char* argc[])          // SystemC main program
{
 sca_tdf::sca_signal<double> sigInput; //Cable entrada
 sca_tdf::sca_signal<double> esclador_integrador;
 sca_tdf::sca_signal<double> integrador_escalador2;
 sca_tdf::sca_signal<double> sigOutput; //Cable salidas
 sca_tdf::sca_signal< sc_int<NBitsADC> > sigOutputADC;
 sca_tdf::sca_signal< sc_int<NBitsADC> > centigrad;
//sc_core::sc_signal<sc_int<NBitsADC>	 >
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




 sca_trace_file *tdf = sca_create_tabular_trace_file("testbench");
 	sca_trace(tdf, sigInput, "sigInput");
 	sca_trace(tdf, esclador_integrador, "esclador_integrador");
 	sca_trace(tdf, integrador_escalador2, "integrador_escalador2");
 	sca_trace(tdf, sigOutput, "sigOutput");
 	sca_trace(tdf, sigOutputADC, "sigOutputADC");
 	sca_trace(tdf, centigrad, "centigrad");

 	sc_start(5000,SC_US);
 	sca_close_tabular_trace_file(tdf);

 	return 0; 

}
 