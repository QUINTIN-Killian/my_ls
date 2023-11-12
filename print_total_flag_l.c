/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Prints the total with the l flag.
** print_total_flag_l
*/

#include "include/my.h"
#include "include/my_ls.h"

int print_total_flag_l(char *file_path)
{
    int n = 0;
    struct stat lst;
    struct dirent *my_dir;
    DIR *fd;

    fd = opendir(file_path);
    my_dir = readdir(fd);
    while (my_dir != NULL) {
        lstat(concat_str(3, file_path, "/", my_dir->d_name), &lst);
        n += lst.st_blocks;
        my_dir = readdir(fd);
    }
    closedir(fd);
    my_putstr("total ");
    my_put_nbr(n / 2);
    my_putchar('\n');
}
