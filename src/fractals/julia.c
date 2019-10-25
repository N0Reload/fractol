/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:53:55 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 12:23:55 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"
#include "../../libft/libft.h"
#include <pthread.h>

void			*julia(t_e *e)
{
	int		y;
	double	tmp;
	t_cplx	r;
	t_cplx	z;

	while (++e->x_begin < e->x_max - 1 && (y = -1))
	{
		while (++y < SIZEY)
		{
			r = gratio((t_cplx){0, 0}, (t_cplx){SIZEX, SIZEY},
				(t_cplx){e->x_begin, y});
			z = appratio((t_cplx){e->x1, e->y1}, (t_cplx){e->x2, e->y2}, r);
			e->i = -1;
			while (((z.r * z.r) + (z.i * z.i)) < 4 && (++e->i < e->imax))
			{
				tmp = z.r;
				z.r = ((z.r * z.r) - (z.i * z.i) + e->cr);
				z.i = ((2 * z.i * tmp) + e->ci);
			}
			e->timg[e->x_begin + (y * SIZEX)] = 0x000000;
			if (e->i != e->imax)
				e->timg[e->x_begin + (y * SIZEX)] = color(e);
		}
	}
	pthread_exit(NULL);
}
