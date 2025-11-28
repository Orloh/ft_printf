/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:05:15 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/27 01:21:10 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LOWHEXBASE "0123456789abcdef"
# define UPPERHEXBASE "0123456789ABCDEF"
# define DECBASE "0123456789"
# define MAX_DIGITS 65

# include <stdarg.h>
# include "libft.h"

/* Custom printf function*/
int	ft_printf(const char *format, ...);
int	ft_vprintf(const char *format, va_list ap);
int	ft_parse_specifier(const char **format, va_list ap);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *ptr);
int	ft_print_int(int nbr);
int	ft_print_uint(uintmax_t nbr);
int	ft_print_hex(uintmax_t nbr, int is_lowbase);
int	ft_putnbr_base_fd(intmax_t nbr, const char *base, int fd);
int	ft_putunbr_base_fd(uintmax_t nbr, const char *base, int fd, int is_neg);

#endif
