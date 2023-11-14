/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** l flag functions.
** flag_l
*/

#include "include/my.h"
#include "include/my_ls.h"

void call_flag_l(char *file_path, struct flags_list *flags)
{
    struct stat lst;

    lstat(file_path, &lst);
    print_permissions(&lst);
    if (!flags->d)
        print_file_name(file_path);
    else
        my_putstr(file_path);
    my_putchar('\n');
}
