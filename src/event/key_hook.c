/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 23:43:00 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 11:55:15 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"
#include "../../minilibx_macos/mlx.h"
#include <stdlib.h>

void	put_man(t_e *e)
{
	fractale(e);
	mlx_string_put(e->m->mlx, e->m->win, 20, 10, BLANK, "<- : left");
	mlx_string_put(e->m->mlx, e->m->win, 20, 30, BLANK, "-> : right");
	mlx_string_put(e->m->mlx, e->m->win, 20, 50, BLANK, "^ : up");
	mlx_string_put(e->m->mlx, e->m->win, 20, 70, BLANK, "v : down");
	mlx_string_put(e->m->mlx, e->m->win, 20, 90, BLANK, "+ : iterations++");
	mlx_string_put(e->m->mlx, e->m->win, 20, 110, BLANK, "- : iterations--");
	mlx_string_put(e->m->mlx, e->m->win, 20, 130, BLANK, "z : 2000 iterations");
	mlx_string_put(e->m->mlx, e->m->win, 20, 150, BLANK, "x : 50 iterations");
	mlx_string_put(e->m->mlx, e->m->win, 20, 170, BLANK, "q / esc : quit");
	mlx_string_put(e->m->mlx, e->m->win, 20, 190, BLANK, "r : clear + man");
	mlx_string_put(e->m->mlx, e->m->win, 1100, 1200, BLANK, "lclick : +zoom");
	mlx_string_put(e->m->mlx, e->m->win, 1100, 1220, BLANK, "rclick : -zoom");
	mlx_string_put(e->m->mlx, e->m->win, 1100, 1240, BLANK, "c : random color");
}

void	put_fractal(t_e *e, int keycode)
{
	if (keycode == 83)
		init_mandelbrot(e);
	else if (keycode == 84)
		init_julia(e);
	else if (keycode == 85)
		init_ship(e);
	else if (keycode == 86)
		init_fish(e);
	else
		init_sea_lion(e);
	refresh(e);
}

int		key_hook(int keycode, t_e *e)
{
	if (keycode == 53 || keycode == 12)
		exit(0);
	else if (keycode == 6 || keycode == 7)
	{
		if (keycode == 6)
			e->imax = 2000;
		else if (keycode == 7)
			e->imax = 50;
		refresh(e);
	}
	else if (keycode == 15)
		put_man(e);
	else if (keycode >= 83 && keycode <= 87)
		put_fractal(e, keycode);
	else if (keycode == 49)
		e->boule = e->boule == 1 ? 0 : 1;
	return (0);
}
