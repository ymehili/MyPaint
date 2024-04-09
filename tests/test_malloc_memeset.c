/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-lucas.leclerc
** File description:
** test_malloc_memeset
*/

#include "../include/my_paint.h"
#include <criterion/criterion.h>


Test(my_malloc, basic_test)
{
    int size = 10;
    char *ptr = my_malloc(size);

    cr_assert_not_null(ptr, "my_malloc() returned NULL");

    for (int i = 0; i < size; i++) {
        cr_assert_eq(ptr[i], '\0', "my_malloc() did not initialize memory to '\0'");
    }
}
