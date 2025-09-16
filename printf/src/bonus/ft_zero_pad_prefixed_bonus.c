/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_pad_prefixed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:36:44 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 13:17:08 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_zero_pad_prefixed(char *number, char *prefix, int width)
{
	int		num_len;
	int		prefix_len;
	int		padding;
	int		total_len;
	char	*result;

	if (!number || !prefix)
		return (NULL);
	num_len = ft_strlen(number);
	prefix_len = ft_strlen(prefix);
	total_len = num_len + prefix_len;
	if (width <= total_len)
		return (ft_strjoin_free(prefix, number));
	padding = width - total_len;
	result = malloc(width + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, prefix);
	ft_memset(result + prefix_len, '0', padding);
	ft_strcpy(result + prefix_len + padding, number);
	result[width] = '\0';
	free(prefix);
	free(number);
	return (result);
}
