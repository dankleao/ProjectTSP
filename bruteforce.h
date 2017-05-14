//
// Created by Daniel Cardoso on 13/05/17.
//

#ifndef PROJECTPCV_BRUTEFORCE_H
#define PROJECTPCV_BRUTEFORCE_H

/*******************************************************************************
*                                 DEPENDENCIAS                                 *
********************************************************************************/

#include "def.h"
#include "tsp.h"
#include "graph.h"

/*******************************************************************************
*                                    MACROS                                    *
********************************************************************************/

#define SIZE_G (graphPtr->length)

/*******************************************************************************
*                STRUCTS, UNIONS E OUTRAS ESTRUTURAS GLOBAIS                   *
********************************************************************************/

PRIVATE int counter = 0;
PRIVATE int arbitraryVertex = 0;
PRIVATE int *p;
PRIVATE Graph* graphPtr;

/*******************************************************************************
*                            PROTOTIPOS DE FUNCOES                             *
********************************************************************************/

PUBLIC BestRoute* bruteForce(Graph*,int);
PRIVATE void initialization( int vector[] );
PRIVATE inline void setArbitraryVertex(int);
PRIVATE inline void setGraph(Graph*);
PRIVATE inline Graph* getGraph();
PRIVATE void initPermutation(int[]);
PRIVATE void permutation(int[],int);
PRIVATE void walk();


#endif //PROJECTPCV_BRUTEFORCE_H
