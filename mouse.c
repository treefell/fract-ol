/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 18:49:56 by chuang            #+#    #+#             */
/*   Updated: 2015/11/26 19:11:17 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_define.h"
#define ZOOM_IN 0.8
#define ZOOM_OUT 1.2

int				mouse_motion_hook(int x, int y, t_env *e)
{
	double		event_x;
	double		event_y;

	event_x = x;
	event_y = y;
	if ((e->fv.motion))
	{
		event_x = x * (e->fv.x_max - e->fv.x_min) / SCREEN_L + e->fv.x_min;
		event_y = y * (e->fv.y_max - e->fv.y_min) / SCREEN_H + e->fv.y_min;
		e->fv.c.r = event_x;
		e->fv.c.i = event_y;
		apply_key(e);
	}
	return (0);
}

static void		mouse_zoom(t_env *e, double zoom_factor, int x, int y)
{
	double				event_x;
	double				event_y;

	event_x = x * (e->fv.x_max - e->fv.x_min) / SCREEN_L + e->fv.x_min;
	event_y = y * (e->fv.y_max - e->fv.y_min)
		/ SCREEN_H + e->fv.y_min;
	e->fv.x_min = (e->fv.x_min - event_x) * zoom_factor + event_x;
	e->fv.x_max = (e->fv.x_max - event_x) * zoom_factor + event_x;
	e->fv.y_min = (e->fv.y_min - event_y) * zoom_factor + event_y;
	e->fv.y_max = (e->fv.y_max - event_y) * zoom_factor + event_y;
	e->fv.x_max = e->fv.x_max > 50 ? 50 : e->fv.x_max;
	e->fv.y_max = e->fv.y_max > 50 ? 50 : e->fv.y_max;
	e->fv.x_min = e->fv.x_min < -50 ? -50 : e->fv.x_min;
	e->fv.y_min = e->fv.y_min < -50 ? -50 : e->fv.y_min;
	e->fv.zoom_x = SCREEN_L / (e->fv.x_max - e->fv.x_min);
	e->fv.zoom_y = SCREEN_H / (e->fv.y_max - e->fv.y_min);
	apply_key(e);
}

int				mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == MOUSE_WHEEL_DOWN || button == MOUSE_BUTTON_R)
		mouse_zoom(e, ZOOM_OUT, x, y);
	if (button == MOUSE_WHEEL_UP || button == MOUSE_BUTTON_L)
		mouse_zoom(e, ZOOM_IN, x, y);
	return (0);
}
