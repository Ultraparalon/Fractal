/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:01:00 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/10 20:01:03 by vkaidans         ###   ########.fr       */
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

static int	ara(t_input *in, t_frac *fr, int x, int y)
{
	fr->cr = 1.5 * (x - (512)) / (0.5 * in->zoom * 512) + in->posx;
	fr->ci = (y - (384)) / (0.25 * in->zoom * W_H) + in->posy;
	fr->eth = -1;
	zero(fr);
	while (++fr->eth < in->meth)
	{
		fr->or = fr->nr;
		fr->oi = fr->ni;
		fr->nr = fr->or * fr->or - fr->oi * fr->oi + fr->cr;
		fr->ni = 2 * fr->or * fr->oi + fr->ci;
		fr->cr = fr->nr + fr->cr / 2;
		fr->ci = fr->ni + fr->ci / 2;
		if (!in->shape(fr->nr, fr->ni))
			break ;
	}
	if (fr->eth < in->meth && in->spectrum)
		return (ft_rainbow((fr->eth << 4), in->color));
	else if (fr->eth < in->meth)
		return (ft_rainbow((fr->eth << 4) % 256, in->color));
	return (0);
}

void		*arachnid(void *p)
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
			th->img->addr[x + (y << 10)] = ara(th->in, th->fr, x, y);
		}
		y++;
	}
	return (NULL);
}
