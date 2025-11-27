/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:54:35 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/27 02:29:08 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(uintmax_t nbr, int is_lowbase)
{
	int	count;

	if (is_lowbase)
		count = ft_putunbr_base_fd(nbr, LOWHEXBASE, STDOUT_FILENO, 0);
	else
		count = ft_putunbr_base_fd(nbr, UPPERHEXBASE, STDOUT_FILENO, 0);
	return (count);
}
