/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_parse_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:53:52 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/19 23:44:11 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	setUp(void) {}
void	tearDown(void) {}

void	test_with_args_and_ptr_move(int expected_count, const char *format, ...)
{
	const char *fmt = format;

	va_list		ap;
	va_start(ap, format);
	int result = ft_parse_specifier(&fmt, ap);
	va_end(ap);
	
	TEST_ASSERT_EQUAL_INT(expected_count, result);
	TEST_ASSERT_EQUAL_PTR(format + 1, fmt);
}

void	test_ft_parse_specifier_char(void)
{
	test_with_args_and_ptr_move(1, "c", 'A');
	test_with_args_and_ptr_move(1, "c", '\0');
	test_with_args_and_ptr_move(1, "c", ' ');
	test_with_args_and_ptr_move(1, "c", 127);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_parse_specifier_char);
	return UNITY_END();
}
