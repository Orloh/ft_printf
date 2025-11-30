/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_parse_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:53:52 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/28 13:41:50 by orhernan         ###   ########.fr       */
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

void	test_ft_parse_specifier_string(void)
{
	test_with_args_and_ptr_move(12, "s", "Hello World!");
	test_with_args_and_ptr_move(0, "s", "");
	test_with_args_and_ptr_move(1, "s", " ");
	test_with_args_and_ptr_move(19, "s", "My name is Orlando\n");
}

void	test_ft_parse_specifier_percent(void)
{
	test_with_args_and_ptr_move(1, "%", '%');
}

void	test_ft_parse_specifier_pointer(void)
{
	void	*ptr1 = (void *)0x12345678;
	void	*ptr2 = NULL;
	void	*ptr3 = &ptr1;
	int	dummy = 42;
	
	test_with_args_and_ptr_move(10, "p", ptr1);
	test_with_args_and_ptr_move(5, "p", ptr2);
	test_with_args_and_ptr_move(14, "p", ptr3);
	test_with_args_and_ptr_move(14, "p", &dummy);
}

void	test_ft_parse_specifier_integer(void)
{
	int	int1 = 1;
	int	int2 = 12345;
	int	int3 = -12345;
	
	test_with_args_and_ptr_move(1, "i", int1);
	test_with_args_and_ptr_move(5, "i", int2);
	test_with_args_and_ptr_move(6, "i", int3);
}

void	test_ft_parse_specifier_decimal(void)
{
	int	int1 = 1;
	int	int2 = 12345;
	int	int3 = -12345;
	
	test_with_args_and_ptr_move(1, "d", int1);
	test_with_args_and_ptr_move(5, "d", int2);
	test_with_args_and_ptr_move(6, "d", int3);
}
int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_parse_specifier_char);
	RUN_TEST(test_ft_parse_specifier_string);
	RUN_TEST(test_ft_parse_specifier_percent);
	RUN_TEST(test_ft_parse_specifier_pointer);
	RUN_TEST(test_ft_parse_specifier_integer);
	RUN_TEST(test_ft_parse_specifier_decimal);
	return UNITY_END();
}
