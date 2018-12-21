/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:11:16 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/04 20:11:19 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zero(t_frac *fr)
{
	fr->nr = 0;
	fr->ni = 0;
	fr->or = 0;
	fr->oi = 0;
}

static int	man(t_input *in, t_frac *fr, int x, int y)
{
	double cardio;

	fr->cr = 1.5 * (x - (W_W >> 1)) / (0.5 * in->zoom * W_W) + in->posx;
	fr->ci = (y - (W_H >> 1)) / (0.5 * in->zoom * W_H) + in->posy;
	cardio = sqrt((fr->cr - 0.25) * (fr->cr - 0.25) + fr->ci * fr->ci);
	if (fr->cr > (cardio - 2 * cardio * cardio + 0.25)
		|| (fr->cr + 1) * (fr->cr + 1) + fr->ci * fr->ci > 0.0625)
	{
		zero(fr);
		fr->eth = -1;
		while (in->shape(fr->nr, fr->ni) && ++fr->eth < in->meth)
		{
			fr->or = fr->nr;
			fr->oi = fr->ni;
			fr->nr = fr->or * fr->or - fr->oi * fr->oi + fr->cr;
			fr->ni = 2 * fr->or * fr->oi + fr->ci;
			if (fr->or == fr->nr && fr->oi == fr->ni)
				fr->eth = in->meth;
		}
		if (fr->eth < in->meth && in->spectrum)
			return (ft_rainbow((fr->eth << 4), in->color));
		else if (fr->eth < in->meth)
			return (ft_rainbow((fr->eth << 4) % 256, in->color));
	}
	return (0);
}

void		*mandelbrot(void *p)
{
	t_thread	*th;
	int			y;
	int			x;

	th = p;
	y = th->miny;
	while (y < th->maxy)
	{
		x = -1;
		while (++x < W_W)
		{
			th->img->addr[x + (y << 10)] = man(th->in, th->fr, x, y);
		}
		y++;
	}
	return (NULL);
}
