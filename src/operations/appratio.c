/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appratio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:27:15 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 11:38:46 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

t_cplx	appratio(t_cplx up_left, t_cplx down_right, t_cplx gratio)
{
	t_cplx a;
	t_cplx b;
	t_cplx ret;

	a.r = down_right.r - up_left.r;
	a.i = down_right.i - up_left.i;
	b.r = a.r * gratio.r;
	b.i = a.i * gratio.i;
	ret.r = up_left.r + b.r;
	ret.i = up_left.i + b.i;
	return (ret);
}
