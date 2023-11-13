/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** t flag functions.
** flag_t
*/

#include "include/my.h"
#include "include/my_ls.h"

static void inv_files(struct flags_list *flags, int j)
{
    struct stat lst1;
    struct stat lst2;
    char *temp;

    lstat(flags->file_name[j], &lst1);
    lstat(flags->file_name[j + 1], &lst2);
    if (lst2.st_mtime > lst1.st_mtime) {
        temp = flags->file_name[j];
        flags->file_name[j] = flags->file_name[j + 1];
        flags->file_name[j + 1] = temp;
    }
}

static void inv_dir(struct flags_list *flags, int j)
{
    struct stat lst1;
    struct stat lst2;
    char *temp;

    lstat(flags->dir_name[j], &lst1);
    lstat(flags->dir_name[j + 1], &lst2);
    if (lst2.st_mtime > lst1.st_mtime) {
        temp = flags->dir_name[j];
        flags->dir_name[j] = flags->dir_name[j + 1];
        flags->dir_name[j + 1] = temp;
    }
}

void flag_t(struct flags_list *flags)
{
    for (int i = 0; i < flags->file_name_ind; i++)
        for (int j = 0; j < flags->file_name_ind - 1; j++)
            inv_files(flags, j);
    for (int i = 0; i < flags->dir_name_ind; i++)
        for (int j = 0; j < flags->dir_name_ind - 1; j++)
            inv_dir(flags, j);
}
