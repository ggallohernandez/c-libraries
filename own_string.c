#include "own_string.h"

char * own_strcat(char * dest, const char * src)
{
    char * ps = dest;

    while (*dest)
        dest++;

    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return ps;
}

char * own_strncat(char * dest, const char * src, size_t n)
{
    char * ps = dest;
    size_t i = 0;

    while (*dest)
        dest++;

    while (i < n && *(src+i)) {
        *dest = *(src+i);
        dest++;
        i++;
    }

    *dest = '\0';

    return ps;
}

char * own_strchr(const char * str, int c)
{
    while (*str && *str != c)
        str++;

    return *str == c ? str : NULL;
}
