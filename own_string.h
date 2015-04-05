#ifndef OWN_STRING_H_INCLUDED
#define OWN_STRING_H_INCLUDED

#include <string.h>

char * own_strcat(char * dest, const char * src);
char * own_strncat(char * dest, const char * src, size_t n);
char * own_strchr(const char * str, int c);

#endif // OWN_STRING_H_INCLUDED
