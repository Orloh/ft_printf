/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:19:48 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/19 20:52:50 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_specifier(const char **format, va_list ap)
{
	int	count;

	count = 0;
	/*Specifiers cspdiuxX%*/
	if (**format == 'c')
		count += ft_print_char(va_arg(ap, int));
	return (count);
}

int	ft_print_char(int c) 
{
	(void) c;
	return (0);
}
