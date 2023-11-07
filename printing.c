/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Prints something in the correct color.
** printing
*/

#include "include/my.h"
#include "include/my_ls.h"

void printing(char *str)
{
    my_putstr("\033[34;01m");
    my_putstr(str);
    my_putstr("\033[00m");
}
