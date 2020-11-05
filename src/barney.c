

#include <stdlib.h>
#include <math.h>
#include "fractol.h"

void	barney1(t_fract *f, double t, double p)
{
	if (p < 0.93)
	{
		f->x = 0.20 * f->x - 0.26 * f->y;
		f->y = 0.26 * t + 0.212 * f->y + 0.44;
	}
	else if (p < 0.99)
	{
		f->x = -0.15 * f->x + 0.28 * f->y;
		f->y = 0.26 * t + 0.24 * f->y + 0.44;
	}
	else
	{
		f->x = 0.0;
		f->y = 0.16 * f->y;
	}
}

int		barney(t_fract *f)
{
	int		i;
	double	p;
	double	t;

	f->x = 1.0;
	f->y = 1.0;
	i = 0;
	while (i < 100000)
	{
		p = ((float)random()) / RAND_MAX;
		t = f->x;
		if (p <= 0.85)
		{
			f->x = 0.84 * f->x + 0.04 * f->y;
			f->y = 0.04 * t + 0.85 * f->y + 1.6;
		}
		else
			barney1(f, t, p);
		pixel(WIDTH / 2 + floor(61 * f->x) + 1, \
		HEIGHT - (floor(40 * f->y) + 100), f, 0x33CC00);
		i++;
	}
	return (0);
}
