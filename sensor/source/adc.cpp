#include "adc.h"

void adc::processing()
{
	double v_in = in_sig.read();
	if (v_in > 10.0)
	{
		out_d.write((1 << (NBitsADC - 1)) - 1);
	}
	else
	{
		sc_dt::sc_int<NBitsADC> q_v_in = lround(
				(v_in / 10) * ((1 << (NBitsADC - 1)) - 1));
		

		out_d.write(q_v_in);
	}
}





