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
#define LOWHEXBASE "0123456789abcdef"
#define MAX_DIGITS 65

int	ft_parse_specifier(const char **format, va_list ap)
{
	int	count;

	count = 0;
	/*Specifiers cspdiuxX%*/
	if (**format == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (**format == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (**format == 'p')
		count += ft_print_ptr(va_arg(ap, void *));
	else if (**format == '%')
		count += ft_print_char('\%');
	(*format)++;
	return (count);
}

int	ft_print_char(int c) 
{
	ft_putchar_fd((char)c, STDOUT_FILENO);
	return (1);
}

int	ft_print_str(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
}

int	ft_base_check(char *base)
{
	int	i;
	int 	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || !ft_isprint(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_putunbr_base_fd(uintmax_t nbr, const char *base, int fd, int is_negative)
{
	char		buffer[MAX_DIGITS];
	int		base_len;
	int		count;
	int		i;

	i = 0;
	count = 0;
	base_len = ft_base_check((char *)base);
	if (is_negative)
	{
		ft_putchar_fd('-', fd);
		count++;
	}
	if (nbr == 0)
		return (ft_putchar_fd(base[0], fd), count++);
	while (nbr > 0)
	{
		buffer[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	while (i > 0)
	{
		ft_putchar_fd(buffer[i--], fd);
		count++;
	}
	return (count);
}

int	ft_putnbr_base_fd(intmax_t nbr, const char *base, int fd)
{
	if (nbr < 0)
	{
		if (nbr == INTMAX_MIN)
			return (ft_putunbr_base_fd((uintmax_t)INTMAX_MAX + 1, base, fd, 1));
		return (ft_putunbr_base_fd((uintmax_t)-nbr, base, fd, 1));
	}
	return ft_putunbr_base_fd((uintmax_t)nbr, base, fd, 0);
}

int	ft_print_hex(uintmax_t nbr)
{
	int	count;

	count = ft_print_str("0x");
	count += ft_putnbr_base_fd(nbr, LOWHEXBASE, STDOUT_FILENO);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	uintptr_t	ptr_addr;
	int		count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	ptr_addr = (uintptr_t)ptr;
	count = ft_print_hex(ptr_addr);
	ft_print_char('\n');
	return (count);
}
