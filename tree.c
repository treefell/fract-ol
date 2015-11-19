/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/18 21:21:23 by chuang            #+#    #+#             */
/*   Updated: 2015/11/19 18:34:54 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fml_tree(t_env *e)
{
	int			i;

	e->fv.zoom_y = SCREEN_H / (e->fv.y_max - e->fv.y_min);
	e->fv.z.r = e->fv.x / e->fv.zoom_x + e->fv.x_min;
	e->fv.z.i = e->fv.y / e->fv.zoom_y + e->fv.y_min;
	i = 0;
	while ((e->fv.z.r * e->fv.z.r) + (e->fv.z.i * e->fv.z.i) < 4
			&& i < e->fv.maxiter)
	{
		e->fv.z = cpx_add(cpx_mult(e->fv.z, cpx_sqrt(e->fv.z)), e->fv.c);
		i++;
	}
	put_pxl_image(e, smooth_color(e, i));
}
