

#include "fractol.h"

void	ft_zoom(int k, int x, int y, t_fract *f)
{
	double scal;

	scal = 1;
	if (k == 4 && f->zoom < 2000000000)
	{
		scal = 1.25;
		f->iter += 10;
	}
	if (k == 5)
	{
		scal = 0.8;
		if (f->iter > 80)
			f->iter -= 10;
	}
	f->min.y = (y / f->zoom + f->min.y) - \
	((f->zoom * scal) / 2);
	f->min.y += ((f->zoom * scal) / 2) - \
	(y / (f->zoom * scal));
	f->min.x = (x / f->zoom + f->min.x) - \
	((f->zoom * scal) / 2);
	f->min.x += ((f->zoom * scal) / 2) - \
	(x / (f->zoom * scal));
	f->zoom *= scal;
}

int		ft_mouse(int k, int x, int y, t_fract *f)
{
	if (k == 1)
	{
		if (f->mousestop == 0)
			f->mousestop = 1;
		else if (f->mousestop == 1)
			f->mousestop = 0;
	}
	if (k == 4 || k == 5)
		ft_zoom(k, x, y, f);
	ft_pthread(f);
	return (0);
}

int		mouse_julia(int x, int y, t_fract *f)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && !f->mousestop)
	{
		f->mousex = x;
		f->mousey = y;
		f->zd = (f->mousex) / (double)f->zoom + f->min.x;
		f->zi = (f->mousey) / (double)f->zoom + f->min.y;
		ft_pthread(f);
	}
	return (1);
}
