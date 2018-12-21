/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rapid_boost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:29:33 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/09 10:29:34 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_thread	*thread_init(t_map *map, int ymin, int ymax)
{
	t_frac		*fr;
	t_thread	*th;

	if (!(th = malloc(sizeof(t_thread))))
		ft_error("couldn't allocate memory");
	if (!(fr = malloc(sizeof(t_frac))))
		ft_error("couldn't allocate memory");
	th->img = map->img;
	th->in = map->in;
	th->fr = fr;
	th->miny = ymin;
	th->maxy = ymax;
	return (th);
}

void			rapid_boost(t_map *map)
{
	int			i;
	t_thread	**thread;

	i = 0;
	if (!(thread = (t_thread**)ft_memalloc(sizeof(t_thread *) * 128 + 1)))
		ft_error("couldn't allocate memory");
	while (i < 128)
	{
		thread[i] = thread_init(map, i * 6, i * 6 + 6);
		i++;
	}
	map->thread = thread;
}

void			process(t_map *map)
{
	int			i;
	t_thread	*th;

	i = 0;
	while (i < 128)
	{
		th = map->thread[i];
		pthread_create(&th->thread, NULL, map->in->fractol, th);
		pthread_join(th->thread, NULL);
		i++;
	}
	mlx_put_image_to_window(map->mlx, map->window, map->img->img, 0, 0);
}
