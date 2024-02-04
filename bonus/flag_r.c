/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Reverses the files and dir strings arrays.
** flag_r
*/

#include "include/my.h"
#include "include/my_ls.h"

void sort_rev_under_dir(struct flags_list *flags)
{
    char *temp;

    for (int i = 0; i < flags->under_dir_name_ind / 2; i++) {
        temp = flags->under_dir_name[i];
        flags->under_dir_name[i] =
        flags->under_dir_name[flags->under_dir_name_ind - 1 - i];
        flags->under_dir_name[flags->under_dir_name_ind - 1 - i] = temp;
    }
}

void sort_rev(struct flags_list *flags)
{
    char *temp;

    for (int i = 0; i < flags->file_name_ind / 2; i++) {
        temp = flags->file_name[i];
        flags->file_name[i] = flags->file_name[flags->file_name_ind - 1 - i];
        flags->file_name[flags->file_name_ind - 1 - i] = temp;
    }
    for (int i = 0; i < flags->dir_name_ind / 2; i++) {
        temp = flags->dir_name[i];
        flags->dir_name[i] = flags->dir_name[flags->dir_name_ind - 1 - i];
        flags->dir_name[flags->dir_name_ind - 1 - i] = temp;
    }
}

void flag_r_recognition(struct flags_list *flags)
{
    if (flags->r)
        sort_rev(flags);
}

void flag_r_recognition_under_dir(struct flags_list *flags)
{
    if (flags->r)
        sort_rev_under_dir(flags);
}
