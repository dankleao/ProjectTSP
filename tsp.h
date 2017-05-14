//
// Created by Daniel Cardoso on 10/05/17.
//

#ifndef PROJECTPCV_TSP_H
#define PROJECTPCV_TSP_H

#include "def.h"
#include "graphio.h"
#include "graph.h"

/*******************************************************************************
*                                    MACROS                                    *
********************************************************************************/

#define distance( cityA, cityB ) sqrt( pow( cityA.coordinate.x - cityB.coordinate.x, 2) + pow( cityA.coordinate.y - cityB.coordinate.y, 2 ) )

/*******************************************************************************
*                STRUCTS, UNIONS E OUTRAS ESTRUTURAS GLOBAIS                   *
********************************************************************************/

/* Estrutura representa as coordenadas de uma cidade  */
struct coordinates{
    int x;
    int y;
};

/* Estrutura armazena a coordenada (x,y) de uma cidade arbitraria */
typedef struct city{
    struct coordinates coordinate;
}City;

typedef struct best_route{
    double distance;
    char* path;
}BestRoute;

enum Algorithm
{
    BRUTE_FORCE = 1,
    BRANCH_AND_BOUND ,
    GENERIC_ALGORITHM
};

typedef struct algorithm{
    BestRoute* (*func) (Graph*,int);
}Algorithm;

/*******************************************************************************
*                            PROTOTIPOS DE FUNCOES                             *
********************************************************************************/

PUBLIC void initTSP(char,InfoFile*);
PUBLIC void setCity(City*);

#endif //PROJECTPCV_TSP_H
