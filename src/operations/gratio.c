/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gratio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:50:40 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 11:38:58 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

t_cplx	gratio(t_cplx up_left, t_cplx down_right, t_cplx point)
{
	t_cplx a;
	t_cplx b;
	t_cplx ret;

	a.r = down_right.r - up_left.r;
	a.i = down_right.i - up_left.i;
	b.r = point.r - up_left.r;
	b.i = point.i - up_left.i;
	ret.r = b.r / a.r;
	ret.i = b.i / a.i;
	return (ret);
}
