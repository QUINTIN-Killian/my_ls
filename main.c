/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Main file.
** main
*/
/*
Sorting est sensible a la casse => pas le sorting de ls !!!!!
*/

#include "include/my.h"
#include "include/my_ls.h"

void initialize_struct(struct flags_list *flags)
{
    flags->a = 0;
    flags->l = 0;
    flags->r_maj = 0;
    flags->d = 0;
    flags->r = 0;
    flags->t = 0;
    flags->file_name_ind = 0;
    flags->dir_name_ind = 0;
    flags->under_dir_name_ind = 0;
    flags->total = 0;
    flags->error = 0;
}

int main(int ac, char **av)
{
    struct flags_list flags;

    initialize_struct(&flags);
    get_flags(&flags, ac, av);
    get_files(&flags, ac, av);
    my_ls(&flags);
    if (flags.under_dir_name_ind > 0)
        free(flags.under_dir_name);
    return flags.error;
}
