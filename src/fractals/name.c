/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:47:48 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 03:10:48 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"
#include "../../libft/libft.h"

int		name(char *s)
{
	if ((ft_strcmp(s, "mandelbrot") == 0))
		return (MANDELBROT);
	else if (ft_strcmp(s, "burningship") == 0)
		return (SHIP);
	else if (ft_strcmp(s, "julia") == 0)
		return (JULIA);
	else if (ft_strcmp(s, "fish") == 0)
		return (FISH);
	else if (ft_strcmp(s, "sea_lion") == 0)
		return (SEA_LION);
	return (-1);
}
