/**
 * @author Andrej Bartulin
 * PROJECT: 3x
 * LICENSE: Public Domain
 * DESCRIPTION: Header file for big number generator
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *strrev(char *s) 
{
    size_t j = 0, i = strlen(s);
    while (i --> j) 
    {
        char c = s[i];
        s[i] = s[j];
        s[j++] = c;
    }
    return s;
}

static char *mulstr(char *s, int n) 
{
    size_t i = 0;
    int carry = 0;
    while (s[i]) {
        carry += n * (s[i] - '0');
        s[i++] = '0' + carry % 10;
        carry /= 10;
    }
    while (carry) {
        s = (char*)realloc(s, i + 2);
        s[i++] = '0' + carry % 10;
        carry /= 10;
    }
    s[i] = '\0';
    return s;
}

static char *factorial(int n) 
{
    char *f = strdup("1");
    for (int i = 2; i <= n; i++) 
    {
        f = mulstr(f, i);
    }
    return f;
}