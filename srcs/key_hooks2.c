/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:07:33 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 15:11:39 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_pressed2(int kc, t_env *e)
{
	if (kc == KEY_ESC)
		exit(1);
	if (kc == KEY_PLUS || kc == KEY_MOINS)
		e->nb_it2 += kc == KEY_PLUS ? 5 : -5;
	if (kc == LEFT || kc == RIGHT)
	{
		e->re_min2 += kc == LEFT ? e->pixel_size2 * 50 : e->pixel_size2 * (-50);
		e->re_max2 += kc == LEFT ? e->pixel_size2 * 50 : e->pixel_size2 * (-50);
	}
	if (kc == UP || kc == DOWN)
	{
		e->im_min2 -= kc == DOWN ? e->pixel_size2 * 50 : e->pixel_size2 * (-50);
		e->im_max2 -= kc == DOWN ? e->pixel_size2 * 50 : e->pixel_size2 * (-50);
	}
	clear_image(&e->img2_address);
	mlx_clear_window(e->mlx, e->win2);
	e->draw_fract2(e);
	return (1);
}
