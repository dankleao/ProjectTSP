//
// Created by Daniel Cardoso on 10/05/17.
//
/*******************************************************************************
*                                 DEPENDENCIAS                                 *
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "graphio.h"
#include "tsp.h"

/*******************************************************************************
*                                IMPLEMENTATIONS                               *
********************************************************************************/

PUBLIC void* readGraph(InfoFile *args)
{
    if( (OPEN_FILE((*args))) == NULL )
        (printf("GraphIOException{ The \"%s\" file can not be opened! };\n",(*args).name),exit(1));
    READLINE_FILE;
    int order = atoi(buffer);
    City cities[order];
    int idCity = -1;
    while( READLINE_FILE )
        setCity(&cities[++idCity]);
    CLOSE_FILE();
    Graph*g = newGraph(order);
    generateCompleteGraph(g,&cities[0]);
    return g;
}

