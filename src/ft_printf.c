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

int	ft_printf(const char *format)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		ft_putchar_fd(*format, 1);
		i++
	}
	return (i);
}
