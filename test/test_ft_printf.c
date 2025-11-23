/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:10:01 by orhernan          #+#    #+#             */
/*   Updated: 2025/11/19 23:44:09 by orhernan         ###   ########.fr       */
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

static printf_result_t	capture_printf(int (*printf_func)(const char*, ...), const char *format, ...)
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
	result.ret = printf_func(format, args);
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
	const char 	*format = "Hello, world!\n";

	printf_result_t	result1 = capture_printf(printf, format);
	printf_result_t	result2 = capture_printf(ft_printf, format);

	TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
	TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
}

void	test_ft_printf_char(void)
{
	const char 	*format = "Char: %c %c\n";

	printf_result_t	result1 = capture_printf(printf, format, 'c', 'S');
	printf_result_t	result2 = capture_printf(ft_printf, format, 'c', 'S');

	TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
	TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
}

void	test_ft_printf_str(void)
{
	const char	*format = "String: %s %s\n";

	printf_result_t	result1 = capture_printf(printf, format, "Orlando", "Hernández");
	printf_result_t	result2 = capture_printf(ft_printf, format, "Orlando", "Hernández");

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
		printf_result_t	result1 = capture_printf(printf, "ptr1: %p\n", ptr1);
		printf_result_t	result2 = capture_printf(ft_printf, "ptr1: %p\n", ptr1);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
	}
	// Test null ptr
	{
		printf_result_t	result1 = capture_printf(printf, "NULL: %p\n", null_ptr);
		printf_result_t	result2 = capture_printf(ft_printf, "NULL: %p\n", null_ptr);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
	}
	// Test multiple pointers
	{
		printf_result_t	result1 = capture_printf(printf, "ptrs: %p %p %p\n", ptr1, ptr2, ptr3);
		printf_result_t	result2 = capture_printf(ft_printf, "ptrs: %p %p %p\n", ptr1, ptr2, ptr3);

		TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
		TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_printf_no_specifiers);
	RUN_TEST(test_ft_printf_char);
	RUN_TEST(test_ft_printf_str);
	RUN_TEST(test_ft_printf_ptr);
	return UNITY_END();
}

