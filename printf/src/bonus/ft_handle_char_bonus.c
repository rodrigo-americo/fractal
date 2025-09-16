/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:42:31 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/08 14:42:53 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handle_char(int c, t_flags *flags)
{
	char			*str;
	unsigned char	ch;
	int				len;

	ch = (unsigned char)c;
	len = 1;
	if (flags->width > 1)
		len = flags->width;
	str = malloc(len);
	if (!str)
		return (0);
	ft_memset(str, ' ', len);
	if (flags->minus)
		str[0] = ch;
	else
		str[len - 1] = ch;
	write(1, str, len);
	free(str);
	return (len);
}
