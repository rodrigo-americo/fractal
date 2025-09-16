/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_int_precision_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:47:58 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 17:08:45 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_apply_int_precision(char *content, int precision)
{
	char	*result;
	int		len;
	int		neg;
	int		padding;

	if (precision == 0 && content[0] == '0' && content[1] == '\0')
	{
		free(content);
		return (ft_strdup(""));
	}
	if (!content)
		return (NULL);
	neg = content[0] == '-';
	len = ft_strlen(content) - neg;
	if (precision <= len)
		return (content);
	padding = precision - len;
	result = malloc(precision + 1 + neg);
	if (!result)
		return (NULL);
	if (neg)
		result[0] = '-';
	ft_memset(result + neg, '0', padding);
	ft_strcpy(result + neg + padding, content + neg);
	return (free(content), result);
}
