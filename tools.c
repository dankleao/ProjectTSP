//
// Created by Daniel Cardoso on 13/05/17.
//


#include <stdlib.h>
#include "tools.h"

void itoa2(int num,int numDigit)
{
    static int maxDigit = 0;
    if( num <= 99 )
    {
        str = (String) malloc(sizeof(char)*numDigit);
        str[0] = getChr(num/10);
        str[1] = getChr(num%10);
        maxDigit = numDigit;
        return;
    }
    itoa2(num/10,(numDigit+1));
    str[maxDigit-(numDigit-1)] = getChr(num%10);
}

char* itoa(int num)
{
    if( num <= 9 )
    {
        str = (String) malloc(sizeof(char));
        str[0] = getChr(num);
        return str;
    }
    else
    {
        int numDigit = 2;
        itoa2(num,numDigit);
        return str;
    }
}

PRIVATE inline char getChr(int num)
{
    return (char)(num + '0');
}



