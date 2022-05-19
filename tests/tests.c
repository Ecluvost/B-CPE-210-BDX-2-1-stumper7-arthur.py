/*
** EPITECH PROJECT, 2022
** change
** File description:
** tests the function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "stumper.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(cesar_tests, valid_arg_dash_s)
{
    const char **str = malloc(sizeof(char *) * 5);
    str[0] = "./cesar";
    str[1] = "-s";
    str[2] = "abcdefghijklmnopqrstuvwxyz";
    str[3] = "42";
    int returned_value = arg_check(4, str);

    cr_assert_eq(0, returned_value);
}

Test(cesar_tests, valid_arg_dash_f)
{
    const char **str = malloc(sizeof(char *) * 5);
    str[0] = "./cesar";
    str[1] = "-f";
    str[2] = "tests/alphabet";
    str[3] = "42";
    int returned_value = arg_check(4, str);

    cr_assert_eq(0, returned_value);
}

Test(cesar_tests, negative_key)
{
    const char **str = malloc(sizeof(char *) * 5);
    str[0] = "./cesar";
    str[1] = "-s";
    str[2] = "abcdefg";
    str[3] = "-42";
    int returned_value = arg_check(4, str);

    cr_assert_eq(0, returned_value);
}

Test(cesar_tests, null_key)
{
    const char **str = malloc(sizeof(char *) * 4);
    str[0] = "./cesar";
    str[1] = "-s";
    str[2] = "abcdefg";
    int returned_value = arg_check(3, str);

    cr_assert_eq(0, returned_value);
}

Test(cesar_tests, not_enough_arg)
{
    const char **str = malloc(sizeof(char*) * 2);
    str[0] = "./cesar";
    int returned_value = arg_check(1, str);

    cr_assert_eq(84, returned_value);
}

Test(cesar_tests, too_many_arg)
{
    const char **str = malloc(sizeof(char *) * 6);
    str[0] = "./cesar";
    str[1] = "-s";
    str[2] = "abcdefghijklmnopqrstuvwxyz";
    str[3] = "42";
    str[4] = "too much";
    int returned_value = arg_check(5, str);

    cr_assert_eq(84, returned_value);
}

Test(cesar_tests, invalid_dash)
{
    const char **str = malloc(sizeof(char *) * 5);
    str[0] = "./cesar";
    str[1] = "-incorrect";
    str[2] = "abcdefghijklmnopqrstuvwxyz";
    str[3] = "42";
    int returned_value = arg_check(4, str);

    cr_assert_eq(84, returned_value);
}

Test(cesar_tests, invalid_key)
{
    const char **str = malloc(sizeof(char *) * 5);
    str[0] = "./cesar";
    str[1] = "-f";
    str[2] = "tests/alphabet";
    str[3] = "incorrect";
    int returned_value = arg_check(4, str);

    cr_assert_eq(84, returned_value);
}

Test(cesar_tests, invalid_file)
{
    const char **str = malloc(sizeof(char *) * 5);
    str[0] = "./cesar";
    str[1] = "-f";
    str[2] = "incorrect";
    str[3] = "42";
    int returned_value = arg_check(4, str);

    cr_assert_eq(84, returned_value);
}
