/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alien.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:57:58 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/14 16:58:00 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	al(t_input *in, t_frac *fr, int x, int y)
{
	fr->cr = 1.5 * (x - (512)) / (in->zoom * 512) + in->posx;
	fr->ci = (y - (384)) / (0.5 * in->zoom * W_H) + in->posy;
	fr->eth = 0;
	fr->nr = 0;
	fr->ni = 0;
	while (fr->eth < in->meth)
	{
		fr->eth++;
		fr->or = (fr->nr);
		fr->oi = (fr->ni);
		fr->nr = fr->or * fr->or - fr->oi * fr->oi + fr->cr;
		fr->ni = 3 * fr->or * fr->oi + fr->ci;
		fr->cr = fr->nr + fr->cr / 2.5;
		fr->ci = fr->ni + fr->ci / 2.5;
		if (!in->shape(fr->nr, fr->ni))
			break ;
	}
	if (fr->eth < in->meth && in->spectrum)
		return (ft_rainbow((fr->eth << 4), in->color));
	else if (fr->eth < in->meth)
		return (ft_rainbow((fr->eth << 4) % 256, in->color));
	return (0);
}

void		*alien(void *p)
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
			th->img->addr[x + (y << 10)] = al(th->in, th->fr, x, y);
		}
		y++;
	}
	return (NULL);
}
