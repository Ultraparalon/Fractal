/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:43:28 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/14 17:43:30 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	blu(t_input *in, t_frac *fr, int x, int y)
{
	fr->nr = 1.5 * (x - (W_W >> 1)) / (0.5 * in->zoom * W_W) + in->posx;
	fr->ni = (y - (W_H >> 1)) / (0.5 * in->zoom * W_H) + in->posy;
	fr->eth = 0;
	while (in->shape(fr->nr, fr->ni))
	{
		fr->eth++;
		fr->or = (fr->nr);
		fr->oi = (fr->ni);
		fr->nr = 2 * (fr->or * fr->or - fr->oi * fr->oi) + fr->cr;
		fr->ni = 2 * fr->or * fr->oi + fr->ci;
	}
	if (in->spectrum)
		return (ft_rainbow((fr->eth << 2), in->color));
	return (ft_rainbow((fr->eth << 2) % 256, in->color));
}

void		*blur(void *p)
{
	t_thread	*th;
	int			y;
	int			x;

	th = p;
	th->fr->cr = -0.70176;
	th->fr->ci = -0.3942;
	y = th->miny;
	while (y < th->maxy)
	{
		x = -1;
		while (++x < W_W)
		{
			th->img->addr[x + (y << 10)] = blu(th->in, th->fr, x, y);
		}
		y++;
	}
	return (NULL);
}
