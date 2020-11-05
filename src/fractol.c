

#include "fractol.h"

int		mand(t_fract *f)
{
	double	t;
	int		i;
	double	xi;
	double	xd;

	i = 0;
	xi = (f->mousey - HEIGHT) / ((double)HEIGHT) + 0.50;
	xd = (f->mousex - WIDTH) / ((double)WIDTH * 2) + 0.25;
	f->zd = (f->x) / f->zoom + f->min.x;
	f->zi = (f->y) / f->zoom + f->min.y;
	while (i < f->iter && xd * xd + xi * xi < 4)
	{
		t = xd;
		xd = t * t - xi * xi + f->zd;
		xi = 2 * xi * t + f->zi;
		i++;
	}
	return (i);
}

int		ft_julia(t_fract *f)
{
	double	t;
	int		i;

	i = 0;
	f->xd = (f->x) / f->zoom + f->min.x;
	f->xi = (f->y) / f->zoom + f->min.y;
	while (i < f->iter && f->xd * f->xd + f->xi * f->xi < 4)
	{
		t = f->xd;
		f->xd = t * t - f->xi * f->xi + f->zd;
		f->xi = 2 * f->xi * t + f->zi;
		i++;
	}
	return (i);
}

int		ft_phoenix(t_fract *f)
{
	double	t;
	int		i;

	i = 0;
	f->xi = (f->mousey - HEIGHT) / ((double)HEIGHT) + 0.50;
	f->xd = (f->mousex - WIDTH) / ((double)WIDTH * 2) + 0.25;
	f->zd = (f->x) / f->zoom + f->min.x;
	f->zi = (f->y) / f->zoom + f->min.y - 0.5;
	while (i < f->iter && f->xd * f->xd + f->xi * f->xi < 4)
	{
		t = f->xd;
		f->xd = t * t - f->xi * f->xi + f->zd;
		f->xi = 2 * fabs(f->xi * t) + f->zi;
		i++;
	}
	return (i);
}

void	ft_clean(t_fract *f)
{
	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = -1;
		while (f->x++ < WIDTH)
			pixel(f->x, f->y, f, 0x99FFFF);
		f->y++;
	}
}
