/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:21:34 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/20 00:38:30 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	i;
	char	*res;

	s_len = ft_strlen(s);
	res = ft_calloc(s_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
