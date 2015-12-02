/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 21:59:08 by chuang            #+#    #+#             */
/*   Updated: 2015/11/26 18:28:32 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char *av[])
{
	if (ac > 1 && (!ft_strcmp(av[1], "mandel") || !ft_strcmp(av[1], "julia")
				|| !ft_strcmp(av[1], "tree") || !ft_strcmp(av[1], "tricorn")))
	{
		d_fractal(av[1]);
	}
	else
		ft_putendl("Param:\n-mandel\n-julia\n-tree\n");
	return (1);
}
