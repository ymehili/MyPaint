/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-amazed-lucas.leclerc
** File description:
** test_my_putnbr_in_str
*/

#include "../include/my_paint.h"
#include <criterion/criterion.h>

Test(my_putnbr_in_str, basic_test)
{
    int nb = 42;
    char *result = my_putnbr_in_str(nb);

    cr_assert_str_eq(result, "42");
}

Test(my_putnbr_in_str, negative_test)
{
    int nb = -42;
    char *result = my_putnbr_in_str(nb);

    cr_assert_str_eq(result, "-42");
}

Test(my_putnbr_in_str, zero_test)
{
    int nb = 0;
    char *result = my_putnbr_in_str(nb);

    cr_assert_str_eq(result, "0");
}

Test(my_putnbr_in_str, big_number_test)
{
    int nb = 1234567890;
    char *result = my_putnbr_in_str(nb);

    cr_assert_str_eq(result, "1234567890");
}

Test(my_putnbr_in_str, negative_big_number_test)
{
    int nb = -1234567890;
    char *result = my_putnbr_in_str(nb);

    cr_assert_str_eq(result, "-1234567890");
}

Test(my_putnbr_in_str, negative_zero_test)
{
    int nb = -0;
    char *result = my_putnbr_in_str(nb);

    cr_assert_str_eq(result, "0");
}

Test(my_putnbr_in_str, negative_one_test)
{
    int nb = -1;
    char *result = my_putnbr_in_str(nb);

    cr_assert_str_eq(result, "-1");
}

Test(my_putnbr_in_str, one_test)
{
    int nb = 1;
    char *result = my_putnbr_in_str(nb);

    cr_assert_str_eq(result, "1");
}
