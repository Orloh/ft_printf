/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:05:15 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/19 20:52:26 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

/* Custom printf function*/
int	ft_printf(const char *format, ...);
int	ft_parse_specifier(const char **format, va_list ap);
int	ft_print_char(int c);
int	ft_print_str(char *str);

#endif
