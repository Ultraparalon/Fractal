/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:36:23 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 09:38:53 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

# define W_W 1024
# define W_H 768

typedef struct	s_frac
{
	int			eth;
	double		cr;
	double		ci;
	double		nr;
	double		ni;
	double		or;
	double		oi;
}				t_frac;

typedef struct	s_img
{
	int			bit_per_pix;
	int			size_line;
	int			endian;
	int			*addr;
	void		*img;
}				t_img;

typedef struct	s_input
{
	int			isdown;
	int			morph;
	int			help;
	int			meth;
	int			color;
	int			spectrum;
	double		zoom;
	double		posx;
	double		posy;
	double		real;
	double		imag;
	int			(*shape)(double, double);
	void		*(*fractol)(void *);
}				t_input;

typedef struct	s_thread
{
	int			miny;
	int			maxy;
	t_input		*in;
	t_img		*img;
	t_frac		*fr;
	pthread_t	thread;
}				t_thread;

typedef struct	s_map
{
	void		*mlx;
	void		*window;
	t_thread	**thread;
	t_input		*in;
	t_img		*img;
}				t_map;

int				ft_loop(t_map *map);
void			process(t_map *map);
void			available_set(void);
void			*mandelbrot(void *p);
void			*julia(void *p);
void			*vessel(void *p);
void			*arachnid(void *p);
void			*thorn(void *p);
void			*alien(void *p);
void			*blur(void *p);
void			*trinity(void *p);
int				wave(double real, double image);
int				party(double real, double image);
int				leaf(double real, double image);
int				petal1(double real, double image);
int				petal2(double real, double image);
int				ft_rainbow(int morph, int base_clr);
void			wizard(char *file_name);
void			rapid_boost(t_map *map);
int				deal_key(int key, t_input *in);
int				key_rep(int key, t_input *in);
int				hook_mousedown(int button, int x, int y, t_input *in);
int				hook_mouseup(int button, int x, int y, t_input *in);
int				mouse_move(int x, int y, t_input *in);

#endif
