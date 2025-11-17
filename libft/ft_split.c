/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:41:52 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/24 13:15:11 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(const char *s, char c)
{
	int		flag;
	int		word_count;

	word_count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			word_count++;
			flag = 1;
		}
		else if (*s == c && flag)
			flag = 0;
		s++;
	}
	return (word_count);
}

static void	*free_mem(char **s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static void	var_init(size_t *i, int *j, int *w_start)
{
	*i = 0;
	*j = 0;
	*w_start = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**str_array;
	size_t	i;
	int		w_start;
	int		j;

	str_array = ft_calloc(get_word_count(s, c) + 1, sizeof(char *));
	if (!str_array)
		return (NULL);
	var_init(&i, &j, &w_start);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && w_start == -1)
			w_start = i;
		else if ((s[i] == c || s[i] == '\0') && w_start >= 0)
		{
			str_array[j] = ft_substr(s, w_start, i - w_start);
			if (!str_array[j])
				return (free_mem(str_array, j));
			w_start = -1;
			j++;
		}
		i++;
	}
	return (str_array);
}
