/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:19:32 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 13:04:41 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	init2(t_env *e, char ens)
{
	e->nb_it = 60;
	e->pixel_size = 0.01;
	e->nb_it2 = 60;
	e->pixel_size2 = 0.01;
	e->fix_julia = 0;
	e->re_min = -3;
	e->re_max = 3;
	e->im_min = -2;
	e->im_max = 2;
	e->re_min2 = -3;
	e->re_max2 = 3;
	e->im_min2 = -2;
	e->im_max2 = 2;
	e->puissance = 2;
	e->ens = ens;
	e->jul.re = 0;
	e->jul.im = 0;
}

void	init(t_env *e, char ens)
{
	init2(e, ens);
	if (ens == 'j' && (e->palette = &palette_4))
		e->draw_fract = &draw_julia;
	else if (ens == 'b' && (e->palette = &palette_3))
		e->draw_fract = &draw_burning_ship;
	else if (ens == 'n')
	{
		e->draw_fract = &draw_newton;
		e->palette = &newton_palette;
		e->newton_roots.r1.re = 1;
		e->newton_roots.r1.im = 0;
		e->newton_roots.r2.re = -1 / 2;
		e->newton_roots.r2.im = sqrt(3) / 2;
		e->newton_roots.r3.re = -1 / 2;
		e->newton_roots.r3.im = sqrt(3) / -2;
		e->nb_it = 10;
	}
	else if (ens == 'i' && (e->palette = &palette_4))
		e->draw_fract = &draw_burning_julia;
	else
	{
		e->draw_fract = &draw_mandel;
		e->palette = &palette_1;
	}
}

int		main(int ac, char **av)
{
	t_env	e;

	e.zomfgtwins = 0;
	if (!(e.mlx = mlx_init()))
		ft_error("Connection to MLX server failed...\n");
	if (!(e.win = mlx_new_window(e.mlx, 600, 400, "fractol")))
		ft_error("Failed to open window\n");
	if (!(e.img = mlx_new_image(e.mlx, 600, 400)))
		ft_error("Failed to create image\n");
	e.img_address = mlx_get_data_addr(e.img, &e.bpp, &e.sline, &e.end);
	if (ac == 1)
		display_menu(&e);
	else
	{
		init(&e, av[1][0]);
		e.draw_fract(&e);
	}
	mlx_mouse_hook(e.win, &mouse_roll, &e);
	mlx_key_hook(e.win, &key_pressed, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, &motion_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
