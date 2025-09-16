/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_sign_flag_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:00:11 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 12:53:21 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_apply_sign_flag(char *str, t_flags *flags)
{
	char	*new;

	if (!str)
		return (NULL);
	if (flags->plus && str[0] != '-')
	{
		new = malloc(ft_strlen(str) + 2);
		if (!new)
			return (str);
		new[0] = '+';
		ft_strcpy(&new[1], str);
		free(str);
		return (new);
	}
	if (flags->space && str[0] != '-')
	{
		new = malloc(ft_strlen(str) + 2);
		if (!new)
			return (str);
		new[0] = ' ';
		ft_strcpy(&new[1], str);
		free(str);
		return (new);
	}
	return (str);
}
