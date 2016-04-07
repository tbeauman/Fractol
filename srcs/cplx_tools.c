/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:16:37 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 11:45:04 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cpx	mult(t_cpx a, t_cpx b)
{
	t_cpx	ret;

	ret.re = a.re * b.re - a.im * b.im;
	ret.im = a.im * b.re + a.re * b.im;
	return (ret);
}

t_cpx	puissance(t_cpx a, int n)
{
	t_cpx	id;

	id.re = 1;
	id.im = 0;
	if (n == 0)
		return (id);
	return (mult(a, puissance(a, n - 1)));
}

t_cpx	divise(t_cpx a, t_cpx b)
{
	t_cpx	ret;

	ret.re = 0;
	ret.im = 0;
	if (b.re == 0 && b.im == 0)
		return (ret);
	ret.re = (a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im);
	ret.im = (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im);
	return (ret);
}

t_cpx	inverse(t_cpx a)
{
	t_cpx	tp;

	tp.re = 1;
	tp.im = 0;
	return (divise(tp, a));
}

t_cpx	mandelbrot_rec(t_cpx z, t_cpx c, t_env *e)
{
	t_cpx	ret;
	t_cpx	z_2;
	int		cpt;

	cpt = 1;
	z_2 = z;
	while (cpt++ < ABS(e->puissance))
		z_2 = mult(z, z_2);
	if (e->puissance < 0)
		z_2 = inverse(z_2);
	if (e->puissance == 0)
	{
		z_2.re = 1;
		z_2.im = 0;
	}
	ret.re = z_2.re + c.re;
	ret.im = z_2.im + c.im;
	return (ret);
}
