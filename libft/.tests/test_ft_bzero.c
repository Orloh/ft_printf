/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:29:12 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/13 13:52:04 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libft.h"
#include <string.h>
#include <stdlib.h>

void setUp(void)
{
	// Set up code, if needed.
}

void tearDown(void)
{
	// Clean up code, if needed.
}

void test_ft_bzero_zeros_buffer(void)
{
	char 	buffer [10] = "abcdefghij";
	int 	i = 0;
	
	ft_bzero(buffer, 10);
	TEST_ASSERT_EQUAL_INT(0, 0);
	while (i < 10)
		TEST_ASSERT_EQUAL_INT(0, buffer[i++]);
}

void test_ft_bzero_partial_buffer(void)
{
	char	buffer[10] = "abcdefghij";
	int	i = 0;

	ft_bzero(buffer, 5);
	while (i < 5)
		TEST_ASSERT_EQUAL_INT(0,buffer[i++]);
	TEST_ASSERT_EQUAL_CHAR('f', buffer[5]);
	TEST_ASSERT_EQUAL_CHAR('g', buffer[6]);
	TEST_ASSERT_EQUAL_CHAR('h', buffer[7]);
}

void test_ft_bzero_zero_size(void)
{
	char	buffer[10] = "abcdefghij";
	int	i = 0;

	ft_bzero(buffer, 0);
	TEST_ASSERT_EQUAL_STRING("abcdefghij", buffer);
}

void test_ft_bzero_int_array(void)
{
	int	buffer[5] = {1, 2, 3, 4 ,5};
	int	i = 0;

	ft_bzero(buffer, sizeof(int) * 5);
	while (i < 5)
		TEST_ASSERT_EQUAL_INT(0, buffer[i++]);
}

void test_ft_bzero_null_pointer(void)
{
    ft_bzero(NULL, 10);
    TEST_ASSERT_TRUE(1);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_bzero_zeros_buffer);
	RUN_TEST(test_ft_bzero_partial_buffer);
	RUN_TEST(test_ft_bzero_zero_size);
	RUN_TEST(test_ft_bzero_int_array);
	return UNITY_END();
}
