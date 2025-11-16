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
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	setUp(void) {}
void	tearDown(void) {}

void	test_ft_printf_no_specifiers(void)
{
	const char 	*format = "Hello, world!\n";

	int		backup_fd;
	backup_fd = dup(STDOUT_FILENO);
	TEST_ASSERT_NOT_EQUAL(-1, backup_fd);

	char		buffer1[128] = {0};
	char		buffer2[128] = {0};
	int 		num1, num2;
	
	int		pipe1[2];
	TEST_ASSERT_EQUAL(0, pipe(pipe1));
	TEST_ASSERT_NOT_EQUAL(-1, dup2(pipe1[1], STDOUT_FILENO));
	close(pipe1[1]);
	num1 = ft_printf(format);
	fflush(stdout);
	read(pipe1[0], buffer1, sizeof(buffer1) - 1);
	close(pipe1[0]);
	TEST_ASSERT_NOT_EQUAL(-1, dup2(backup_fd, STDOUT_FILENO));

	int		pipe2[2];
	TEST_ASSERT_EQUAL(0, pipe(pipe2));
	TEST_ASSERT_NOT_EQUAL(-1, dup2(pipe2[1], STDOUT_FILENO));
	close(pipe2[1]);
	num2 = ft_printf(format);
	fflush(stdout);
	read(pipe2[0], buffer2, sizeof(buffer2) - 1);
	close(pipe2[0]);
	TEST_ASSERT_NOT_EQUAL(-1, dup2(backup_fd, STDOUT_FILENO));
	close(backup_fd);

	TEST_ASSERT_EQUAL_INT(num2, num1);
	TEST_ASSERT_EQUAL_STRING(buffer2, buffer1);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_printf_no_specifiers);
	return UNITY_END();
}

