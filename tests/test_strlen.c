/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-amazed-lucas.leclerc
** File description:
** test_strlen
*/

#include "../include/my_paint.h"
#include <criterion/criterion.h>

Test(my_strlen, basic_test)
{
    char *src = "hello world";
    int result = my_strlen(src);

    cr_assert_eq(result, 11, "bad result for the len");
}

Test(my_strlen, no_lenth)
{
    char *src = "";
    int result = my_strlen(src);

    cr_assert_eq(result, 0, "bad result for the len");
}