/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:54:51 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 13:16:43 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strjoin_free( char *prefix, char *suffix)
{
	char	*result;

	result = ft_strjoin(prefix, suffix);
	free(suffix);
	free(prefix);
	return (result);
}
