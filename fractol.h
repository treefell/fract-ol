/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:09:49 by chuang            #+#    #+#             */
/*   Updated: 2015/11/26 18:40:51 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define SCREEN_L	1080
# define SCREEN_H	960
# define MOVE_STEP	300
# define N_COLORS	1536
# define MAX_ITER	100

typedef struct		s_cpx
{
	double			r;
	double			i;
}					t_cpx;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_fracval
{
	int				x;
	int				y;
	int				maxiter;
	int				motion;
	double			zoom_x;
	double			zoom_y;
	double			x_min;
	double			y_min;
	double			x_max;
	double			y_max;
	t_cpx			z;
	t_cpx			c;

	t_color			tab[N_COLORS];
}					t_fracval;

typedef struct		s_env
{
	void			*mlx;
	void			*img;
	void			*win;
	int				*length;
	int				*height;
	int				sizeline;
	int				bpp;
	int				endian;
	int				frac;
	char			*data;
	t_fracval		fv;
}					t_env;

t_cpx				new_cpx(double r, double i);
t_cpx				cpx_add(t_cpx a, t_cpx b);
t_cpx				cpx_mult(t_cpx a, t_cpx b);
t_cpx				cpx_sqrt(t_cpx a);
void				draw(t_env *e);
int					key_release_hook (int keycode, t_env *e);
int					key_press_hook(int keycode, t_env *e);
int					mouse_motion_hook(int x, int y, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					apply_key(t_env *e);
void				def_color(t_env *e);
void				d_fractal(char *av);
void				init_env(t_env *e);
void				init_hook(t_env *e, char *av);
int					expose_hook(t_env *e);

void				fml_mandel(t_env *e);
void				init_mandel(t_env *e);

void				fml_julia(t_env *e);
void				init_julia(t_env *e);

void				fml_tree(t_env *e);
void				init_tree(t_env *e);

void				fml_tricorn(t_env *e);
void				init_tricorn(t_env *e);

void				put_pxl_image(t_env *e, t_color color);
t_color				smooth_color(t_env *e, int i);
#endif
