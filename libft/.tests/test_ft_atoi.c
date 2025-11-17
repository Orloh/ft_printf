/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 01:20:22 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/27 01:23:37 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libft.h"

// Function prototype for ft_atoi (to ensure clarity)
int ft_atoi(const char *str);

// Setup function (called before each test)
void setUp(void) {
	// No specific setup needed for these tests
}

// Teardown function (called after each test)
void tearDown(void) {
	// No specific cleanup needed
}

// Test case: Valid positive number
void test_ft_atoi_positive_number(void) {
	TEST_ASSERT_EQUAL_INT(123, ft_atoi("123"));
	TEST_ASSERT_EQUAL_INT(42, ft_atoi("42"));
	TEST_ASSERT_EQUAL_INT(0, ft_atoi("0"));
}

// Test case: Valid negative number
void test_ft_atoi_negative_number(void) {
	TEST_ASSERT_EQUAL_INT(-123, ft_atoi("-123"));
	TEST_ASSERT_EQUAL_INT(-42, ft_atoi("-42"));
}

// Test case: Number with leading whitespace
void test_ft_atoi_leading_whitespace(void) {
	TEST_ASSERT_EQUAL_INT(42, ft_atoi("  42"));
	TEST_ASSERT_EQUAL_INT(42, ft_atoi("\t\n\r 42"));
	TEST_ASSERT_EQUAL_INT(-42, ft_atoi(" \t\n\r-42"));
}

// Test case: Number with plus sign
void test_ft_atoi_plus_sign(void) {
	TEST_ASSERT_EQUAL_INT(42, ft_atoi("+42"));
	TEST_ASSERT_EQUAL_INT(123, ft_atoi("+123"));
}

// Test case: Number with whitespace and sign
void test_ft_atoi_whitespace_and_sign(void) {
	TEST_ASSERT_EQUAL_INT(42, ft_atoi("   +42"));
	TEST_ASSERT_EQUAL_INT(-42, ft_atoi("   -42"));
}

// Test case: Non-numeric input
void test_ft_atoi_non_numeric(void) {
	TEST_ASSERT_EQUAL_INT(0, ft_atoi("abc"));
	TEST_ASSERT_EQUAL_INT(0, ft_atoi(""));
	TEST_ASSERT_EQUAL_INT(0, ft_atoi("   "));
}

// Test case: Mixed input (numeric followed by non-numeric)
void test_ft_atoi_mixed_input(void) {
	TEST_ASSERT_EQUAL_INT(42, ft_atoi("42abc"));
	TEST_ASSERT_EQUAL_INT(-42, ft_atoi("-42abc"));
}

// Test case: Edge cases (sign only, whitespace only, empty string)
void test_ft_atoi_edge_cases(void) {
	TEST_ASSERT_EQUAL_INT(0, ft_atoi("+"));
	TEST_ASSERT_EQUAL_INT(0, ft_atoi("-"));
	TEST_ASSERT_EQUAL_INT(0, ft_atoi(""));
	TEST_ASSERT_EQUAL_INT(0, ft_atoi("   "));
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_ft_atoi_positive_number);
	RUN_TEST(test_ft_atoi_negative_number);
	RUN_TEST(test_ft_atoi_leading_whitespace);
	RUN_TEST(test_ft_atoi_plus_sign);
	RUN_TEST(test_ft_atoi_whitespace_and_sign);
	RUN_TEST(test_ft_atoi_non_numeric);
	RUN_TEST(test_ft_atoi_mixed_input);
	RUN_TEST(test_ft_atoi_edge_cases);

	return UNITY_END();
}
