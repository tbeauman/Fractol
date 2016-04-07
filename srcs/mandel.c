/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:51:37 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 12:58:25 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putpixel(int x, int y, t_env *e, int index)
{
	int		*keepitreal;

	if (x + y * 400 > 600 * 400 || x > 599 || y > 399 || x < 0 || y < 0)
		return ;
	keepitreal = (int*)e->img_address;
	keepitreal[x + y * 600] = e->palette(index, e);
	e->img_address = (char*)keepitreal;
}

void	ft_putpixel2(int x, int y, t_env *e, int index)
{
	int		*keepitreal;

	if (x + y * 400 > 600 * 400 || x > 599 || y > 399 || x < 0 || y < 0)
		return ;
	keepitreal = (int*)e->img2_address;
	keepitreal[x + y * 600] = palette_4(index, e);
	e->img2_address = (char*)keepitreal;
}

int		is_escaping(t_cpx z, t_cpx c, int nb_it, t_env *e)
{
	if (MODULE(z) > 2 || nb_it <= 0)
		return (e->nb_it - nb_it);
	z = mandelbrot_rec(z, c, e);
	return (is_escaping(z, c, nb_it - 1, e));
}

void	draw_mandel(t_env *e)
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
			if ((index = is_escaping(z0, c, e->nb_it, e)) < e->nb_it && index)
				ft_putpixel(x, y, e, index);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
