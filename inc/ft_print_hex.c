/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:54:35 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/27 01:19:31 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(uintmax_t nbr)
{
	int	count;

	count = ft_print_str("0x");
	count += ft_putunbr_base_fd(nbr, LOWHEXBASE, STDOUT_FILENO, 0);
	return (count);
}
