/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:08:32 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 12:13:56 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"
#include <stdlib.h>

static void	random_color(t_e *e)
{
	e->c->r = random() % 255;
	e->c->g = random() % 255;
	e->c->b = random() % 255;
}

static void	move(t_e *e, int keycode, double tmp)
{
	if (keycode == 124)
	{
		tmp = (e->x2 - e->x1) / 10;
		e->x1 += tmp;
		e->x2 += tmp;
	}
	else if (keycode == 125)
	{
		tmp = (e->y2 - e->y1) / 10;
		e->y1 += tmp;
		e->y2 += tmp;
	}
	else if (keycode == 126)
	{
		tmp = (e->y2 - e->y1) / 10;
		e->y1 -= tmp;
		e->y2 -= tmp;
	}
	else
	{
		tmp = (e->x2 - e->x1) / 10;
		e->x1 -= tmp;
		e->x2 -= tmp;
	}
}

int			lock_hook(int keycode, t_e *e)
{
	double tmp;

	tmp = 0;
	if (keycode == 8)
		random_color(e);
	else if (keycode == 69 || keycode == 78)
		e->imax += keycode == 69 ? 1 : -1;
	else if (keycode >= 123 && keycode <= 126)
		move(e, keycode, tmp);
	refresh(e);
	return (0);
}
