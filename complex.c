/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 18:27:57 by chuang            #+#    #+#             */
/*   Updated: 2015/11/19 18:23:57 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

t_cpx			new_cpx(double real, double imag)
{
	t_cpx		cpx;

	cpx.r = real;
	cpx.i = imag;
	return (cpx);
}

t_cpx			cpx_add(t_cpx a, t_cpx b)
{
	t_cpx		res;

	res.r = a.r + b.r;
	res.i = a.i + b.i;
	return (res);
}

t_cpx			cpx_mult(t_cpx a, t_cpx b)
{
	t_cpx		res;

	res.r = a.r * b.r - a.i * b.i;
	res.i = a.i * b.r + a.r * b.i;
	return (res);
}

t_cpx			cpx_sqrt(t_cpx a)
{
	t_cpx		b;

	b = a;
	a.r = sqrt((b.r + sqrt(b.r * b.r + b.i * b.i)) / 2);
	a.i = b.i / fabs(b.i) * sqrt((-b.r + sqrt(b.r * b.r + b.i * b.i)) / 2);
	return (a);
}
