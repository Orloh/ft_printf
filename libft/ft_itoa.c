/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:25:44 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/19 23:54:14 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		int_len;

	nbr = n;
	int_len = get_int_len(nbr);
	str = ft_calloc(int_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
	{
		str[0] = '0';
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		str[int_len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		int_len--;
	}
	return (str);
}
