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

	//int		backup_fd;
	//backup_fd = dup(STDOUT_FILENO);
	//TEST_ASSERT_NOT_EQUAL(-1, backup_fd);

	//char		buffer1[128] = {0};
	//char		buffer2[128] = {0};
	//int 		num1, num2;
	//
	//int		pipe1[2];
	//TEST_ASSERT_EQUAL(0, pipe(pipe1));
	//TEST_ASSERT_NOT_EQUAL(-1, dup2(pipe1[1], STDOUT_FILENO));
	//close(pipe1[1]);
	//num1 = ft_printf(format);
	//fflush(stdout);
	//read(pipe1[0], buffer1, sizeof(buffer1) - 1);
	//close(pipe1[0]);
	//TEST_ASSERT_NOT_EQUAL(-1, dup2(backup_fd, STDOUT_FILENO));

	//int		pipe2[2];
	//TEST_ASSERT_EQUAL(0, pipe(pipe2));
	//TEST_ASSERT_NOT_EQUAL(-1, dup2(pipe2[1], STDOUT_FILENO));
	//close(pipe2[1]);
	//num2 = ft_printf(format);
	//fflush(stdout);
	//read(pipe2[0], buffer2, sizeof(buffer2) - 1);
	//close(pipe2[0]);
	//TEST_ASSERT_NOT_EQUAL(-1, dup2(backup_fd, STDOUT_FILENO));
	//close(backup_fd);

	//TEST_ASSERT_EQUAL_INT(num2, num1);
	//TEST_ASSERT_EQUAL_STRING(buffer2, buffer1);
}

void	test_ft_printf_char(void)
{
	const char 	*format = "Char: %c %c\n";

	printf_result_t	result1 = capture_printf(printf, format, 'c', 'S');
	printf_result_t	result2 = capture_printf(ft_printf, format, 'c', 'S');

	TEST_ASSERT_EQUAL_INT(result1.ret, result2.ret);
	TEST_ASSERT_EQUAL_STRING(result1.buffer, result2.buffer);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_printf_char);
	RUN_TEST(test_ft_printf_no_specifiers);
	return UNITY_END();
}

