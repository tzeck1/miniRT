#include "../../includes/miniRT.h"

int	float_to_fix(float n)
{
	return (n * 256);
}

float	fix_to_float(int raw)
{
	//float	tmp;

	//tmp = raw / (float)256;
	//return (roundf(tmp * 100) / 100);
	return (raw / (float)256);
}
