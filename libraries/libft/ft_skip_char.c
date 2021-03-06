/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:16:40 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/28 18:23:32 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*ft_skip_char(char const *str, char c)
{
	while (*str == c)
		str++;
	return (str);
}
