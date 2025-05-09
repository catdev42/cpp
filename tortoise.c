#include <stdlib.h>

int	*race(int v1, int v2, int g)
{
	int	*ret;
	int	time_min;
	int	time_hrs;
	int	time_sec;

	// return a heap-allocated array of 3 elements
	ret = calloc(3, sizeof(int));
	if (v1 >= v2)
		for (int i = 0; i < 3; i++)
			ret[i] = -1;
	double t = (double)g / ((double)v2 - (double)v1); // time in hours
	ret[0] = (int)t;
	ret[1] = ((int)t - ret[0]) * 60;
	ret[2] = ((((int)t - ret[0])* 60) - ret[1])*60; //think
	return (ret);
}

int	main(void)
{
	race(750, 820, 70);
}