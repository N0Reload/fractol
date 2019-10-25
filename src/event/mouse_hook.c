/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 23:08:50 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 14:02:12 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	zoom(t_e *e, double m)
{
	e->x1 *= m;
	e->x2 *= m;
	e->y1 *= m;
	e->y2 *= m;
}

int		mouse_hook(int button, int x, int y, t_e *e)
{
	t_cplx a;
	t_cplx b;
	double m;

	if (button == 1 || button == 2 || button == 4 || button == 5)
	{
		a = gratio((t_cplx){0, 0}, (t_cplx){SIZEX, SIZEY}, (t_cplx){x, y});
		a = appratio((t_cplx){e->x1, e->y1}, (t_cplx){e->x2, e->y2}, a);
		m = e->zoom;
		if (button == 2 || button == 5)
			m = 1 / m;
		zoom(e, m);
		b = gratio((t_cplx){0, 0}, (t_cplx){SIZEX, SIZEY}, (t_cplx){x, y});
		b = appratio((t_cplx){e->x1, e->y1}, (t_cplx){e->x2, e->y2}, b);
		a.r = a.r - b.r;
		a.i = a.i - b.i;
		e->x1 += a.r;
		e->x2 += a.r;
		e->y1 += a.i;
		e->y2 += a.i;
		refresh(e);
	}
	return (0);
}
