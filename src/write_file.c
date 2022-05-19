/*
** EPITECH PROJECT, 2022
** stumper
** File description:
** stumper_descroption
*/

#include "stumper.h"

int write_file(char *str)
{
    if (!str)
        return 84;
    FILE *stream = fopen("crypt", "w+");

    if (!stream) {
        write(2, "File creation failed\n", 21);
        return 84;
    }
    fprintf(stream, str);
    free(str);
    fclose(stream);
    return 0;
}
