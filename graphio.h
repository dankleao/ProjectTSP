//
// Created by Daniel Cardoso on 10/05/17.
//

#ifndef PROJECTPCV_GRAPHIO_H
#define PROJECTPCV_GRAPHIO_H

/*******************************************************************************
*                                 DEPENDENCIAS                                 *
********************************************************************************/

#import <stdio.h>
#include <math.h>
#include "graph.h"
#include "def.h"

/*******************************************************************************
*                                    MACROS                                    *
********************************************************************************/

/* Macro para obter dados da entrada padrao */
#define inputStream(bff,in) (fgets(bff,sizeof(bff),in) != NULL)

#define OPEN_FILE(infoFile) fileG = fopen(infoFile.name,infoFile.attr)
#define READLINE_FILE inputStream(buffer,fileG)
#define CLOSE_FILE() fclose(fileG);

/* Macro determina a largura maxima( quantidade de caracteres por linha ) da entrada de dados */
#define input_width 12

/*******************************************************************************
*                STRUCTS, UNIONS E OUTRAS ESTRUTURAS GLOBAIS                   *
********************************************************************************/

PRIVATE FILE * fileG;

typedef char* string;// Define o tipo string

/* Buffer para armazenar dados da entrada padrao */
PUBLIC char buffer[input_width];

typedef struct info_file{
    char* name;
    char* attr;
}InfoFile;

/*******************************************************************************
*                            PROTOTIPOS DE FUNCOES                             *
********************************************************************************/
PUBLIC void* readGraph(InfoFile*);

#endif //PROJECTPCV_GRAPHIO_H
