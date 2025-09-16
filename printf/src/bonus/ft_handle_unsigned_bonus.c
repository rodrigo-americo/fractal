/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:13:39 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 13:06:35 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handle_unsigned(unsigned int c, t_flags *flags)
{
	char	*nbr;
	int		len;

	nbr = ft_utoa_base(c, "0123456789");
	if (!nbr)
		return (0);
	nbr = ft_apply_int_precision(nbr, flags->precision);
	if (flags->zero && !flags->minus && flags->precision == -1)
		nbr = ft_zero_pad(nbr, flags->width, 0);
	else
		nbr = ft_apply_width(nbr, flags->width, flags->minus);
	len = ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}
