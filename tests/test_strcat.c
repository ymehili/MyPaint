/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lucas.leclerc
** File description:
** test_strcat
*/

#include "../include/my_paint.h"
#include <criterion/criterion.h>

Test(my_strcat, basic_test)
{
    char dest[20] = "Hello ";
    char src[] = "World!";
    char *result = my_strcat(dest, src);

    cr_assert_str_eq(result, "Hello World!");
}

Test(my_strcat, empty_string)
{
    char dest[20] = "";
    char src[] = "Test";
    char *result = my_strcat(dest, src);

    cr_assert_str_eq(result, "Test");
}
