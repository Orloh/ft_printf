/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:10:01 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/12 13:27:22 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libftprintf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static char	output_buffer[1024];
static int	buffer_pos = 0;

void	setUp(void) {}
void	tearDown(void) {}

void	test_ft_printf_no_specifiers(void)
{
	const char 	*fomrat = "Hello, world!\n";
	int		*pipefd;
	int		ret;

	ret = ft_printf(format);

	TEST_ASSERT_EQUAL_INT((int)ft_strlen(format), ret);
	TEST_
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST();
	return UNITY_END();
}

