/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:09:20 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 12:49:10 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../inc/fractol.h"
#include "../libft/libft.h"

static t_e	mlx_launcher(t_e e, char *s)
{
	e.m->mlx = mlx_init();
	e.m->win = mlx_new_window(e.m->mlx, SIZEX, SIZEY, s);
	e.m->img = mlx_new_image(e.m->mlx, SIZEX, SIZEY);
	e.timg = (int *)mlx_get_data_addr(e.m->img, &(e.m->bbp), &(e.m->size),
		&(e.m->endn));
	return (e);
}

static void	usage(char *av)
{
	ft_putstr("usage: ");
	ft_putstr(av);
	ft_putstr(" [mandelbrot | julia | burningship | fish | sea_lion]\n");
}

int			main(int ac, char **av)
{
	t_e		e;
	t_m		m;
	t_c		c;

	ft_bzero(&e, sizeof(e));
	if (ac == 2 && (e.type = name(av[1])) != -1)
	{
		e.m = &m;
		e.c = &c;
		e = mlx_launcher(e, av[1]);
		fractale(&e);
		mlx_hook(e.m->win, KEYPRESS, KEYPRESSMASK, lock_hook, &e);
		mlx_hook(e.m->win, MOTIONNOTIFY, POINTERMOTIONMASK, motion, &e);
		mlx_key_hook(e.m->win, key_hook, &e);
		mlx_mouse_hook(e.m->win, mouse_hook, &e);
		mlx_loop(e.m->mlx);
	}
	else
		usage(av[0]);
	return (0);
}
