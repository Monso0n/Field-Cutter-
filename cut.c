#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "assign2funcs.h"
#define total 100

int argCount; //global Variables
char **argVector;

int main(int argc, char *argv[]){

    //Test code
    argCount = argc;
    argVector = argv;

    char str[] = "Hello World";

    //printf("%s\n", str);
    //printf("%i\n", argc);

    //for (int i = 0; i<argc; i++){
        //printf("Argument %d: [%s])\n",i,argv[i]);
    //}
    //printf("\n\n");
    
    //Real program
    if(checkArgVectorLen(argCount) == 1){ 
        terminateProgram(argVector);
    }

    if ( checkDelimiter(argv[1]) == 1 || checkDelimiter(argv[2]) == 1 ){
        terminateProgram(argVector);
    }

    char inputDelimiter[1]; //set input 
    strcpy(inputDelimiter, argv[1]);
    //printf("input dleim is %s\n", inputDelimiter);

    char outputDelimiter[1]; //and output delimiter
    strcpy(outputDelimiter, argv[2]);
    //printf("output dleim is %s\n", outputDelimiter);


    if(checkFields(argc, argv) == 1){  //check if fields are valid
        terminateProgram(argVector);
    }

    int *f;
    int fields[argc-3]; 

    f = getFields(argc, argv, fields); 

    //for (int i = 0; i<argc-3; i++){ //print fields
        //printf("%d\n", fields[i]);
    //}

    char line[1024];

    while (fgets(line, 1024, stdin)){
        printFields(line, fields, argc-3,inputDelimiter, outputDelimiter);
    }

    //terminateProgram(argVector);    
    
    return 0;

}
