/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:32:46 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/12 11:32:52 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	wave(double real, double image)
{
	return (real * real + image * image < 4) ? 1 : 0;
}

int	leaf(double real, double image)
{
	return (real + image < 4) ? 1 : 0;
}

int	petal1(double real, double image)
{
	image = (double)image;
	return (real * real < 4) ? 1 : 0;
}

int	petal2(double real, double image)
{
	real = (double)real;
	return (image * image < 4) ? 1 : 0;
}

int	party(double real, double image)
{
	return (image / real < 8) ? 1 : 0;
}
