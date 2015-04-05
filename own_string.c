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

char * own_strncat(char * dest, const char * src, unsigned int n)
{
    char * ps = dest;
    unsigned int i = 0;

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
