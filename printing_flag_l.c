/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Prints flag l infos
** printing_flag_l
*/

#include "include/my.h"
#include "include/my_ls.h"

void print_file_name(char *str)
{
    int ind = my_strlen(str) - 1;

    while (str[ind] != '/' && ind >= 0)
        ind--;
    ind++;
    while (ind < my_strlen(str)) {
        my_putchar(str[ind]);
        ind++;
    }
}

void print_last_modif(struct stat *lst)
{
    char *timedate = ctime(&lst->st_mtime);

    my_parsing(timedate, 4, 8);
    if (timedate[9] != ' ') {
        my_putchar(timedate[8]);
        my_putchar(timedate[9]);
    } else
        my_putchar(timedate[8]);
    my_parsing(timedate, 10, 16);
    my_putchar(' ');
}

void print_size(struct stat *lst)
{
    my_put_nbr(lst->st_size);
    my_putchar(' ');
    print_last_modif(lst);
}

static void print_usr_and_grp(struct stat *lst)
{
    struct passwd *u_pwd;
    struct passwd *g_pwd;

    u_pwd = getpwuid(lst->st_uid);
    g_pwd = getpwuid(lst->st_gid);
    my_putstr(u_pwd->pw_name);
    my_putchar(' ');
    my_putstr(g_pwd->pw_name);
    my_putchar(' ');
    print_size(lst);
}

static void print_nb_hard_link(struct stat *lst)
{
    my_put_nbr(lst->st_nlink);
    my_putchar(' ');
    print_usr_and_grp(lst);
}

static void print_user_permissions(struct stat *lst)
{
    if (lst->st_mode & S_IRUSR)
        my_putchar('r');
    else
        my_putchar('-');
    if (lst->st_mode & S_IWUSR)
        my_putchar('w');
    else
        my_putchar('-');
    if (lst->st_mode & S_IXUSR)
        my_putchar('x');
    else
        my_putchar('-');
}

static void print_group_permissions(struct stat *lst)
{
    if (lst->st_mode & S_IRGRP)
        my_putchar('r');
    else
        my_putchar('-');
    if (lst->st_mode & S_IWGRP)
        my_putchar('w');
    else
        my_putchar('-');
    if (lst->st_mode & S_IXGRP)
        my_putchar('x');
    else
        my_putchar('-');
}

static void print_other_permissions(struct stat *lst)
{
    if (lst->st_mode & S_IROTH)
        my_putchar('r');
    else
        my_putchar('-');
    if (lst->st_mode & S_IWOTH)
        my_putchar('w');
    else
        my_putchar('-');
    if (lst->st_mode & S_IXOTH)
        my_putchar('x');
    else
        my_putchar('-');
}

void print_permissions(struct stat *lst)
{
    if (S_ISDIR(lst->st_mode))
        my_putchar('d');
    else
        my_putchar('-');
    print_user_permissions(lst);
    print_group_permissions(lst);
    print_other_permissions(lst);
    my_putchar(' ');
    print_nb_hard_link(lst);
}
