/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:49:41 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/14 10:10:35 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last;
	unsigned char	uc;

	uc = (unsigned char)c;
	last = NULL;
	while (*s != '\0')
	{
		if (*s == uc)
			last = (char *)s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (last);
}
