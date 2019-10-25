/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 23:11:35 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 13:45:33 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"
#include "../../minilibx_macos/mlx.h"
#include "../../libft/libft.h"
#include <pthread.h>

void	refresh(t_e *e)
{
	int			k;
	pthread_t	t[THREADS];
	t_e			info[THREADS];

	k = -1;
	ft_memset(t, '\0', sizeof(pthread_t) * THREADS);
	while (++k < THREADS)
	{
		info[k] = *e;
		info[k].x_begin = (SIZEX / THREADS) * k - 1;
		info[k].x_max = (SIZEX / THREADS) * (k + 1) + 1;
		pthread_create(t + k, NULL, (void *(*)(void *))e->fract, info + k);
	}
	while (k--)
		pthread_join(t[k], NULL);
	mlx_clear_window(e->m->mlx, e->m->win);
	mlx_put_image_to_window(e->m->mlx, e->m->win, e->m->img, 0, 0);
}
