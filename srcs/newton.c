/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 18:07:01 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 11:54:49 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cpx	itere_de_newton(t_cpx z)
{
	t_cpx	ret;
	t_cpx	t;
	t_cpx	trois;

	trois.re = 3;
	trois.im = 0;
	t.re = puissance(z, 3).re - 1;
	t.im = puissance(z, 3).im;
	t = divise(t, mult(trois, puissance(z, 2)));
	ret.re = z.re - t.re;
	ret.im = z.im - t.im;
	return (ret);
}

double	distance(t_cpx z1, t_cpx z2)
{
	t_cpx	s;

	s.re = z1.re - z2.re;
	s.im = z1.im - z2.im;
	return (MODULE(s));
}

int		newton_recursive(t_cpx z, int nb_it, t_roots r)
{
	if (nb_it <= 0)
	{
		if (distance(z, r.r1) < distance(z, r.r2) &&
				distance(z, r.r1) < distance(z, r.r3))
			return (1);
		else if (distance(z, r.r2) < distance(z, r.r1) &&
				distance(z, r.r2) < distance(z, r.r3))
			return (2);
		else
			return (3);
	}
	return (newton_recursive(itere_de_newton(z), nb_it - 1, r));
}

void	draw_newton(t_env *e)
{
	int		x;
	int		y;
	t_cpx	z0;
	int		ret;

	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			z0.re = x * e->pixel_size + e->re_min;
			z0.im = y * e->pixel_size + e->im_min;
			if ((ret = newton_recursive(z0, e->nb_it, e->newton_roots)))
				ft_putpixel(x, y, e, ret);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
