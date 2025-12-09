/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:01:45 by orhernan          #+#    #+#             */
/*   Updated: 2025/12/09 19:01:49 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	str[] = "%c\n";
	int original = printf(str, 0);
	printf("original: %i\n", original);
	
	int mine = ft_printf(str, 0);
	printf("mine: %i\n", mine);

	return (0);
}
