

#include "fractol.h"

void	ft_julia1(t_fract *f)
{
	int r;

	r = random() % 4;
	if (r == 3)
	{
		f->zi = 0.520000;
		f->zd = -0.506667;
	}
	else if (r == 1)
	{
		f->zd = 0.403333;
		f->zi = 0.273333;
	}
	else if (r == 2)
	{
		f->zi = 0.103333;
		f->zd = 0.386667;
	}
	else if (r == 0)
	{
		f->zi = -0.566667;
		f->zd = 0.18;
	}
}

void	ft_offset(int key, t_fract *f)
{
	if (key == 123)
		f->min.x += 5 / f->zoom;
	if (key == 124)
		f->min.x -= 5 / f->zoom;
	if (key == 125)
		f->min.y -= 5 / f->zoom;
	if (key == 126)
		f->min.y += 5 / f->zoom;
}

int		ft_key(int key, t_fract *f)
{
	if (key == 49)
		f->k += 0x150000;
	if (key == 53)
		exit(0);
	if (key == 4 && f->keyh == 0)
		f->keyh = 1;
	else if (key == 4 && f->keyh == 1)
		f->keyh = 0;
	if (key >= 18 && key <= 21)
	{
		f->name = key - 17;
		f->mousestop = 1;
		ft_init(f);
		if (f->name == 2)
			ft_julia1(f);
	}
	if (key >= 123 && key <= 126)
		ft_offset(key, f);
	ft_pthread(f);
	return (0);
}
