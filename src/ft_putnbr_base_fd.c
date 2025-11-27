/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 01:42:02 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/27 01:42:32 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_check(char *base)
{
	int		i;
	int		j;

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
	char	buffer[MAX_DIGITS];
	int		base_len;
	int		count;
	int		i;

	i = 0;
	count = 0;
	base_len = ft_base_check((char *)base);
	if (is_negative && ++count)
		ft_putchar_fd('-', fd);
	if (nbr == 0)
		return (ft_putchar_fd(base[0], fd), ++count);
	while (nbr > 0)
	{
		buffer[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	while (i > 0)
	{
		ft_putchar_fd(buffer[--i], fd);
		count++;
	}
	return (count);
}

int	ft_putnbr_base_fd(intmax_t nbr, const char *base, int fd)
{
	if (nbr < 0)
	{
		if (nbr == INT_MIN)
			return (ft_putunbr_base_fd((uintmax_t)INT_MAX + 1, base, fd, 1));
		return (ft_putunbr_base_fd((uintmax_t)(-nbr), base, fd, 1));
	}
	return (ft_putunbr_base_fd((uintmax_t)nbr, base, fd, 0));
}
