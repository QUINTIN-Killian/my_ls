/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Main file.
** main
*/

#include "include/my.h"
#include "include/my_ls.h"

int initialize_struct(struct flags_list *flags)
{
    flags->a = 0;
    flags->l = 0;
    flags->r_maj = 0;
    flags->d = 0;
    flags->r = 0;
    flags->t = 0;
    flags->file_name_ind = 0;
    flags->dir_name_ind = 0;
    flags->total = 0;
    return 0;
}

int main(int ac, char **av)
{
    struct flags_list flags;
    int error_flags = 0;
    int error_files = 0;

    initialize_struct(&flags);
    error_flags = get_flags(&flags, ac, av);
    error_files = get_files(&flags, ac, av);
    if (flags.d == 1)
        flag_d(&flags);
    if (flags.d == 0)
        classic_ls(&flags);
    if (error_flags == 84 || error_files == 84)
        return 84;
    return 0;
}
