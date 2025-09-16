/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:05:32 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 17:19:09 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handle_string(char *c, t_flags *flags)
{
	char	*str;
	int		len;

	if (c == NULL)
	{
		if (flags->dot && flags->precision < 6)
			str = ft_strdup("");
		else
			str = ft_strdup("(null)");
	}
	else
		str = ft_strdup_safe(c);
	if (!str)
		return (0);
	if (flags->dot)
		str = ft_apply_str_precision(str, flags->precision);
	if (!str)
		return (0);
	str = ft_apply_width(str, flags->width, flags->minus);
	if (!str)
		return (0);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
