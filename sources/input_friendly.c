/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friendly_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:58:20 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/07 15:58:21 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			hook_mousedown(int button, int x, int y, t_input *in)
{
	(void)x;
	(void)y;
	in->isdown |= 1 << button;
	if (x >= 0 && x <= W_W && y >= 0 && y <= W_H)
	{
		if (button == 5)
		{
			in->zoom *= 1.03;
			in->posx += (x - 512) / (10 * in->zoom * 1024);
			in->posy += (y - 384) / (20 * in->zoom * 768);
		}
		else if (button == 4)
		{
			in->zoom *= 1 / 1.03;
			in->posx -= (x - 512) / (10 * in->zoom * 1024);
			in->posy -= (y - 384) / (20 * in->zoom * 768);
		}
	}
	return (0);
}

int			hook_mouseup(int button, int x, int y, t_input *in)
{
	(void)x;
	(void)y;
	in->isdown &= ~(1 << button);
	return (0);
}

int			mouse_move(int x, int y, t_input *in)
{
	if (x > 0 && x < W_W && y > 0 && y < W_H && in->morph)
	{
		in->real = -0.70176 + (0.00008 * (x - 512));
		in->imag = -0.3842 + (0.00008 * (y - 384));
	}
	if (in->isdown & (1 << 1))
	{
		in->posy -= (in->posy - (y - 384)) / (in->zoom * 2500.0f);
		in->posx -= (in->posx - (x - 512)) / (in->zoom * 2500.0f);
	}
	return (0);
}
