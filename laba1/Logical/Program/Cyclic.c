
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if (Enable)
	{
		if (counter == 200)
		{
			Speed = 0;
			counter = 0;
		}
		if (counter == 50)
		{
			Speed = 50;
		}
		
		counter++;
		
		fb_regulator.e = Speed - fb_motor1.w;
		FB_Regulator(&fb_regulator);
		fb_motor1.u = fb_regulator.u;
		
		FB_Motor(&fb_motor1);
		
		fb_motor2.u = Speed * fb_motor2.ke;
		FB_Motor(&fb_motor2);
		}
	
}
