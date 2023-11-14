/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Works the same as ls.
** my_ls
*/
/*
NOTES ET OBJECTIFS :
    - recréer affichage de plusieurs dir
    - demander Loïc son printing en couleur
    - error handling si le file name ou dir name n'existe pas
*/

#include "include/my.h"
#include "include/my_ls.h"

int print_files(struct flags_list *flags, int ind)
{
    my_putstr(flags->file_name[ind]);
    if (ind < flags->file_name_ind - 1)
        my_putstr("  ");
    if (ind == flags->file_name_ind - 1 && flags->dir_name_ind > 0)
        my_putchar('\n');
    return 0;
}

int print_dir(struct flags_list *flags, int ind)
{
    if (flags->total > 1 && ind != 0)
        my_putchar('\n');
    if (flags->total > 1) {
        my_putstr(flags->dir_name[ind]);
        my_putstr(":\n");
    }
    for (int i = 0; i < my_strlen_array(flags->under_dir_name); i++) {
        my_putstr(flags->under_dir_name[i]);
        if (i < my_strlen_array(flags->under_dir_name) - 1)
            my_putstr("  ");
    }
    my_putchar('\n');
}

static void if_flag_l(struct flags_list *flags, int i)
{
    if (i > 0)
        my_putstr("\n\n");
    if (flags->total > 1) {
        my_putstr(flags->dir_name[i]);
        my_putstr(":\n");
    }
    print_total_flag_l(flags->dir_name[i]);
    for (int j = 0; j < flags->under_dir_name_ind; j++)
        call_flag_l(concat_str(3, flags->dir_name[i], "/",
        flags->under_dir_name[j]), flags);
}

static void separator(struct flags_list *flags)
{
    if (!flags->l && flags->file_name_ind > 0)
        my_putchar('\n');
    if (flags->l && flags->file_name_ind > 0 && flags->dir_name_ind > 0)
        my_putchar('\n');
}

static void isolate_files(struct flags_list *flags)
{
    for (int i = 0; i < flags->file_name_ind; i++) {
        if (flags->l) {
            call_flag_l(flags->file_name[i], flags);
            continue;
        }
        print_files(flags, i);
    }
}

static void isolate_dir(struct flags_list *flags)
{
    for (int i = 0; i < flags->dir_name_ind; i++) {
        get_under_dir(flags, i);
        flag_t_recognition_under_dir(flags, i);
        flag_r_recognition_under_dir(flags);
        if (flags->l) {
            if_flag_l(flags, i);
            continue;
        }
        print_dir(flags, i);
    }
}

int my_ls(struct flags_list *flags)
{
    DIR *fd;
    struct dirent *my_dir;

    flag_d_recognition(flags);
    flag_t_recognition(flags);
    flag_r_recognition(flags);
    isolate_files(flags);
    separator(flags);
    isolate_dir(flags);
    return 0;
}
