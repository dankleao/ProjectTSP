//
// Created by Daniel Cardoso on 10/05/17.
//

/*******************************************************************************
*                                 DEPENDENCIAS                                 *
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"
#include "graphio.h"
#include "tsp.h"

/*******************************************************************************
*                                    MACROS                                    *
********************************************************************************/

#define err(arg) printf("Command line arguments: %s!\n", arg ); exit(1)

/*******************************************************************************
*                            PROTOTIPOS DE FUNCOES                             *
********************************************************************************/

PUBLIC int evaluateExpression(char *[]);

/*******************************************************************************
*                STRUCTS, UNIONS E OUTRAS ESTRUTURAS GLOBAIS                   *
********************************************************************************/

PRIVATE char * token[] = { "-help", "-f", "-b", "-g" };

/*******************************************************************************
*                                   MAIN()                                     *
********************************************************************************/

PUBLIC int main(int argc , char * argv[] )
{
	switch(argc)
	{
		case 1:
			printf("%s\n", "Use ./program [-help] to execute program correctly" );
			err("no input values");
		case 2:
			if( ! strcmp( argv[1], token[0] ) )
			{
				printf("\nOptions line command:%s%s%s%s%s\n",
					   "\n\n List options:\n",
					   "\n\t-f to [Brute Force] \n\t-b to [Branch and Bounds] \n\t-g to [Generic algorithm]\n",
					   "\n How to use:\n",
					   "\n\t./program [-option] [name_of_file]\n",
					   "\n*OBS: Use spaces to separate the options\n" );
				break;
			}
			else
			{
				err("invalid sentence [need more parameters]" );
			}
		case 3:
			if ( evaluateExpression(argv) )
            {
				InfoFile infoFile = {argv[2],"r"};
				initTSP((*(++argv[1])),&infoFile);
            }
			break;
		default:
			err("number of args exceed");
	}
	return 0;
}

/*******************************************************************************
*                                IMPLEMENTATIONS                               *
********************************************************************************/

PUBLIC int evaluateExpression( char * argv[] )
{
	if( !((strlen(argv[1]) != 2) ^ (strlen(argv[1]) != 5)) )
		return 0;

	int i = 0;
	while( ++i < 4 )
		if( ! strcmp( argv[1], token[i] ) ) return 1;
    return 0;
}

