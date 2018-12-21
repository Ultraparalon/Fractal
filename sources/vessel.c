/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vessel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:03:11 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/10 20:03:12 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ves(t_input *in, t_frac *fr, int x, int y)
{
	fr->cr = 1.5 * (x - (512)) / (in->zoom * 512) + in->posx;
	fr->ci = (y - (384)) / (0.5 * in->zoom * W_H) + in->posy;
	fr->eth = 0;
	fr->nr = 0;
	fr->ni = 0;
	while (fr->eth < in->meth)
	{
		fr->eth++;
		fr->or = fabs(fr->nr);
		fr->oi = fabs(fr->ni);
		fr->nr = fr->or * fr->or - fr->oi * fr->oi + fr->cr;
		fr->ni = 2 * fr->or * fr->oi + fr->ci;
		if (!in->shape(fr->nr, fr->ni))
			break ;
	}
	if (fr->eth < in->meth && in->spectrum)
		return (ft_rainbow((fr->eth << 4), in->color));
	else if (fr->eth < in->meth)
		return (ft_rainbow((fr->eth << 4) % 256, in->color));
	return (0);
}

void		*vessel(void *p)
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
			th->img->addr[x + (y << 10)] = ves(th->in, th->fr, x, y);
		}
		y++;
	}
	return (NULL);
}
