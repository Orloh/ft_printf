/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:11:02 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/17 13:45:58 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*original;
	size_t	str_len;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(str_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	original = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (original);
}
