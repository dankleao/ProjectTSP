//
// Created by Daniel Cardoso on 10/05/17.
//

/*******************************************************************************
*                                 DEPENDENCIAS                                 *
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "tsp.h"

/*******************************************************************************
*                                IMPLEMENTATIONS                               *
********************************************************************************/

PUBLIC Graph * createGraph( int size )
{
    Graph * g = NULL;
    if( ! (g = (Graph*) calloc( 1, sizeof(Graph) ) ) )
        return NULL;

    if( ! ( g->matrix = (Vertex*) calloc( (size_t) (size*size), sizeof(Vertex) ) ) )
        return NULL;
    else
        return ( g->length = size, g );

}

PUBLIC void destroyGraph(Graph* g)
{
    free(g->matrix);
    free(g);
}

PUBLIC Vertex getEdge(Graph*g,int source,int target )
{
    return g->matrix[virtualAddress(source,target,g->length)];
}

PUBLIC void generateCompleteGraph(Graph* g,void* c )
{
    City* city = (City*) c;
    int i,j;
    for( i = 0 ; i < g->length ; ++i )
    {
        for( j = i+1 ; j < g->length ; ++j )
        {
            static Edge e;
            e.source = i;
            e.target = j;
            e.weight = distance( city[i],city[j] );/* obtem o valor da aresta{i,j} */
            insertEdge(g,&e);

        }
    }
}

PUBLIC inline void insertEdge(Graph* g, Edge* e )
{
    g->matrix[virtualAddress(e->source,e->target,g->length)].weight = e->weight;
    g->matrix[virtualAddress(e->target,e->source,g->length)].weight = e->weight;
}

PUBLIC void printg(Graph* g)
{
    int i,j;
    for( i = 0 ; i < g->length ; ++i )
    {
        for( j = 0 ; j < g->length ; ++j )
        {
            printf("%5.0f ",g->matrix[virtualAddress(i,j,g->length)].weight);
        }
        printf("\n");
    }
}

PUBLIC inline int virtualAddress(int source ,int target ,int size )
{
    return source * size + target;
}
