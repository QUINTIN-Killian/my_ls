/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** contains d flag functions.
** flag_d
*/

#include "include/my.h"
#include "include/my_ls.h"

static void re_malloc_array(struct flags_list *flags)
{
    char **buff = malloc(sizeof(char *) * (flags->file_name_ind + 1));

    buff[flags->file_name_ind] = NULL;
    for (int i = 0; i < flags->file_name_ind; i++)
        buff[i] = my_strdup(flags->file_name[i]);
    for (int i = 0; i < flags->file_name_ind; i++)
        free(flags->file_name[i]);
    free(flags->file_name);
    flags->file_name = malloc(sizeof(char *) *
    (flags->file_name_ind + flags->dir_name_ind + 1));
    for (int i = 0; i < flags->file_name_ind; i++)
        flags->file_name[i] = my_strdup(buff[i]);
    for (int i = 0; i < flags->file_name_ind; i++)
        free(buff[i]);
    free(buff);
}

void d_flag(struct flags_list *flags)
{
    re_malloc_array(flags);
    for (int i = 0; i < flags->dir_name_ind; i++) {
        flags->file_name[flags->file_name_ind] = flags->dir_name[i];
        flags->file_name_ind++;
    }
    flags->dir_name_ind = 0;
}

void flag_d_recognition(struct flags_list *flags)
{
    if (flags->d)
        d_flag(flags);
}
