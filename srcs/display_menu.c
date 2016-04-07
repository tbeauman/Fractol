/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:00:54 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 11:59:15 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	couleur_cafe(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 5, 240,
			0x00ffffff, "Pour les trois premieres fractales, appuyez sur O/P");
	mlx_string_put(e->mlx, e->win, 5, 260,
			0x00ffffff, "pour diminuer/augmenter l'exponant de l'iteration");
	mlx_string_put(e->mlx, e->win, 5, 280,
			0x00ffffff, "+/- pour augmenter/diminuer le nombre d'iterations");
	mlx_string_put(e->mlx, e->win, 5, 320,
			0x00ffffff, "Zoomez/Dezoomez avec le scroll de la souris");
	mlx_string_put(e->mlx, e->win, 5, 360,
			0x00ffffff, "Pour revoir le menu des commandes:");
	mlx_string_put(e->mlx, e->win, 10, 380,
			0x00ffffff, "-Appuyez sur la touche Tab");
	mlx_string_put(e->mlx, e->win, 5, 175, 0x00ffffff,
			"-S pour afficher Julia dans une nouvelle fenetre");
}

void	display_menu(t_env *e)
{
	e->ens = 0;
	mlx_string_put(e->mlx, e->win, 50, 10,
			0x00ba54fc, "Bienvenue dans mon explorateur de fractales");
	mlx_string_put(e->mlx, e->win, 5, 50,
			0x00ffffff, "Pour changer la palette de couleur:");
	mlx_string_put(e->mlx, e->win, 5, 65,
			0x00ffffff, "-Touches du pave numerique 1/2/3/4");
	mlx_string_put(e->mlx, e->win, 5, 100,
			0x00ffffff, "Pour visionner un ensemble different:");
	mlx_string_put(e->mlx, e->win, 5, 115,
			0x00ffffff, "-M pour Mandelbrot");
	mlx_string_put(e->mlx, e->win, 5, 130,
			0x00ffffff, "-J pour Julia (dispose d'un motion hook)");
	mlx_string_put(e->mlx, e->win, 5, 145,
			0x00ffffff, "-B pour Burning ship");
	mlx_string_put(e->mlx, e->win, 5, 160,
			0x00ffffff, "-N pour Newton");
	mlx_string_put(e->mlx, e->win, 5, 205,
			0x00ffffff, "Notes:");
	mlx_string_put(e->mlx, e->win, 5, 220, 0x00ffffff,
			"Vous pouvez fixer un ensemble de Julia en appuyant sur F");
	couleur_cafe(e);
}
