/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sea_lion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:07:28 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 12:49:23 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../inc/fractol.h"
#include <pthread.h>

static void	whilenorme(t_e *e, t_cplx z, t_cplx c)
{
	double tmp;

	while (((z.r * z.r) + (z.i * z.i)) < 4 && (++e->i < e->imax))
	{
		tmp = z.r;
		z.r = -((z.r * z.r) - (z.i * z.i) + c.r);
		z.i = ABS((-2 * z.i * tmp) + c.i);
	}
}

void		*sea_lion(t_e *e)
{
	int		y;
	t_cplx	r;
	t_cplx	c;
	t_cplx	z;

	while (++e->x_begin < e->x_max - 1 && (y = -1))
	{
		while (++y < SIZEY)
		{
			r = gratio((t_cplx){0, 0}, (t_cplx){SIZEX, SIZEY},
					(t_cplx){e->x_begin, y});
			c = appratio((t_cplx){e->x1, e->y1},
					(t_cplx){e->x2, e->y2}, r);
			z.r = 0;
			z.i = 0;
			e->i = -1;
			whilenorme(e, z, c);
			if (e->i == e->imax)
				e->timg[e->x_begin + (y * SIZEX)] = 0x000000;
			else
				e->timg[e->x_begin + (y * SIZEX)] = color(e);
		}
	}
	pthread_exit(NULL);
}
