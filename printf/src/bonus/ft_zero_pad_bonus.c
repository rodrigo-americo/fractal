/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_pad_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:21:20 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 12:57:58 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_zero_pad(char *str, int width, int is_signed)
{
	int		padding;
	char	*res;

	if (!str)
		return (NULL);
	if (width <= (int)ft_strlen(str))
		return (str);
	padding = width - ft_strlen(str);
	res = malloc(width + 1);
	if (!res)
		return (NULL);
	if (is_signed && (str[0] == '-' || str[0] == '+'))
	{
		res[0] = str[0];
		ft_memset(res + 1, '0', padding);
		ft_strcpy(res + 1 + padding, str + 1);
	}
	else
	{
		ft_memset(res, '0', padding);
		ft_strcpy(res + padding, str);
	}
	res[width] = '\0';
	free(str);
	return (res);
}
