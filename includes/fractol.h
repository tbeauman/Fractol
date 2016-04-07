/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:16:49 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 15:10:59 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "typedefs.h"
# include "libft.h"
# include "mlx.h"
# include "macoskeys.h"
# include <time.h>
# include <stdlib.h>
# define ABS(x) ((x < 0) ? -x : x)
# define MODULE(z) sqrt(z.re * z.re + z.im * z.im)

int		is_escaping(t_cpx z, t_cpx c, int nb_it, t_env *e);
int		is_escaping2(t_cpx z, t_cpx c, int nb_it, t_env *e);
int		is_escapingjul(t_cpx z, t_cpx c, int nb_it, t_env *e);
int		is_escapingjul2(t_cpx z, t_cpx c, int nb_it, t_env *e);
void	ft_putpixel(int x, int y, t_env *e, int color);
void	ft_putpixel2(int x, int y, t_env *e, int color);
t_cpx	mult(t_cpx a, t_cpx b);
t_cpx	puissance(t_cpx a, int n);
t_cpx	divise(t_cpx a, t_cpx b);
t_cpx	inverse(t_cpx a);
t_cpx	mandelbrot_rec(t_cpx z, t_cpx c, t_env *e);
void	draw_mandel(t_env *e);
void	draw_julia(t_env *e);
void	draw_julia2(t_env *e);
void	draw_burning_ship(t_env *e);
void	draw_burning_julia(t_env *e);
void	draw_burning_julia2(t_env *e);
void	draw_newton(t_env *e);
void	display_menu(t_env *e);
int		key_pressed(int kc, t_env *e);
int		key_pressed2(int kc, t_env *e);
int		mouse_roll(int bt, int x, int y, t_env *e);
int		mouse_roll2(int bt, int x, int y, t_env *e);
int		motion_hook(int x, int y, t_env *e);
void	init(t_env *e, char ens);
void	ft_error(char *msg);
void	clear_image(char **address);
int		palette_1(int index, t_env *e);
int		palette_2(int index, t_env *e);
int		palette_3(int index, t_env *e);
int		palette_4(int index, t_env *e);
int		newton_palette(int index, t_env *e);

#endif
