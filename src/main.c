

#include "fractol.h"
#include <stdio.h>

void	ft_usage(void)
{
	write(1, "usage: ./fractol [mandelbrot or 1]\n", 35);
	write(1, "                 [julia or 2]\n", 30);
	write(1, "                 [phoenix or 3]\n", 33);
	write(1, "                 [barsney or 4]\n", 33);
}

void	ft_name(t_fract *f, char *s)
{
	if (!ft_strcmp(s, "julia") || !ft_strcmp(s, "2"))
		f->name = 2;
	else if (!ft_strcmp(s, "mandelbrot") || !ft_strcmp(s, "1"))
		f->name = 1;
	else if (!ft_strcmp(s, "barsney") || !ft_strcmp(s, "4"))
		f->name = 4;
	else if (!ft_strcmp(s, "phoenix") || !ft_strcmp(s, "3"))
		f->name = 3;
	else
	{
		ft_usage();
		exit(1);
	}
}

void	ft_init(t_fract *f)
{
	f->k = 0;
	f->zoom = 300;
	f->x = 1;
	f->zi = -0.566667;
	f->zd = 0.180000;
	f->mousestop = 1;
	f->min.x = -2.1;
	f->min.y = -1.2;
	f->mousex = WIDTH / 2;
	f->mousey = HEIGHT / 2;
	if (f->name == 1)
		f->iter = 150;
	if (f->name == 2)
		f->iter = 400;
	if (f->name == 3)
		f->iter = 80;
}

int		main(int argc, char **argv)
{
	t_fract *f;

	if (argc != 2)
	{
		ft_usage();
		return (1);
	}
	if (!(f = (t_fract*)malloc(sizeof(t_fract))))
	{
		write(1, "Allocation memory error\n", 24);
		return (1);
	}
	ft_name(f, argv[1]);
	f->mlx.ptr_init = mlx_init();
	f->mlx.ptr_win = mlx_new_window(f->mlx.ptr_init, WIDTH, HEIGHT, "");
	f->mlx.ptr_img = mlx_new_image(f->mlx.ptr_init, WIDTH, HEIGHT);
	f->addr.img_data = mlx_get_data_addr(f->mlx.ptr_img, &f->addr.bits, \
	&f->addr.size_line, &f->addr.endian);
	ft_init(f);
	ft_pthread(f);
	mlx_hook(f->mlx.ptr_win, 2, 3, ft_key, f);
	mlx_mouse_hook(f->mlx.ptr_win, ft_mouse, f);
	mlx_hook(f->mlx.ptr_win, 6, 1, mouse_julia, f);
	mlx_loop(f->mlx.ptr_init);
}
