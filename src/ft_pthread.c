

#include "fractol.h"
#include <pthread.h>

void	ft_usage1(t_fract *f)
{
	if (f->keyh == 1)
	{
		mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, WIDTH - 302, \
		HEIGHT - 180, 0xFFFFFF, "Press 'H' to close help");
		mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, WIDTH - 302,\
		HEIGHT - 160, 0xFFFFFF, "Move : [<-] [->] [^] [v]");
		mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, WIDTH - 302,\
		HEIGHT - 140, 0xFFFFFF, "Zoom : Mouse wheel");
		mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, WIDTH - 302,\
		HEIGHT - 120, 0xFFFFFF, "Change Fractal : 1, 2, 3, 4 ");
		mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, WIDTH - 302,\
		HEIGHT - 100, 0xFFFFFF, "Change Color : Space");
		mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, WIDTH - 302,\
		HEIGHT - 80, 0xFFFFFF, "Pause/activate mouse move:");
		mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, WIDTH - 302,\
		HEIGHT - 60, 0xFFFFFF, "Mouse left click");
		mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, WIDTH - 302,\
		HEIGHT - 40, 0xFFFFFF, "Exit : ESCAPE");
	}
	else
		mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, WIDTH - 302, \
		HEIGHT - 30, 0xFFFFFF, "Press 'H' to help");
}

void	ft_string(t_fract *f)
{
	char		*s;
	char		*s1;
	char		*sl;
	char		*sk;

	sl = ft_itoa(f->zoom);
	s = ft_strjoin("ZOOM = ", sl);
	mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, 4, 10, 0xFFFFFF, s);
	ft_strdel(&s);
	ft_strdel(&sl);
	sk = ft_itoa(f->iter);
	s1 = ft_strjoin("ITERATION = ", sk);
	mlx_string_put(f->mlx.ptr_init, f->mlx.ptr_win, 4, 30, 0xFFFFFF, s1);
	ft_strdel(&s1);
	ft_strdel(&sk);
}

void	ft_pthread(t_fract *f)
{
	t_fract		tab[20];
	pthread_t	t[20];
	int			i;

	i = 0;
	while (i < 20)
	{
		ft_memcpy((void *)&tab[i], (void *)f, sizeof(t_fract));
		tab[i].x = ((double)(1.00 / 20) * WIDTH) * i;
		tab[i].l = ((double)(1.00 / 20) * WIDTH) * (i + 1);
		pthread_create(&t[i], NULL, fractol, &tab[i]);
		i += 1;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx.ptr_init, f->mlx.ptr_win, \
	f->mlx.ptr_img, 0, 0);
	ft_string(f);
	ft_usage1(f);
}
