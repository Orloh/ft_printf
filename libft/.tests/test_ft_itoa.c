/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:47:12 by orhernan          #+#    #+#             */
/*   Updated: 2025/10/27 16:47:46 by orhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libft.h"
#include <limits.h>

// Function prototype for ft_itoa
char *ft_itoa(int n);

// Setup function (called before each test)
void setUp(void) {
    // No specific setup needed
}

// Teardown function (called after each test)
void tearDown(void) {
    // No specific cleanup needed
}

// Test case: Positive numbers
void test_ft_itoa_positive_number(void) {
    char *result;

    result = ft_itoa(123);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING_MESSAGE("123", result, "Failed for input 123");
    free(result);

    result = ft_itoa(42);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING_MESSAGE("42", result, "Failed for input 42");
    free(result);
}

// Test case: Negative numbers
void test_ft_itoa_negative_number(void) {
    char *result;

    result = ft_itoa(-123);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING_MESSAGE("-123", result, "Failed for input -123");
    free(result);

    result = ft_itoa(-42);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING_MESSAGE("-42", result, "Failed for input -42");
    free(result);
}

// Test case: Zero
void test_ft_itoa_zero(void) {
    char *result;

    result = ft_itoa(0);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING_MESSAGE("0", result, "Failed for input 0");
    free(result);
}

// Test case: Single-digit numbers
void test_ft_itoa_single_digit(void) {
    char *result;

    result = ft_itoa(5);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING_MESSAGE("5", result, "Failed for input 5");
    free(result);

    result = ft_itoa(-5);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING_MESSAGE("-5", result, "Failed for input -5");
    free(result);
}

// Test case: Edge cases (INT_MAX and INT_MIN)
void test_ft_itoa_edge_cases(void) {
    char *result;

    result = ft_itoa(INT_MAX);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING_MESSAGE("2147483647", result, "Failed for input INT_MAX");
    free(result);

    result = ft_itoa(INT_MIN);
    TEST_ASSERT_NOT_NULL(result);
    TEST_ASSERT_EQUAL_STRING_MESSAGE("-2147483648", result, "Failed for input INT_MIN");
    free(result);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ft_itoa_positive_number);
    RUN_TEST(test_ft_itoa_negative_number);
    RUN_TEST(test_ft_itoa_zero);
    RUN_TEST(test_ft_itoa_single_digit);
    RUN_TEST(test_ft_itoa_edge_cases);

    return UNITY_END();
}
