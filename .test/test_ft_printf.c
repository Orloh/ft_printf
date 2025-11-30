/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:10:01 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/28 14:40:19 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void	setUp(void) {}
void	tearDown(void) {}

typedef struct printf_result_s{
	int	ret;
	char	buffer[1024];
} printf_result_t;

static printf_result_t	capture_vprintf(int (*vprintf_func)(const char*, va_list), const char *format, ...)
{
	printf_result_t	result = {.ret = -1, .buffer = {0}};
	int		pipefd[2];
	int		old_stdout;

	fflush(stdout);
	old_stdout = dup(STDOUT_FILENO);
	if (old_stdout == -1)
		return (result);
	
	if (pipe(pipefd) == -1)
	{
		close(old_stdout);
		return (result);
	}
	
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		close(old_stdout);
		return (result);
	}
	close(pipefd[1]);
	
	va_list		args;
	va_start(args, format);
	result.ret = vprintf_func(format, args);
	va_end(args);

	fflush(stdout);

	ssize_t		bytes_read;
	bytes_read = read(pipefd[0], result.buffer, sizeof(result.buffer) - 1);
	if (bytes_read >= 0)
		result.buffer[bytes_read] = '\0';
	else
	{
		result.ret = -1;
		result.buffer[0] = '\0';
	}

	if(dup2(old_stdout, STDOUT_FILENO) == -1)
	{
		close(pipefd[0]);
		close(old_stdout);
		result.ret = -1;
		return (result);
	}
	close(old_stdout);
	close(pipefd[0]);

	return (result);
}

void	test_ft_printf_no_specifiers(void)
{
	// Basic test
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Hello world!\n");
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Hello world!\n");

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Basic test completed.");
	}
	//  Empty string test
//	{
//		printf_result_t	result1 = capture_vprintf(vprintf, "");
//		printf_result_t	result2 = capture_vprintf(ft_vprintf, "");
//
//		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
//		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
//		TEST_MESSAGE("\t[PASS] Empty string test completed.");
//	}
	//  Lone percent string test
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "%\n");
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "%\n");

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Lone % test completed.");
	}
	//  Three percent signs test
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "%%%\n");
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "%%%\n");

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Three % test completed.");
	}
	// Mix of percent and spaces test
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "%% %%%% %%\n");
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "%% %%%% %%\n");

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Mix of %% and spaces test completed.");
	}
	// Percent not followed by specifier test
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Hello % World!\n");
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Hello % World!\n");
		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Percent not followed by specifier test completed.");
	}
	// Invalid specifiers test
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "%! %K %123 %%%y\n");
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "%! %K %123 %%%y\n");
		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Invalid specifiers test completed.");
	}
	// %%% test
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "%%%");
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "%%%");
		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] %%% test completed.");
	}
}

void	test_ft_printf_char(void)
{
	const char 	*format = "Char: %c %c\n";

	printf_result_t	result1 = capture_vprintf(vprintf, format, 'c', 'S');
	printf_result_t	result2 = capture_vprintf(ft_vprintf, format, 'c', 'S');

	TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
	TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
	}

void	test_ft_printf_str(void)
{
	const char	*format = "String: %s %s\n";

	printf_result_t	result1 = capture_vprintf(vprintf, format, "Orlando", "Hernández");
		printf_result_t	result2 = capture_vprintf(ft_vprintf, format, "Orlando", "Hernández");

	TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
	TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
}

void	test_ft_printf_ptr(void)
{
	void	*ptr1 = (void *)0x1234abcd;
	void	*ptr2 = (void *)0x0;
	void	*ptr3 = (void *)0x7fff5fbff86c;
	void	*null_ptr = NULL;
	
	// Test regular ptr
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "ptr1: %p\n", ptr1);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "ptr1: %p\n", ptr1);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
	}
	// Test null ptr
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "NULL: %p\n", null_ptr);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "NULL: %p\n", null_ptr);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
	}
	// Test multiple pointers
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "ptrs: %p %p %p\n", ptr1, ptr2, ptr3);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "ptrs: %p %p %p\n", ptr1, ptr2, ptr3);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
	}
}

