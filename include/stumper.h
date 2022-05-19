/*
** EPITECH PROJECT, 2022
** B-CPE-210-BDX-2-1-stumper7-esteban.loriot
** File description:
** stumper
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#ifndef STUMPER_H_
    #define STUMPER_H_

    #define EPITECH_ERROR 84

typedef struct game_s {
    int nothing;
} game_t;

int arg_check(int ac, const char **av);
game_t *init_struct(void);
int write_file(char *str);
char *open_file(const char *file_path);

#endif /* !STUMPER_H_ */
