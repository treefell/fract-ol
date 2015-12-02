/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 23:19:42 by chuang            #+#    #+#             */
/*   Updated: 2015/11/26 18:39:20 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandel(t_env *e)
{
	e->fv.motion = 0;
	e->fv.x_min = -2.1;
	e->fv.x_max = 0.6;
	e->fv.y_min = -1.2;
	e->fv.y_max = 1.2;
}

void	init_julia(t_env *e)
{
	e->fv.c.r = 0;
	e->fv.c.i = 0;
	e->fv.motion = 1;
	e->fv.x_min = -2;
	e->fv.x_max = 2;
	e->fv.y_min = -2;
	e->fv.y_max = 2;
}

void	init_tree(t_env *e)
{
	e->fv.c.r = -0.2;
	e->fv.c.i = 0;
	e->fv.motion = 0;
	e->fv.x_min = -1;
	e->fv.x_max = 1.5;
	e->fv.y_min = -1;
	e->fv.y_max = 1;
}

void	init_tricorn(t_env *e)
{
	e->fv.motion = 0;
	e->fv.x_min = -2;
	e->fv.x_max = 2;
	e->fv.y_min = -2;
	e->fv.y_max = 2;
}
