/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 23:06:37 by chuang            #+#    #+#             */
/*   Updated: 2015/11/19 18:35:34 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_color			smooth_color(t_env *e, int iter)
{
	double		nu;

	if (iter < e->fv.maxiter && iter >= 0)
	{
		nu = e->fv.z.r * e->fv.z.r + e->fv.z.i * e->fv.z.i;
		nu = log(log(sqrt(nu))) / log(2);
		nu = iter - nu;
		nu = ((N_COLORS - 1) * nu) / e->fv.maxiter;
		if ((int)nu < 0 || (int)nu > N_COLORS - 1)
			return (e->fv.tab[0]);
		else
			return (e->fv.tab[(int)nu]);
	}
	else
		return (e->fv.tab[0]);
}

void			put_pxl_image(t_env *e, t_color color)
{
	int		ptr;

	ptr = e->fv.y * e->sizeline + e->fv.x * (e->bpp / 8);
	e->data[ptr] = color.b;
	e->data[ptr + 1] = color.g;
	e->data[ptr + 2] = color.r;
}

void			draw(t_env *e)
{
	e->fv.zoom_x = SCREEN_L / (e->fv.x_max - e->fv.x_min);
	e->fv.x = 0;
	while (e->fv.x < SCREEN_L)
	{
		e->fv.y = 0;
		e->fv.c.r = e->frac == 1 ?
			e->fv.x / e->fv.zoom_x + e->fv.x_min : e->fv.c.r;
		while (e->fv.y < SCREEN_H)
		{
			if (e->frac == 1)
				fml_mandel(e);
			else if (e->frac == 2)
				fml_julia(e);
			else
				fml_tree(e);
			e->fv.y++;
		}
		e->fv.x++;
	}
}

void			def_color(t_env *e)
{
	int		i;

	i = 0;
	while (i < 256)
	{
		e->fv.tab[i].r = i;
		e->fv.tab[i].g = 0;
		e->fv.tab[i].b = 0;
		e->fv.tab[i + 256].r = 255 - i;
		e->fv.tab[i + 256].g = i;
		e->fv.tab[i + 256].b = i;
		e->fv.tab[i + 512].r = 255;
		e->fv.tab[i + 512].g = 255 - i;
		e->fv.tab[i + 512].b = 0;
		e->fv.tab[i + 768].r = 255;
		e->fv.tab[i + 768].g = 0;
		e->fv.tab[i + 768].b = i;
		e->fv.tab[i + 1024].r = 255 - i;
		e->fv.tab[i + 1024].g = 255;
		e->fv.tab[i + 1024].b = 0;
		e->fv.tab[i + 1280].r = 255;
		e->fv.tab[i + 1280].g = 255 - i;
		e->fv.tab[i + 1280].b = 255 - i;
		i++;
	}
}
