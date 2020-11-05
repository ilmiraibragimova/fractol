

#include "fractol.h"
#include <stdio.h>

int		ft_color(t_fract *f, int i)
{
	int col[7];
	int	j;
	int	color;
	int	n;

	n = -1;
	j = f->iter / 7;
	col[0] = 0x330000 + f->k;
	col[3] = 0xFFFFFF + f->k;
	col[1] = 0x1DF914 + f->k;
	col[2] = 0x199EBD + f->k;
	col[3] = 0x7366BD + f->k;
	col[4] = 0xFB7EFD + f->k;
	col[5] = 0x95918C + f->k;
	col[6] = 0xEE204D + f->k;
	if (i == f->iter)
		color = 0x990000 + f->k;
	else
		while (++n < 7)
		{
			if (i >= j * n && i < (n + 1) * j)
				color = col[n] + 12 * (i % j);
		}
	return (color);
}

void	pixel(int x, int y, t_fract *f, int col)
{
	if (x < WIDTH && x >= 0 && y >= 0 && y < HEIGHT)
		*(int *)(f->addr.img_data + (y * WIDTH) * 4 + x * 4) = col;
}

int		ft_fractal_choose(t_fract *f)
{
	int	deth;

	if (f->name == 2)
		deth = ft_julia(f);
	if (f->name == 1)
		deth = mand(f);
	if (f->name == 3)
		deth = ft_phoenix(f);
	return (deth);
}

void	*fractol(void *tab)
{
	int		deth;
	t_fract	*f;
	double	tmpx;

	f = (t_fract*)tab;
	tmpx = f->x - 1;
	if (f->name == 4)
	{
		ft_clean(f);
		barney(f);
	}
	else
	{
		f->y = -1;
		while (++f->y < HEIGHT)
		{
			f->x = tmpx;
			while (++f->x < f->l)
			{
				deth = ft_fractal_choose(f);
				pixel((int)f->x, (int)f->y, f, ft_color(f, deth));
			}
		}
	}
	return (tab);
}
