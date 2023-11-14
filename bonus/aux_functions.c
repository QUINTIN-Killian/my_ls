/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Contains auxiliar functions.
** aux
*/

#include "include/my.h"
#include "include/my_ls.h"

static void free_str(char *str1, char *str2)
{
    free(str1);
    free(str2);
}

static char *change_s1(char *s1)
{
    for (int i = 0; i < my_strlen(s1); i++)
        if (s1[i] >= 97 && s1[i] <= 122)
            s1[i] = s1[i] - 32;
    return s1;
}

static char *change_s2(char *s2)
{
    for (int i = 0; i < my_strlen(s2); i++)
        if (s2[i] >= 97 && s2[i] <= 122)
            s2[i] = s2[i] - 32;
    return s2;
}

static int get_max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}

static int my_strcmp_ls_aux(char *dup_s1, char *dup_s2)
{
    int len_s1 = my_strlen(dup_s1);
    int len_s2 = my_strlen(dup_s2);
    int len = get_max(len_s1, len_s2);

    for (int i = 0; i < len; i++) {
        if (i >= len_s1 && i < len_s2)
            return -1;
        if (i < len_s1 && i >= len_s2)
            return 1;
        if (dup_s1[i] < dup_s2[i])
            return -1;
        if (dup_s1[i] > dup_s2[i])
            return 1;
    }
    return 0;
}

int my_strcmp_ls(char const *s1, char const *s2)
{
    char *dup_s1 = change_s1(my_strdup(s1));
    char *dup_s2 = change_s2(my_strdup(s2));
    int ans = my_strcmp_ls_aux(dup_s1, dup_s2);

    free(dup_s1);
    free(dup_s2);
    return ans;
}

int get_nb_other(int ac, char **av)
{
    struct stat lst;
    int ans = 0;
    DIR *fd;

    for (int i = 1; i < ac; i++) {
        fd = opendir(av[i]);
        if (fd == NULL &&
        lstat(av[i], &lst) != 0 && av[i][0] != '-')
            ans++;
        closedir(fd);
    }
    return ans;
}

int is_flag(char *str)
{
    return str[0] == '-';
}
