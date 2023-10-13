
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
/*void FB_Regulator(struct FB_Regulator* inst)
{
	inst->dt = 0.01;
	inst->integrator.in = (inst->e * inst->k_i) + inst->iyOld;
	FB_Integrator(&inst->integrator);
	if (abs(inst->e * inst->k_p) > inst->max_abs_value)
	{
		if (abs(inst->max_abs_value + inst->integrator.out) > inst->max_abs_value)
		{
			inst->u = inst->max_abs_value;
			inst->iyOld = inst->max_abs_value;
		}
		else
		{
			inst->u = inst->max_abs_value + inst->integrator.out;
			inst->iyOld = 0;
		}
	}
	else
	{
		if (abs((inst->e * inst->k_p) + inst->integrator.out) > inst->max_abs_value)
		{
			inst->u = inst->max_abs_value;
			inst->iyOld = inst->max_abs_value - (inst->e * inst->k_p);
		}
		else
		{
			inst->u = (inst->e * inst->k_p) + inst->integrator.out;
			inst->iyOld = 0;
		}
	}
} */

void FB_Regulator(struct FB_Regulator* inst)
{
	REAL a = inst ->e * inst -> k_p;
	REAL b = inst ->e * inst -> k_i;
	
	a = a > inst -> max_abs_value ? inst ->max_abs_value : a;
	a = a < -inst -> max_abs_value ? -inst ->max_abs_value : a;
	
	inst -> integrator.in = b + inst -> iyOld;
	FB_Integrator (&inst -> integrator);
	
	REAL sum = a + inst -> integrator.out;
	
	inst -> u = sum;
	inst -> u = inst -> u > inst -> max_abs_value ? inst -> max_abs_value : inst -> u;
	inst -> u = inst -> u < -inst -> max_abs_value ? -inst -> max_abs_value : inst -> u;
	
	inst -> iyOld = inst ->u - sum;
}