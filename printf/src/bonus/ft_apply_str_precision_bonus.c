/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_str_precision_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:40:30 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 12:41:54 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_str_precision(char *content, int precision)
{
	char	*result;
	int		len;

	if (!content)
		return (NULL);
	len = ft_strlen(content);
	if (precision < 0 || precision >= len)
		return (content);
	result = malloc(precision + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, content, precision);
	result[precision] = '\0';
	free(content);
	return (result);
}
