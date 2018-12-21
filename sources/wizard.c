/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wizard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 10:53:17 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 10:53:20 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		close_button(void)
{
	exit(0);
	return (0);
}

static t_img	*new_img(t_map *map)
{
	t_img *img;

	if (!(img = ft_memalloc(sizeof(t_img))))
		ft_error("couldn't allocate memory");
	if (!(img->img = mlx_new_image(map->mlx, W_W, W_H)))
		ft_error("couldn't create image");
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bit_per_pix,
		&img->size_line, &img->endian);
	return (img);
}

static void		*check_name(char *fractol)
{
	if (!ft_strcmp(fractol, "mandelbrot"))
		return (mandelbrot);
	else if (!ft_strcmp(fractol, "julia"))
		return (julia);
	else if (!ft_strcmp(fractol, "vessel"))
		return (vessel);
	else if (!ft_strcmp(fractol, "arachnid"))
		return (arachnid);
	else if (!ft_strcmp(fractol, "thorn"))
		return (thorn);
	else if (!ft_strcmp(fractol, "trinity"))
		return (trinity);
	else if (!ft_strcmp(fractol, "blur"))
		return (blur);
	else if (!ft_strcmp(fractol, "alien"))
		return (alien);
	available_set();
	exit(0);
	return (0);
}

static t_input	*new_input(char *fractol)
{
	t_input	*i;

	if (!(i = malloc(sizeof(t_input))))
		ft_error("couldn't allocate memory");
	i->zoom = 0.7;
	i->posx = -0.5;
	i->posy = 0;
	i->real = -0.70176;
	i->imag = -0.3842;
	i->morph = 1;
	i->help = 0;
	i->meth = 100;
	i->color = 0x0000FF;
	i->spectrum = 1;
	i->shape = wave;
	i->fractol = check_name(fractol);
	return (i);
}

void			wizard(char *fractol)
{
	t_map	map;

	if (!(map.mlx = mlx_init()))
		ft_error("couldn't initializate");
	if (!(map.window = mlx_new_window(map.mlx, W_W, W_H, fractol)))
		ft_error("couldn't initializate");
	map.img = new_img(&map);
	map.in = new_input(fractol);
	rapid_boost(&map);
	mlx_key_hook(map.window, deal_key, map.in);
	mlx_hook(map.window, 17, 0, close_button, NULL);
	mlx_hook(map.window, 2, 0, key_rep, map.in);
	mlx_hook(map.window, 4, 0, hook_mousedown, map.in);
	mlx_hook(map.window, 5, 0, hook_mouseup, map.in);
	mlx_hook(map.window, 6, 0, mouse_move, map.in);
	process(&map);
	mlx_loop_hook(map.mlx, ft_loop, &map);
	mlx_loop(map.mlx);
}