void	test_ft_printf_int_dec(void)
{
	int	dec1 = 0;
	int	dec2 = 2;
	int	dec3 = -9;
	int	max_int = INT_MAX;
	int	min_int = INT_MIN;
	
	// Test 0
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Decimal: %d\n", dec1);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Decimal: %d\n", dec1);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Zero test completed.");
	}
	// Test positive
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Decimal: %d\n", dec2);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Decimal: %d\n", dec2);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Positive integers test completed.");
	}
	// Test negative
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Decimal: %d\n", dec3);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Decimal: %d\n", dec3);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Negative integers test completed.");
	}
	// Test multiple decimals
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Decimals: %d %i %d\n", dec1, dec2, dec3);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Decimals: %d %i %d\n", dec1, dec2, dec3);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Multiple integers test completed.");
	}
	// Test INT_MAX
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "MAX: %d\n", max_int);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "MAX: %d\n", max_int);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] INT_MAX test completed.");
	}
	// Test INT_MIN
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "MAX: %d\n", min_int);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "MAX: %d\n", min_int);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] INT_MIN test completed.");
	}
	// Test %d and %i equivalence
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "D: %d | I: %i\n", dec2, dec2);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "D: %d | I: %i\n", dec2, dec2);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
	}
}

void	test_ft_printf_uint(void)
{
	int	u1 = 0;
	int	u2 = 42;
	int	u3 = 123456789;
	int	u_max = UINT_MAX;
	int	u_big = 4000000000U;
	
	// Test 0
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Unsigned zero: %u\n", u1);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Unsigned zero: %u\n", u1);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Unsigned zero test completed.");
	}
	// Test regular positive nums
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Number: %u\n", u2);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Number: %u\n", u2);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Regular unsigned number test completed.");
	}
	// Test medium-large number
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Big: %u\n", u3);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Big: %u\n", u3);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Medium-large unsigned test completed.");
	}
	// Test UINT_MAX
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "UINT_MAX: %u\n", u_max);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "UINT_MAX: %u\n", u_max);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] UINT_MAX test completed.");
	}
	// Test value larger than INT_MAX
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Over UINT_MAX: %u\n", u_big);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Over UINT_MAX: %u\n", u_big);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Value > UINT_MAX test completed.");
	}
	// Test multiple %u in one call
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Multi: %u %u %u %u\n", u1, u2, u3, u_max);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Multi: %u %u %u %u\n", u1, u2, u3, u_max);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Multiple unsigned test completed.");
	}
	// Mixed with signed negative integers (common mistake)
	{
		int	negative = -42;
		printf_result_t	result1 = capture_vprintf(vprintf, "Mixed: D %d | U %u\n", negative, negative);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Mixed: D %d | U %u\n", negative, negative);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Mixed signed | unsigned test completed.");
	}
}

void	test_ft_printf_hex(void)
{
	int	hex1 = 4;
	// Test hex lowbase
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Hexlow: %x\n", hex1);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Hexlow: %x\n", hex1);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Lowbase test completed.");
	}
	// Test hex upperbase
	{
		printf_result_t	result1 = capture_vprintf(vprintf, "Hexupper: %X\n", hex1);
		printf_result_t	result2 = capture_vprintf(ft_vprintf, "Hexupper: %X\n", hex1);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
		TEST_MESSAGE("\t[PASS] Upperbase test completed.");
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_printf_no_specifiers);
	RUN_TEST(test_ft_printf_char);
	RUN_TEST(test_ft_printf_str);
	RUN_TEST(test_ft_printf_ptr);
	RUN_TEST(test_ft_printf_int_dec);
	RUN_TEST(test_ft_printf_uint);
	RUN_TEST(test_ft_printf_hex);
	return UNITY_END();
}

