

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H
# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>
# define HEIGHT 800
# define WIDTH 1200

typedef struct	s_mlx
{
	void		*ptr_init;
	void		*ptr_win;
	void		*ptr_img;
}				t_mlx;

typedef struct	s_addr
{
	char		*img_data;
	int			bits;
	int			size_line;
	int			endian;
}				t_addr;

typedef struct	s_min
{
	double	x;
	double	y;
}				t_min;

typedef struct	s_fract
{
	t_mlx		mlx;
	t_addr		addr;
	t_min		min;
	double		xd;
	double		xi;
	double		zi;
	double		zd;
	int			iter;
	int			k;
	int			name;
	double		zoom;
	double		x;
	double		y;
	double		l;
	int			mousex;
	int			mousey;
	int			mousestop;
	short		keyh;
}				t_fract;

void			*fractol(void *tab);
int				mand(t_fract *f);
int				ft_key(int key, t_fract *f);
int				ft_julia(t_fract *f);
int				ft_phoenix(t_fract *f);
void			pixel(int x, int y, t_fract *f, int col);
int				barney(t_fract *f);
void			ft_pthread(t_fract *f);
void			ft_clean(t_fract *f);
int				ft_mouse(int k, int x, int y, t_fract *f);
int				mouse_julia(int x, int y, t_fract *f);
void			ft_init(t_fract *f);
#endif
