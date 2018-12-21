/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 18:11:56 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/06 18:11:58 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	jul(t_input *in, t_frac *fr, int x, int y)
{
	fr->nr = 1.5 * (x - (W_W >> 1)) / (0.5 * in->zoom * W_W) + in->posx;
	fr->ni = (y - (W_H >> 1)) / (0.5 * in->zoom * W_H) + in->posy;
	fr->eth = 0;
	while (in->shape(fr->nr, fr->ni))
	{
		fr->eth++;
		fr->or = fr->nr;
		fr->oi = fr->ni;
		fr->nr = fr->or * fr->or - fr->oi * fr->oi + fr->cr;
		fr->ni = 2 * fr->or * fr->oi + fr->ci;
	}
	if (in->spectrum)
		return (ft_rainbow((fr->eth << 4), in->color));
	return (ft_rainbow((fr->eth << 4) % 256, in->color));
}

void		*julia(void *p)
{
	t_thread	*th;
	int			y;
	int			x;

	th = p;
	th->fr->cr = th->in->real;
	th->fr->ci = th->in->imag;
	y = th->miny;
	while (y < th->maxy)
	{
		x = -1;
		while (++x < W_W)
		{
			th->img->addr[x + (y << 10)] = jul(th->in, th->fr, x, y);
		}
		y++;
	}
	return (NULL);
}
