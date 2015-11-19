/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 00:41:13 by chuang            #+#    #+#             */
/*   Updated: 2015/11/19 18:25:01 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_define.h"

void			init_env(t_env *e)
{
	def_color(e);
	e->fv.maxiter = MAX_ITER;
	if (e->frac == 2)
		init_julia(e);
	else if (e->frac == 1)
		init_mandel(e);
	else
		init_tree(e);
}

int				expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void			init_hook(t_env *e, char *av)
{
	if (!(e->mlx = mlx_init()))
		exit(0);
	if (!(e->win = mlx_new_window(e->mlx, SCREEN_L, SCREEN_H, av)))
		exit(0);
	if (!(e->img = mlx_new_image(e->mlx, SCREEN_L, SCREEN_H)))
		exit(0);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	draw(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_release_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, key_press_hook, e);
	mlx_hook(e->win, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_motion_hook, e);
	mlx_loop(e->mlx);
}
