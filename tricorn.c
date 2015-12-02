/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:20:16 by chuang            #+#    #+#             */
/*   Updated: 2015/11/26 19:37:22 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fml_tricorn(t_env *e)
{
	int			i;

	i = 0;
	e->fv.zoom_y = SCREEN_H / (e->fv.y_max - e->fv.y_min);
	e->fv.c.i = e->fv.y / e->fv.zoom_y + e->fv.y_min;
	e->fv.z.r = 0;
	e->fv.z.i = 0;
	i = 0;
	while ((e->fv.z.r * e->fv.z.r) + (e->fv.z.i * e->fv.z.i) < 4
			&& i < e->fv.maxiter)
	{
		e->fv.z.i = -e->fv.z.i;
		e->fv.z = cpx_add(cpx_mult(e->fv.z, e->fv.z), e->fv.c);
		i++;
	}
	put_pxl_image(e, smooth_color(e, i));
}
