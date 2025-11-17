/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:35:32 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/16 22:45:30 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	int		count;

	count = ft_strlen(s) + 1;
	tmp = (char *)ft_calloc(count, sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s, count);
	return (tmp);
}
