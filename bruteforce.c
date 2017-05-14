//
// Created by Daniel Cardoso on 13/05/17.
//


/*******************************************************************************
*                                 DEPENDENCIAS                                 *
********************************************************************************/

#include <string.h>
#include "bruteforce.h"
#include "tools.h"

/*******************************************************************************
*                STRUCTS, UNIONS E OUTRAS ESTRUTURAS GLOBAIS                   *
********************************************************************************/

PRIVATE BestRoute bestRoute;

/*******************************************************************************
*                                IMPLEMENTATIONS                               *
********************************************************************************/

PUBLIC BestRoute* bruteForce(Graph*g,int initialv )
{
    setGraph(g);
    setArbitraryVertex(initialv);
    printf("Number of Vertex: %d\n",SIZE_G);
    printg(getGraph());
    int auxP[SIZE_G-1];
    p = &auxP[0];
    int auxVector[SIZE_G-1];
    initialization(auxVector);
    initPermutation(auxVector);
    printf("\nAlgorithm: Brute Force!\n");
    return &bestRoute;
}

PRIVATE inline void setGraph(Graph* g)
{
    graphPtr = g;
}

PRIVATE inline Graph* getGraph()
{
    return graphPtr;
}

PRIVATE inline void setArbitraryVertex(int vertexValue )
{
    arbitraryVertex = vertexValue;
}

PRIVATE void initialization(int vector[])
{
    int i,j;
    for( i = 0, j = 0 ; i < SIZE_G - 1  ; ++i, ++j )
    {
        if( i != arbitraryVertex )
            vector[i] = j;
        else
            vector[i] = ++j;
    }

    bestRoute.distance = 0x7FFFFFFF;
    bestRoute.path = "";
}

PRIVATE void initPermutation(int auxVector[])
{
    permutation(auxVector,0);
}

PRIVATE void permutation(int auxVector[] ,int i)
{
    if( i == SIZE_G - 1 )
    {
        counter++;
        walk();
    }
    else
    {
        int j;
        for( j = 0 ; j < SIZE_G - 1 ; ++j )
        {
            int detect = FALSE;
            for( int k = 0 ; k < i ; ++k )
            {
                if(p[k]==auxVector[j])
                    detect = TRUE;
            }

            if(!detect)
            {
                p[i] = auxVector[j];
                permutation(auxVector,i+1);
            }
        }
    }
}

PRIVATE void walk()
{
    double currentCost = getEdge(getGraph(),arbitraryVertex,p[0]).weight;

    int i;
    for( i = 0 ; i < SIZE_G - 2 ; ++i )
        currentCost += getEdge(getGraph(),p[i],p[i+1]).weight;

    currentCost += getEdge(getGraph(),arbitraryVertex,p[SIZE_G-2]).weight;

    if( currentCost < bestRoute.distance )
    {
        bestRoute.distance = currentCost;
        String str = NULL;
        str = int2str(arbitraryVertex);
        bestRoute.path = strcat( str," " );
        int j;
        for( i = 1, j = 0 ; j < SIZE_G - 1 ; ++i, ++j )
        {
            str = int2str( p[j] );
            bestRoute.path = strcat( bestRoute.path, strcat(str," ") );

        }
        str = int2str(arbitraryVertex);
        bestRoute.path = strcat(bestRoute.path, str);
    }
}

