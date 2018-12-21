/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:02:56 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/11 14:03:00 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	pin(t_input *in, t_frac *fr, int x, int y)
{
	fr->nr = (x - (W_W >> 1)) / (0.5 * in->zoom * W_W) + in->posx;
	fr->ni = (y - (W_H >> 1)) / (0.5 * in->zoom * W_H) + in->posy;
	while (1)
	{
		fr->or = fr->nr;
		fr->oi = fr->ni;
		fr->nr = fr->or * (fr->or * fr->or - 3 * fr->oi * fr->oi) + fr->cr;
		fr->ni = fr->oi * (3 * fr->or * fr->or - fr->oi * fr->oi) + fr->ci;
		if (fabs(fr->nr) > 10 || fabs(fr->ni) > 10
			|| fr->nr * fr->nr + fr->ni * fr->ni > 100)
			break ;
	}
	if (fabs(fr->nr) < 10 || fabs(fr->ni) < 10)
		return (in->color);
	return (0xFFFFFF);
}

void		*thorn(void *p)
{
	t_thread	*th;
	int			y;
	int			x;

	th = p;
	th->fr->cr = 0.5;
	th->fr->ci = 0;
	y = th->miny;
	while (y < th->maxy)
	{
		x = -1;
		while (++x < W_W)
		{
			th->img->addr[x + (y << 10)] = pin(th->in, th->fr, x, y);
		}
		y++;
	}
	return (NULL);
}
