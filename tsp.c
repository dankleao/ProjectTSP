//
// Created by Daniel Cardoso on 10/05/17.
//

/*******************************************************************************
*                                 DEPENDENCIAS                                 *
********************************************************************************/

#include "tsp.h"
#include "genericalgorithm.h"
#include "branchbound.h"
#include "bruteforce.h"

/*******************************************************************************
*                                IMPLEMENTATIONS                               *
********************************************************************************/

PUBLIC void initTSP(char opt,InfoFile* infoFile)
{
    //enum Algorithm algorithm = BRUTE_FORCE;
    Algorithm algorithm = {bruteForce};
    switch ( opt )
    {
        case 'f':
            //algorithm = BRUTE_FORCE;
            break;
        case 'b':
            //algorithm = BRANCH_AND_BOUND;
            algorithm.func = branchBound;
            break;
        case 'g':
            //algorithm = GENERIC_ALGORITHM;
            algorithm.func = genericAlgorithm;
            break;
        default:
            break;
    }
    Graph* g = (Graph*) readGraph(infoFile);
    BestRoute* bestRoutePtr = algorithm.func(g,0);
    destroyGraph(g);
    printf("Distance: %5.0f\nPath:%s\n",bestRoutePtr->distance,bestRoutePtr->path);
}

PUBLIC void setCity( City* city )
{
    register int i = -1;
    while (*(buffer + ++i) != ' ');
    city->coordinate.x = atoi(buffer);
    city->coordinate.y = atoi((buffer + ++i));
}

