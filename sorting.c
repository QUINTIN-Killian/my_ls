/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Sorts the order of strings in an array.
** sorting
*/

#include "include/my.h"
#include "include/my_ls.h"

static void sort_file(struct flags_list *flags, int ind)
{
    char *temp;

    if (my_strcmp_sans_casse(flags->file_name[ind],
    flags->file_name[ind + 1]) > 0) {
        temp = flags->file_name[ind];
        flags->file_name[ind] = flags->file_name[ind + 1];
        flags->file_name[ind + 1] = temp;
    }
}

void sort_file_array(struct flags_list *flags)
{
    for (int i = 0; i < flags->file_name_ind; i++)
        for (int j = 0; j < flags->file_name_ind - 1; j++)
            sort_file(flags, j);
}

static void sort_dir(struct flags_list *flags, int ind)
{
    char *temp;

    if (my_strcmp_sans_casse(flags->dir_name[ind],
    flags->dir_name[ind + 1]) > 0) {
        temp = flags->dir_name[ind];
        flags->dir_name[ind] = flags->dir_name[ind + 1];
        flags->dir_name[ind + 1] = temp;
    }
}

void sort_dir_array(struct flags_list *flags)
{
    for (int i = 0; i < flags->dir_name_ind; i++)
        for (int j = 0; j < flags->dir_name_ind - 1; j++)
            sort_dir(flags, j);
}

static void sort_under_dir(struct flags_list *flags, int ind)
{
    char *temp;

    if (my_strcmp_sans_casse(flags->under_dir_name[ind],
    flags->under_dir_name[ind + 1]) > 0) {
        temp = flags->under_dir_name[ind];
        flags->under_dir_name[ind] = flags->under_dir_name[ind + 1];
        flags->under_dir_name[ind + 1] = temp;
    }
}

void sort_under_dir_array(struct flags_list *flags)
{
    for (int i = 0; i < flags->under_dir_name_ind; i++)
        for (int j = 0; j < flags->under_dir_name_ind - 1; j++)
            sort_under_dir(flags, j);
}
