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
