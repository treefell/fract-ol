/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:33:58 by chuang            #+#    #+#             */
/*   Updated: 2015/12/02 15:29:55 by chuang           ###   ########.fr       */
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
	else if (ft_strcmp(av, "tree") == 0)
		e.frac = 3;
	else
		e.frac = 4;
	init_env(&e);
	init_hook(&e, av);
}
