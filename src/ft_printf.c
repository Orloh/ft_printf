/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:07:43 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/11 16:02:44 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	char	*str;
	va_list	ap;

	str = (char *)format;
	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count += ft_parse_specifier(&str, ap);
		}
		else
		{	
			ft_putchar_fd(*format, 1);
			count++;
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (count);
}

int	ft_parse_specifier(char **format, va_list ap)
{
	(void) format;
	(void) ap;
	return (0);
}
