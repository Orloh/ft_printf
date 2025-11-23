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
		count += ft_print_ptr(va_arg(ap, size_t));
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

int	ft_putnbr_base_fd(intmax_t nbr, char *base, int fd)
{
	int	i;
	int	base_len;
	int	nbr_str[500];
	int	count;

	i = 0;
	count = 0;
	base_len = ft_base_check(base);
	if (base_len)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			count += write(fd,"-", 1);
		}
		while (nbr)
		{
			nbr_str[i] = nbr % base_len;
			nbr = nbr / base_len;
			i++;
		}
		while (i-- > 0)
			count += write(fd, &base[nbr_str[i]], 1);
	}
	return (count);
}

ssize_t	ft_putnbr_base_fd(intmax_t nbr, char *base, int fd)
{
	if (n < 0)
		return (ft_putunbr_base(-n, base, fd, 1);
	return ft_putunbr_base(n, base, fd, 0);
}

			int	ft_print_hex(size_t nbr)
{
	int	count;

	count = ft_print_str("0x");
	count += ft_putnbr_base_fd(nbr, LOWHEXBASE, STDOUT_FILENO);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	long long	addr;
	int		count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	addr = (long long)ptr;
	count = ft_print_hex(addr);
	ft_print_char('\n');
	return (count);
}
