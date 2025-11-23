/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:07:43 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/19 20:41:35 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
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
	va_end(ap);
	return (count);
}
