/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:38:37 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 12:51:11 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct		s_cpx
{
	double			re;
	double			im;
}					t_cpx;

typedef struct		s_roots
{
	t_cpx			r1;
	t_cpx			r2;
	t_cpx			r3;
}					t_roots;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*win2;
	void			*img;
	void			*img2;
	char			*img_address;
	char			*img2_address;
	double			pixel_size;
	double			pixel_size2;
	double			re_min;
	double			re_max;
	double			im_min;
	double			im_max;
	double			re_min2;
	double			re_max2;
	double			im_min2;
	double			im_max2;
	char			ens;
	t_cpx			jul;
	t_roots			newton_roots;
	int				puissance;
	int				nb_it;
	int				nb_it2;
	int				bpp;
	int				sline;
	int				fix_julia;
	int				end;
	int				zomfgtwins;
	void			(*draw_fract)(struct s_env *);
	void			(*draw_fract2)(struct s_env *);
	int				(*palette)(int, struct s_env*);
}					t_env;

#endif
