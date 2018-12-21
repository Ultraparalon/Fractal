/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:51:04 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/23 10:51:08 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset(t_input *i)
{
	i->zoom = 0.7;
	i->posx = -0.5;
	i->posy = 0;
	i->real = -0.70176;
	i->imag = -0.3842;
	i->morph = 1;
	i->help = 0;
	i->meth = 100;
	i->shape = wave;
}

static void	fractype(t_input *i)
{
	reset(i);
	if (i->fractol == julia)
		i->fractol = mandelbrot;
	else if (i->fractol == mandelbrot)
		i->fractol = vessel;
	else if (i->fractol == vessel)
		i->fractol = arachnid;
	else if (i->fractol == arachnid)
		i->fractol = thorn;
	else if (i->fractol == thorn)
		i->fractol = blur;
	else if (i->fractol == blur)
		i->fractol = trinity;
	else if (i->fractol == trinity)
		i->fractol = alien;
	else
		i->fractol = julia;
}

static void	shape(int (**shape)(double, double), void *(*f)(void *))
{
	if (*shape == wave)
		*shape = leaf;
	else if (*shape == leaf)
		*shape = petal1;
	else if (*shape == petal1)
		*shape = petal2;
	else if (*shape == petal2 && f != &mandelbrot)
		*shape = party;
	else
		*shape = wave;
}

int			deal_key(int key, t_input *in)
{
	if (key == 53)
		exit(0);
	else if (key == 8)
		in->color = ft_rainbow(255, in->color);
	else if (key == 7)
		in->spectrum = (in->spectrum) ? 0 : 1;
	else if (key == 1)
		shape(&in->shape, in->fractol);
	else if (key == 49)
		in->morph = (in->morph) ? 0 : 1;
	else if (key == 4)
		in->help = (in->help) ? 0 : 1;
	else if (key == 15)
		reset(in);
	else if (key == 3)
		fractype(in);
	return (0);
}

int			key_rep(int key, t_input *in)
{
	if (key == 24 || key == 69)
		in->meth += 5;
	if ((key == 27 || key == 78) && in->meth > 10)
		in->meth -= 5;
	if (key == 124)
		in->posx += 1 / (in->zoom * 10);
	else if (key == 123)
		in->posx -= 1 / (in->zoom * 10);
	else if (key == 125)
		in->posy += 1 / (in->zoom * 10);
	else if (key == 126)
		in->posy -= 1 / (in->zoom * 10);
	return (0);
}
