#include "../includes/miniRT.h"

/**
 * @brief  converts float to raw fixed point value (int)
 * @param  n: incoming float
 * @retval raw fixed point value
 */
int	float_to_fix(float n)
{
	return (n * 256);
}

/**
 * @brief  converts raw fixed point value back to float
 * @note   (rounding error, not our fault, check if its a problem)
 * @param  raw: raw fixed point value (int)
 * @retval converted float
 */
float	fix_to_float(int raw)
{
	// float	tmp;

	// tmp = raw / (float)256;
	// return (roundf(tmp * 100) / 100);
	return (raw / (float)256);
}
