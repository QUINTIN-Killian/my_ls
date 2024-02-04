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

void free_under_dir(struct flags_list *flags)
{
    for (int i = 0; i < flags->under_dir_name_ind; i++)
        free(flags->under_dir_name[i]);
    if (flags->under_dir_name_ind > 0)
        free(flags->under_dir_name);
}

void free_arrays_flag(struct flags_list *flags)
{
    for (int i = 0; i < flags->file_name_ind; i++)
        free(flags->file_name[i]);
    free(flags->file_name);
    for (int i = 0; i < flags->dir_name_ind; i++)
        free(flags->dir_name[i]);
    free(flags->dir_name);
}

int main(int ac, char **av)
{
    struct flags_list flags;

    initialize_struct(&flags);
    get_flags(&flags, ac, av);
    get_files(&flags, ac, av);
    my_ls(&flags);
    free_under_dir(&flags);
    free_arrays_flag(&flags);
    return flags.error;
}
