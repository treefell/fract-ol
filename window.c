/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:33:58 by chuang            #+#    #+#             */
/*   Updated: 2015/11/19 18:06:05 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	d_fractal(char *av)
{
	t_env	e;

	if (ft_strcmp(av, "mandel") == 0)
		e.frac = 1;
	else if (ft_strcmp(av, "julia") == 0)
		e.frac = 2;
	else
		e.frac = 3;
	init_env(&e);
	init_hook(&e, av);
}
