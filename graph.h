//
// Created by Daniel Cardoso on 10/05/17.
//

#ifndef PROJECTPCV_GRAPH_H
#define PROJECTPCV_GRAPH_H

/*******************************************************************************
*                                 DEPENDENCIAS                                 *
********************************************************************************/

#import <stdlib.h>
#include "def.h"
#include "graphio.h"

/*******************************************************************************
*                                    MACROS                                    *
********************************************************************************/

#define newGraph(order) createGraph(order)

/*******************************************************************************
*                STRUCTS, UNIONS E OUTRAS ESTRUTURAS GLOBAIS                   *
********************************************************************************/

/* Armazena a ordem do graph G */
//static int order;

/*
 * Tipo Vertex representa um vertice do grafo G.
 * weight - representa o valor de uma posicao do grafo.
 * */
typedef struct vertex{
    double weight;
}Vertex;

/*
 * Tipo Graph representa o grafo G.
 * matrix - ponteiro que armazena a primeira posicao da estrutura grafo.
 * length - armazena a qtd de vertices do graph arbitrario G.
 */
typedef struct graph{
    Vertex* matrix;
    int length;
}Graph;

/*
 * Tipo Edge representa uma aresta.
 * source - representa o vertice u.
 * target - representa o vertice v.
 * weight - representa o peso da aresta{u,v}.
 */
typedef struct edge{
    int source;
    int target;
    double weight;
}Edge;

/*******************************************************************************
*                            PROTOTIPOS DE FUNCOES                             *
********************************************************************************/

PUBLIC Graph *createGraph(int);
PUBLIC void destroyGraph(Graph*);
PUBLIC void printg(Graph*);
PUBLIC void insertEdge(Graph*,Edge*);
PUBLIC Vertex getEdge(Graph*,int,int);
PUBLIC int virtualAddress(int,int,int);
PUBLIC void generateCompleteGraph(Graph*,void*);

#endif //PROJECTPCV_GRAPH_H
