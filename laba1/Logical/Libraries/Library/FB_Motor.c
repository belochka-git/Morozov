
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
void FB_Motor(struct FB_Motor* inst)
{
	inst->dt = 0.01;
	
	inst->integrator.in = ((inst->u / inst->ke) - inst->w) / inst->Tm;
	FB_Integrator(&inst->integrator);
	inst->w = inst->integrator.out;
	
}
