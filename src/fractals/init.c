/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:56:20 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 13:37:00 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

t_e	*init_mandelbrot(t_e *e)
{
	e->imax = 30;
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->zoom = 0.8;
	e->c->r = 7;
	e->c->g = 7;
	e->c->b = 0;
	e->fract = &mandelbrot;
	return (e);
}

t_e	*init_ship(t_e *e)
{
	e->imax = 30;
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->zoom = 0.8;
	e->c->r = 7;
	e->c->g = 0;
	e->c->b = 0;
	e->fract = &burningship;
	return (e);
}

t_e	*init_julia(t_e *e)
{
	e->imax = 30;
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->zoom = 0.8;
	e->cr = -0.715;
	e->ci = -0.27015;
	e->c->r = 0;
	e->c->g = 10;
	e->c->b = 10;
	e->fract = &julia;
	return (e);
}

t_e	*init_fish(t_e *e)
{
	e->imax = 30;
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->zoom = 0.8;
	e->c->r = 0;
	e->c->g = 8;
	e->c->b = 8;
	e->fract = &fish;
	return (e);
}

t_e	*init_sea_lion(t_e *e)
{
	e->imax = 30;
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2;
	e->y2 = 2;
	e->zoom = 0.8;
	e->c->r = 20;
	e->c->g = 20;
	e->c->b = 0;
	e->fract = &sea_lion;
	return (e);
}
