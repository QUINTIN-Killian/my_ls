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
    flags->error = 0;
    return 0;
}

int main(int ac, char **av)
{
    struct flags_list flags;

    initialize_struct(&flags);
    get_flags(&flags, ac, av);
    get_files(&flags, ac, av);
    if (flags.t == 1)
        flag_t(&flags);
    if (flags.l == 1)
        return flag_l(&flags);
    if (flags.d == 1)
        return flag_d(&flags);
    if (flags.r == 1)
        return flag_r(&flags);
    if (flags.d == 0 && flags.r == 0 && flags.l == 0)
        classic_ls(&flags);
    return flags.error;
}
