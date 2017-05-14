//
// Created by Daniel Cardoso on 13/05/17.
//


#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

PRIVATE String bufferPtr = NULL;

void int2str2(int num,int numDigit)
{
    static int maxDigit = 0;
    if( num <= 99 )
    {
        maxDigit = numDigit;
        bufferPtr = (String) malloc(sizeof(char)*(maxDigit+1));
        bufferPtr[0] = getChr(num/10);
        bufferPtr[1] = getChr(num%10);
        bufferPtr[maxDigit] = '\0';
        return;
    }
    int2str2(num/10,(numDigit+1));
    bufferPtr[maxDigit-(numDigit-1)] = getChr(num%10);
}

String int2str(int num)
{
    if( num < 0 )
        num *= -1;

    if( num <= 9 )
    {
        bufferPtr = (char*) malloc(sizeof(char)+1);
        bufferPtr[0] = getChr(num);
        bufferPtr[1] = '\0';
    }
    else
    {
        int2str2(num,2);
    }
    return bufferPtr;
}

PRIVATE inline char getChr(int num)
{
    return (char)(num + '0');
}



