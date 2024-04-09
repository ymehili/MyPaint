/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-amazed-lucas.leclerc
** File description:
** test_my_putstr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_paint.h"
#include <stdio.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putstr, should_print_string_to_stdout, .init = redirect_all_std)
{
    char *str = "Hello, world!";
    my_putstr(str);
    cr_assert_stdout_eq_str(str);
}

Test(my_putstr, should_print_null_string_to_stdout, .init = redirect_all_std)
{
    char *str = "";
    my_putstr(str);
    cr_assert_stdout_neq_str("");
}

