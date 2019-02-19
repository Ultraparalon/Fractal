/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainbow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:17:35 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/20 14:17:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <limits.h>

static void	ft_power_up(unsigned char *const col, int *const mor)
{
	if ((*mor + *col) > UCHAR_MAX)
	{
		*mor -= (UCHAR_MAX - *col);
		*col = UCHAR_MAX;
	}
	else
	{
		*col += *mor;
		*mor = 0;
	}
}

static void	ft_power_down(unsigned char *const col, int *const mor)
{
	if ((*col - *mor) < 0)
	{
		*mor -= *col;
		*col = 0;
	}
	else
	{
		*col -= *mor;
		*mor = 0;
	}
}

static void	ft_colour_morph(unsigned char *const color, int mor)
{
	while (mor > 0)
	{
		if (*(color + 2) == UCHAR_MAX && *color)
			ft_power_down(color, &mor);
		else if (*(color + 2) == UCHAR_MAX && *(color + 1) < UCHAR_MAX)
			ft_power_up((color + 1), &mor);
		else if (*(color + 1) == UCHAR_MAX && *(color + 2))
			ft_power_down((color + 2), &mor);
		else if (*(color + 1) == UCHAR_MAX && *color < UCHAR_MAX)
			ft_power_up(color, &mor);
		else if (*color == UCHAR_MAX && *(color + 1))
			ft_power_down((color + 1), &mor);
		else if (*color == UCHAR_MAX && *(color + 2) < UCHAR_MAX)
			ft_power_up((color + 2), &mor);
	}
}

int			ft_rainbow(unsigned int morph, int base_clr)
{
	morph %= 1536;
	ft_colour_morph((unsigned char *)&base_clr, morph);
	return (base_clr);
}
