/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lucas.leclerc
** File description:
** test_strdup
*/

#include "../include/my_paint.h"
#include <criterion/criterion.h>

Test(my_strdup, basic_test)
{
    char *src = "Hello World!";
    char *result = my_strdup(src);

    cr_assert_not_null(result, "my_strdup() returned NULL");
    cr_assert_str_eq(result, "Hello World!");
}

Test(my_strdup, empty_string)
{
    char *src = "";
    char *result = my_strdup(src);

    cr_assert_not_null(result, "my_strdup() returned NULL");
    cr_assert_str_empty(result);
}

Test(my_strdup, NULL_string)
{
    char *src = NULL;
    char *result = my_strdup(src);

    cr_assert_null(result, "my_strdup() did not return NULL for NULL source string");
}