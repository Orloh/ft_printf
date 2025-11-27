/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 01:14:03 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/27 02:29:04 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	uintptr_t	ptr_addr;
	int			count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	count = ft_print_str("0x");
	ptr_addr = (uintptr_t)ptr;
	count += ft_print_hex(ptr_addr, 1);
	return (count);
}
