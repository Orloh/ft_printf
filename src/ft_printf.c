/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:07:43 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/27 00:34:55 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = ft_vprintf(format, args);
	va_end(args);
	return (count);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int		count;

	if (!format)
		return (-1);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_parse_specifier(&format, ap);
		}
		else
		{
			count += ft_print_char(*format);
			format++;
		}
	}
	return (count);
}
