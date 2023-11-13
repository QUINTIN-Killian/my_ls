/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Reproduce the behavior of the strcmp function
** my_strcmp
*/

#include "my.h"

static char *change_s1(char *s1)
{
    for (int i = 0; i < my_strlen(s1); i++)
        if (s1[i] >= 65 && s1[i] <= 90)
            s1[i] = s1[i] + 32;
    return s1;
}

static char *change_s2(char *s2)
{
    for (int i = 0; i < my_strlen(s2); i++)
        if (s2[i] >= 65 && s2[i] <= 90)
            s2[i] = s2[i] + 32;
    return s2;
}

int my_strcmp_sans_casse(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int len = len_s1;
    char *dup_s1 = change_s1(my_strdup(s1));
    char *dup_s2 = change_s2(my_strdup(s2));

    if (len_s1 < len_s2)
        len = len_s2;
    for (int i = 0; i < len; i++) {
        if (i >= len_s1 && i < len_s2)
            return -1;
        if (i < len_s1 && i >= len_s2)
            return 1;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
