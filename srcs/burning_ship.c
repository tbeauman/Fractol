/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:16:46 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 12:58:19 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cpx	burning_ship_rec(t_cpx z, t_cpx c, t_env *e)
{
	t_cpx	ret;
	t_cpx	z_2;
	int		cpt;

	cpt = 1;
	z_2.re = ABS(z.re);
	z_2.im = ABS(z.im);
	while (cpt++ < ABS(e->puissance))
	{
		z.re = ABS(z.re);
		z.im = ABS(z.im);
		z_2 = mult(z, z_2);
	}
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

int		is_escaping2(t_cpx z, t_cpx c, int nb_it, t_env *e)
{
	if (MODULE(z) > 2 || nb_it <= 0)
		return (e->nb_it - nb_it);
	z = burning_ship_rec(z, c, e);
	return (is_escaping2(z, c, nb_it - 1, e));
}

int		is_escapingjul2(t_cpx z, t_cpx c, int nb_it, t_env *e)
{
	if (MODULE(z) > 2 || nb_it <= 0)
		return (nb_it);
	z = burning_ship_rec(z, c, e);
	return (is_escapingjul2(z, c, nb_it - 1, e));
}

void	draw_burning_ship(t_env *e)
{
	int		x;
	int		y;
	t_cpx	c;
	int		index;
	t_cpx	z0;

	z0.re = 0;
	z0.im = 0;
	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			c.re = x * e->pixel_size + e->re_min;
			c.im = y * e->pixel_size + e->im_min;
			if ((index = is_escaping2(z0, c, e->nb_it, e)))
				ft_putpixel(x, y, e, index);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
