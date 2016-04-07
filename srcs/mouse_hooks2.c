/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handling_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:14:12 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 12:53:53 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_image(char **address)
{
	int		i;

	i = 0;
	while (i < 600 * 400 * 4)
		(*address)[i++] = 0;
}

int		motion_hook(int x, int y, t_env *e)
{
	if (e->ens != 0 && e->fix_julia == 0)
	{
		clear_image(&e->img_address);
		e->jul.re = e->re_min + x * (e->re_max - e->re_min) / 600;
		e->jul.im = e->im_min + y * (e->im_max - e->im_min) / 400;
		mlx_clear_window(e->mlx, e->win);
		e->draw_fract(e);
		if (e->win2 != NULL)
		{
			mlx_clear_window(e->mlx, e->win2);
			clear_image(&e->img2_address);
			e->draw_fract2(e);
		}
	}
	return (1);
}

void	zoom_out2(int x, int y, t_env *e)
{
	double	re_m;
	double	im_m;
	double	old[4];

	old[0] = e->re_min2;
	old[1] = e->re_max2;
	old[2] = e->im_min2;
	old[3] = e->im_max2;
	re_m = e->re_min2 + x * (e->re_max2 - e->re_min2) / 600;
	im_m = e->im_min2 + y * (e->im_max2 - e->im_min2) / 400;
	e->pixel_size2 *= 1.25;
	e->nb_it2 -= 2;
	e->re_min2 = re_m - (old[1] - old[0]) * (1.25 / 2);
	e->re_max2 = re_m + (old[1] - old[0]) * (1.25 / 2);
	e->im_min2 = im_m - (old[3] - old[2]) * (1.25 / 2);
	e->im_max2 = im_m + (old[3] - old[2]) * (1.25 / 2);
}

void	zoom_in2(int x, int y, t_env *e)
{
	double	re_m;
	double	im_m;
	double	old[4];

	re_m = e->re_min2 + x * (e->re_max2 - e->re_min2) / 600;
	im_m = e->im_min2 + y * (e->im_max2 - e->im_min2) / 400;
	old[0] = e->re_min2;
	old[1] = e->re_max2;
	old[2] = e->im_min2;
	old[3] = e->im_max2;
	e->pixel_size2 /= 1.25;
	e->nb_it2 += 2;
	e->re_min2 = re_m - (old[1] - old[0]) / 2.5;
	e->re_max2 = re_m + (old[1] - old[0]) / 2.5;
	e->im_min2 = im_m - (old[3] - old[2]) / 2.5;
	e->im_max2 = im_m + (old[3] - old[2]) / 2.5;
}

int		mouse_roll2(int bt, int x, int y, t_env *e)
{
	clear_image(&e->img2_address);
	if (bt == SCROLL_DOWN)
		zoom_out2(x, y, e);
	if (bt == SCROLL_UP)
		zoom_in2(x, y, e);
	mlx_clear_window(e->mlx, e->win2);
	e->draw_fract2(e);
	return (1);
}
