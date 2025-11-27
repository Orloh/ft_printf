/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:19:48 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/27 02:29:01 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_specifier(const char **format, va_list ap)
{
	int	count;

	count = 0;
	if (**format == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (**format == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (**format == 'p')
		count += ft_print_ptr(va_arg(ap, void *));
	else if (**format == 'd' || **format == 'i')
		count += ft_print_int(va_arg(ap, int));
	else if (**format == 'u')
		count += ft_print_int(va_arg(ap, unsigned int));
	else if (**format == 'x')
		count += ft_print_hex(va_arg(ap, unsigned int), 1);
	else if (**format == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), 0);
	else if (**format == '%')
		count += ft_print_char('%');
	(*format)++;
	return (count);
}


