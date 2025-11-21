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

void	test_with_args(int expected_count, const char *spec, ...)
{
	va_list		ap;
	va_start(ap, spec);
	const char *fmt = spec;

	int result = ft_parse_specifier(&fmt, ap);

	TEST_ASSERT_EQUAL_INT(expected_count, result);

	va_end(ap);
}

void	test_ft_parse_specifier_char(void)
{
	test_with_args(1, "c", 'A');
	test_with_args(1, "c", '\0');
	test_with_args(1, "c", ' ');
	test_with_args(1, "c", 127);
}

void	test_ft_parse_specifier_moves_format_pointer(void)
{
	const char *fmt = "c";

	test_with_args(1, fmt, 'A');

	TEST_ASSERT_EQUAL_PTR(&fmt[1], fmt);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_parse_specifier_char);
	RUN_TEST(test_ft_parse_specifier_moves_format_pointer);
	return UNITY_END();
}
