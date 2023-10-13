
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	fb_motor1.dt = 0.01;
	fb_motor1.ke = 0.0011;
	fb_motor1.Tm = 0.0246;
	fb_motor1.u = 60;
	fb_motor1.integrator.dt = 0.01;
	
	
	fb_motor2.dt = 0.01;
	fb_motor2.ke = 0.0011;
	fb_motor2.Tm = 0.0246;
	fb_motor2.u = 0;
	fb_motor2.integrator.dt = 0.01;
	
	fb_regulator.dt = 0.01;
	fb_regulator.integrator.dt = 0.01;
	fb_regulator.k_p = 0.0006;
	fb_regulator.k_i = 0.0228;
	fb_regulator.max_abs_value = 24.0;
	
	Speed = 0;
	counter = 0;
	
}
