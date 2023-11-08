/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Prints something in the correct color.
** printing
*/

#include "include/my.h"
#include "include/my_ls.h"

void printing(struct dirent *my_dir, char *file_path)
{
    struct stat st;

    lstat(file_path, &st);
    if (!S_ISDIR(st.st_mode) && !S_ISLNK(st.st_mode))
        my_putstr(my_dir->d_name);
    if (S_ISDIR(st.st_mode)) {
        my_putstr("\033[34;01m");
        my_putstr(my_dir->d_name);
        my_putstr("\033[00m");
    }
    if (S_ISLNK(st.st_mode)) {
        my_putstr("\033[92;01m");
        my_putstr(my_dir->d_name);
        my_putstr("\033[00m");
    }
}
