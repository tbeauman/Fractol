/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:24:32 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 11:32:27 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_pressed_splitted_split(int kc, t_env *e)
{
	if (kc == KEY_J && (e->draw_fract2 = &draw_julia2))
		init(e, 'j');
	if (kc == KEY_I && (e->draw_fract2 = &draw_burning_julia2))
		init(e, 'i');
	if (kc == KEY_M)
		init(e, 'm');
	if (kc == KEY_B)
		init(e, 'b');
	if (kc == KEY_N)
		init(e, 'n');
	if (kc == KEY_TAB)
		e->draw_fract = &display_menu;
	if (kc == KEY_F)
		e->fix_julia = e->fix_julia == 0 ? 1 : 0;
	return (1);
}

int		key_pressed_split(int kc, t_env *e)
{
	if (kc == KEY_1)
		e->palette = &palette_1;
	if (kc == KEY_2)
		e->palette = &palette_2;
	if (kc == KEY_3)
		e->palette = &palette_3;
	if (kc == KEY_4)
		e->palette = &palette_4;
	if (kc == KEY_6)
		e->palette = &palette_6;
	if (kc == KEY_S)
	{
		e->draw_fract2 = &draw_julia2;
		e->zomfgtwins = 1;
		if (!(e->win2 = mlx_new_window(e->mlx, 600, 400, "julia")))
			ft_error("Failed to open window\n");
		if (!(e->img2 = mlx_new_image(e->mlx, 600, 400)))
			ft_error("Failed to create image\n");
		e->img2_address =
			mlx_get_data_addr(e->img2, &e->bpp, &e->sline, &e->end);
		e->draw_fract2(e);
	}
	return (1);
}

int		key_pressed(int kc, t_env *e)
{
	key_pressed_split(kc, e);
	key_pressed_splitted_split(kc, e);
	if (kc == KEY_ESC)
		exit(1);
	if (kc == KEY_P || kc == KEY_O)
		e->puissance += kc == KEY_P ? 1 : -1;
	if (kc == KEY_PLUS || kc == KEY_MOINS)
		e->nb_it += kc == KEY_PLUS ? 5 : -5;
	if (kc == LEFT || kc == RIGHT)
	{
		e->re_min += kc == LEFT ? e->pixel_size * 50 : e->pixel_size * (-50);
		e->re_max += kc == LEFT ? e->pixel_size * 50 : e->pixel_size * (-50);
	}
	if (kc == UP || kc == DOWN)
	{
		e->im_min -= kc == DOWN ? e->pixel_size * 50 : e->pixel_size * (-50);
		e->im_max -= kc == DOWN ? e->pixel_size * 50 : e->pixel_size * (-50);
	}
	if (e->ens == 0)
		return (1);
	clear_image(&e->img_address);
	mlx_clear_window(e->mlx, e->win);
	e->draw_fract(e);
	return (1);
}
