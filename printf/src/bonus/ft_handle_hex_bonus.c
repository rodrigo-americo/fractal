/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:39:45 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 13:42:12 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h" 

int	ft_handle_hex(unsigned int c, char type, t_flags *flags)
{
	char	*nbr;
	char	*prefix;
	int		len;

	if (type == 'X')
	{
		nbr = ft_utoa_base(c, "0123456789ABCDEF");
		prefix = "0X";
	}
	else
	{
		nbr = ft_utoa_base(c, "0123456789abcdef");
		prefix = "0x";
	}
	if (!nbr)
		return (0);
	nbr = ft_apply_flags_hex(nbr, flags, c, prefix);
	len = ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}
