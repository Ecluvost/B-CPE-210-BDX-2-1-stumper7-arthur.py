/*
** EPITECH PROJECT, 2022
** arg_check
** File description:
** arg_check
*/

#include "stumper.h"

static int is_number(const char *str)
{
    if (!str)
        return EPITECH_ERROR;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9')
        && str[0] != '-') {
            return 0;
        }
    }
    return 1;
}

static int check_arg(int ac, const char **av)
{
    int tmp = 0;

    if (ac < 3) {
        write(2, "Not enough arguments\n", 21);
        return EPITECH_ERROR;
    }
    if (ac > 4) {
        write(2, "Too many arguments\n", 19);
        return EPITECH_ERROR;
    }
    if (ac == 4) {
        tmp = is_number(av[3]);
        if (tmp == 0 || tmp == EPITECH_ERROR) {
            write(2, "Incorrect argument\n", 19);
            return EPITECH_ERROR;
        }
    }
    return 0;
}

static int arg_check2(const char **av, int key)
{
    char *str;

    if (strcmp(av[1], "-f") == 0) {
        str = open_file(av[2]);
        if (!str)
            return EPITECH_ERROR;
        return cesar(str, key);
    } else if (strcmp(av[1], "-s") == 0) {
        str = malloc(sizeof(char) * (strlen(av[2]) + 1));
        strcpy(str, av[2]);
        return cesar(str, key);
    } else {
        write(2, "Incorrect argument\n", 19);
        return EPITECH_ERROR;
    }
}

int arg_check(int ac, const char **av)
{
    if (!av)
        return EPITECH_ERROR;
    int key = 0;

    if (check_arg(ac, av) == EPITECH_ERROR)
        return EPITECH_ERROR;
    if (ac == 4)
        key = atoi(av[3]);
    return arg_check2(av, key);
}
