/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:02:32 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 11:52:59 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	fractale(t_e *e)
{
	if (e->type == MANDELBROT)
		init_mandelbrot(e);
	else if (e->type == SHIP)
		init_ship(e);
	else if (e->type == JULIA)
		init_julia(e);
	else if (e->type == FISH)
		init_fish(e);
	else if (e->type == SEA_LION)
		init_sea_lion(e);
	refresh(e);
}
