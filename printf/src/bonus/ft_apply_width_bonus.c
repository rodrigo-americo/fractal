/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:43:39 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 12:42:14 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_width(char *content, int width, int left_align)
{
	int		len;
	char	*result;

	if (!content)
		return (NULL);
	len = ft_strlen(content);
	if (width <= len)
		return (content);
	result = malloc(width + 1);
	if (!result)
		return (NULL);
	if (left_align)
	{
		ft_strcpy(result, content);
		ft_memset(result + len, ' ', width - len);
	}
	else
	{
		ft_memset(result, ' ', width - len);
		ft_strcpy(result + (width - len), content);
	}
	result[width] = '\0';
	free(content);
	return (result);
}
