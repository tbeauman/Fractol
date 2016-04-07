/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:06:15 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 15:14:18 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_escapingjul(t_cpx z, t_cpx c, int nb_it, t_env *e)
{
	if (MODULE(z) > 2 || nb_it <= 0)
		return (nb_it);
	z = mandelbrot_rec(z, c, e);
	return (is_escapingjul(z, c, nb_it - 1, e));
}

void	draw_julia(t_env *e)
{
	int		x;
	int		y;
	t_cpx	z0;
	int		index;

	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			z0.re = x * e->pixel_size + e->re_min;
			z0.im = y * e->pixel_size + e->im_min;
			if ((index = is_escapingjul(z0, e->jul, e->nb_it, e)) < e->nb_it
					&& index > 0)
				ft_putpixel(x, y, e, index);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_burning_julia(t_env *e)
{
	int		x;
	int		y;
	t_cpx	z0;
	int		index;

	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			z0.re = x * e->pixel_size + e->re_min;
			z0.im = y * e->pixel_size + e->im_min;
			if ((index = is_escapingjul2(z0, e->jul, e->nb_it, e)) < e->nb_it
					&& index > 0)
				ft_putpixel(x, y, e, index);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	draw_julia2(t_env *e)
{
	int		x;
	int		y;
	t_cpx	z0;
	int		index;

	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			z0.re = x * e->pixel_size2 + e->re_min2;
			z0.im = y * e->pixel_size2 + e->im_min2;
			if ((index = is_escapingjul(z0, e->jul, e->nb_it2, e)) < e->nb_it2
					&& index > 0)
				ft_putpixel2(x, y, e, index);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win2, e->img2, 0, 0);
}

void	draw_burning_julia2(t_env *e)
{
	int		x;
	int		y;
	t_cpx	z0;
	int		index;

	x = 0;
	while (x < 600)
	{
		y = 0;
		while (y < 400)
		{
			z0.re = x * e->pixel_size2 + e->re_min2;
			z0.im = y * e->pixel_size2 + e->im_min2;
			if ((index = is_escapingjul2(z0, e->jul, e->nb_it2, e)) < e->nb_it2
					&& index > 0)
				ft_putpixel2(x, y, e, index);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win2, e->img2, 0, 0);
}
