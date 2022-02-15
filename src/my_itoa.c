/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-luca.orelli
** File description:
** my_itoa.c
*/

#include "runner.h"

char *my_revstr(char *str)
{
    int     i = 0;
    int     j = 0;
    char    a;

    while (str[i] != '\0')
        i++;
    i -= 1;
    while (i != j && i > j) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
        i--;
        j++;
    }
    return (str);
}

void my_itoa(char *s, unsigned int n)
{
    char *tmp = s;

    while (n) {
        *s++ = n % 10 + '0';
        n /= 10;
    }
    *s = '\0';
    my_revstr(tmp);
}
