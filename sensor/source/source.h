#include <systemc-ams.h>
SC_MODULE(thermal_source)
{
	sca_eln::sca_terminal in, out;
	sca_eln::sca_node n1;
	sca_eln::sca_r *r1,*r2;
	sca_eln::sca_c *c1;
	sca_eln::sca_node_ref gnd;
	SC_CTOR(thermal_source)
	{
		r1 = new sca_eln::sca_r("r");
		r1->p(in);
		r1->n(out);
		r1->value = 1e3;

		c1 = new sca_eln::sca_c("c1", 50e-3); //positional parameter association
 		c1->p(out);
 		c1->n(n1);
 
 		r2 = new sca_eln::sca_r("r2",1000.0);
 		r2->p(n1);
 		r2->n(gnd);
 	}		
}; 
	