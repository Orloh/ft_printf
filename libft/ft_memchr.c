/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:48:41 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/14 12:22:16 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*ucs;

	uc = (unsigned char) c;
	ucs = (unsigned char *)s;
	while (n > 0)
	{
		if (*ucs == uc)
			return ((void *) ucs);
		ucs++;
		n--;
	}
	return (NULL);
}
