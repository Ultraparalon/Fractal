/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:04:06 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 10:12:06 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		available_set(void)
{
	ft_putendl("available set:\n\
		mandelbrot\n\
		julia\n\
		vessel\n\
		arachnid\n\
		thorn\n\
		blur\n\
		trinity\n\
		alien\n");
}

static void	multifractal(char **fractol)
{
	char *liberator;
	char *sys;

	liberator = ft_strdup("./fractol ");
	sys = ft_strjoin(liberator, *fractol);
	free(liberator);
	liberator = sys;
	sys = ft_strjoin(sys, " & ");
	free(liberator);
	liberator = sys;
	sys = ft_strjoin(sys, "./fractol ");
	free(liberator);
	liberator = sys;
	sys = ft_strjoin(sys, *(fractol + 1));
	system(sys);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		wizard(argv[1]);
	else if (argc == 3)
		multifractal(&argv[1]);
	else
	{
		ft_putendl("usage: fractol \"set\"");
		available_set();
	}
	return (0);
}
