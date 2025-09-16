/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:55:31 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 13:25:34 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handle_pointer(void *c, t_flags *flags)
{
	unsigned long	addr;
	char			*nbr;
	int				len;

	if (!c)
	{
		nbr = ft_strdup("(nil)");
		nbr = ft_apply_width(nbr, flags->width, flags->minus);
		len = ft_putstr_fd(nbr, 1);
		free(nbr);
		return (len);
	}
	addr = (unsigned long)c;
	nbr = ft_utoa_base(addr, "0123456789abcdef");
	if (flags->zero && !flags->minus)
		nbr = ft_zero_pad_prefixed(nbr, ft_strdup("0x"), flags->width);
	else
	{
		nbr = ft_strjoin_free(ft_strdup("0x"), nbr);
		nbr = ft_apply_width(nbr, flags->width, flags->minus);
	}
	len = ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}
