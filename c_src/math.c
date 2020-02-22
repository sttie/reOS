#include "../include/math.h"

int binpow(int base, int deg)
{
	if (deg == 0)
		return 1;
	if (deg % 2 == 1)
		return binpow(base, deg - 1) * base;
	else
	{
		int temp = binpow(base, deg/2);
		return temp * temp;
	}
}