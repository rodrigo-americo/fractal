/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags_hex_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:37:18 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 17:01:08 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_apply_flags_hex(char *str, t_flags *flags, int c, char *prefix)
{
	char	*real_prefix;
	char	*result;

	str = ft_apply_int_precision(str, flags->precision);
	if (flags->hash && c != 0)
		real_prefix = ft_strdup(prefix);
	else
		real_prefix = ft_strdup("");
	if (flags->zero && !flags->minus && flags->precision == -1)
	{
		result = ft_zero_pad_prefixed(str, real_prefix, flags->width);
		return (result);
	}
	result = ft_strjoin(real_prefix, str);
	free(real_prefix);
	free(str);
	result = ft_apply_width(result, flags->width, flags->minus);
	return (result);
}
