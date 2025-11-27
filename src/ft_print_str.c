/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:07:12 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/27 00:33:59 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	if (!str)
		return (ft_print_str("(null)"));
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
}
