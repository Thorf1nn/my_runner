/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-luca.orelli
** File description:
** basic_fonc.c
*/

#include "runner.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}

int my_strlen(char const *str )
{
    int b = 0;

    while (str[b] != '\0')
        b++;
    return b;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while ((s1[i] == s2[i]) && s1[i] && s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int to_number(char const *str)
{
    int sign = 1;
    long long int res = 0;

    while (45 == *str || 43 == *str) {
        if (*str == 45)
            sign *= -1;
        str++;
    }
    while (*str >= 48 && *str <= 57) {
        res = res * 10 + (*str - 48) * sign;
        str++;
        if (res < -2147483648 || res > 2147483647)
            return 0;
    }
    return res;
}
