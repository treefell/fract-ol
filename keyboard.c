/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 20:33:24 by chuang            #+#    #+#             */
/*   Updated: 2015/11/19 18:30:20 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_define.h"

int			apply_key(t_env *e)
{
	draw(e);
	expose_hook(e);
	return (0);
}

void		decrease_move(double *min, double *max)
{
	*min -= (*min - *max) / MOVE_STEP;
	*max -= (*min - *max) / MOVE_STEP;
}

void		increase_move(double *min, double *max)
{
	*min += (*min - *max) / MOVE_STEP;
	*max += (*min - *max) / MOVE_STEP;
}

int			key_press_hook(int keycode, t_env *e)
{
	if (keycode == KEY_MINUS)
		e->fv.maxiter /= e->fv.maxiter < 1 ? 1 : 2;
	if (keycode == KEY_EQUAL)
		e->fv.maxiter *= e->fv.maxiter > 400 ? 1 : 2;
	if (keycode == KEY_A)
		decrease_move(&e->fv.x_min, &e->fv.x_max);
	if (keycode == KEY_D)
		increase_move(&e->fv.x_min, &e->fv.x_max);
	if (keycode == KEY_S)
		decrease_move(&e->fv.y_min, &e->fv.y_max);
	if (keycode == KEY_W)
		increase_move(&e->fv.y_min, &e->fv.y_max);
	apply_key(e);
	return (0);
}

int			key_release_hook(int keycode, t_env *e)
{
	if (keycode == KEY_SPACE)
		e->fv.motion = e->fv.motion ? 0 : 1;
	if (keycode == KEY_ESC)
		exit(0);
	apply_key(e);
	return (0);
}
