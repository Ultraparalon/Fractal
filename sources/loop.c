/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 13:17:05 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/12 13:17:06 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <time.h>

static void	vs_fps(t_map *map)
{
	static unsigned int frame;
	static unsigned int fps;
	static time_t		sec;

	frame++;
	mlx_string_put(map->mlx, map->window, 200, 5, 0xFFFFFF, ft_itoa(fps));
	if (sec != time(0))
	{
		sec = time(0);
		fps = frame;
		frame = 0;
	}
}

static void	help(t_map *map)
{
	mlx_string_put(map->mlx, map->window, 5, 5, 0xFFFFFF, "'Esc' exit");
	mlx_string_put(map->mlx, map->window, 5, 30, 0xFFFFFF, "mousewheel - zoom");
	mlx_string_put(map->mlx, map->window, 5, 60, 0xFFFFFF, " ^");
	mlx_string_put(map->mlx, map->window, 5, 70, 0xFFFFFF, "< > move of lmb");
	mlx_string_put(map->mlx, map->window, 5, 100, 0xFFFFFF, "'C' colour");
	mlx_string_put(map->mlx, map->window, 5, 120, 0xFFFFFF, "'X' spectrum");
	mlx_string_put(map->mlx, map->window, 5, 140, 0xFFFFFF, "'S' shape");
	mlx_string_put(map->mlx, map->window, 5, 160, 0xFFFFFF, "'R' reset");
	mlx_string_put(map->mlx, map->window,
		5, 180, 0xFFFFFF, "'F' change fractol");
	mlx_string_put(map->mlx, map->window, 5, 210, 0xFFFFFF, "additional:");
	mlx_string_put(map->mlx, map->window, 5,
		230, 0xFFFFFF, "'Space' stop morph");
	mlx_string_put(map->mlx, map->window, 5, 250, 0xFFFFFF, "'+-' itteration");
}

int			ft_loop(t_map *map)
{
	process(map);
	vs_fps(map);
	if (map->in->help)
		help(map);
	else
		mlx_string_put(map->mlx, map->window, 5, 5, 0xFFFFFF, "Press (H)elp");
	return (0);
}
