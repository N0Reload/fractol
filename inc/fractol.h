/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:20:19 by lmunoz-q          #+#    #+#             */
/*   Updated: 2018/04/26 10:52:26 by lmunoz-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZEX 1300
# define SIZEY 1300
# define THREADS 16
# define KEYPRESS 2
# define KEYRELEASE 3
# define MOTIONNOTIFY 6
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define POINTERMOTIONMASK (1L<<6)
# define BLANK 0xffffff

typedef enum		e_f
{
	MANDELBROT,
	SHIP,
	JULIA,
	FISH,
	SEA_LION
}					t_f;

typedef struct		s_c
{
	int				r;
	int				g;
	int				b;
}					t_c;

typedef struct		s_cplx
{
	double			r;
	double			i;
}					t_cplx;

typedef struct		s_v
{
	double			ulx;
	double			uly;
	double			drx;
	double			dry;
	double			ptx;
	double			pty;
}					t_v;

typedef struct		s_m
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bbp;
	int				sizeline;
	int				endn;
	int				size;
}					t_m;

typedef struct		s_e
{
	int				x_begin;
	int				x_max;
	int				imax;
	int				i;
	double			click;
	double			zoom;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			cr;
	double			ci;
	int				*timg;
	void			*(*fract)(struct s_e*);
	int				type;
	int				xj;
	int				yj;
	int				boule;
	t_m				*m;
	t_c				*c;
}					t_e;

void				*mandelbrot(t_e *env);
void				*sea_lion(t_e *env);
void				*burningship(t_e *env);
void				*julia(t_e *env);
void				*fish(t_e *env);
void				fractale(t_e *env);
t_e					*init_mandelbrot(t_e *env);
t_e					*init_ship(t_e *env);
t_e					*init_julia(t_e *env);
t_e					*init_fish(t_e *env);
t_e					*init_sea_lion(t_e *env);
t_cplx				gratio(t_cplx up_left, t_cplx down_right, t_cplx point);
t_cplx				appratio(t_cplx up_left, t_cplx down_right, t_cplx point);
void				refresh(t_e *env);
int					mouse_hook(int button, int x, int y, t_e *env);
int					key_hook(int keycode, t_e *e);
int					lock_hook(int keycode, t_e *e);
int					name(char *s);
int					color(t_e *e);
int					motion(int x, int y, t_e *e);
int					boule(t_e *e);

#endif
