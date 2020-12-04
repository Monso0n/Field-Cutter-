#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define total 100

void terminateProgram(char** argv){
    fprintf(stderr, "%s: specify input_delimiter output_delimiter and 1-%i fields in order\n", argv[0], total);
    exit(1);
}
int checkArgVectorLen(int argc) {
    if (argc<4){
        //printf("CLA missing");
        return 1;
    }
    return 0;
}
int checkDelimiter(char *delim){
    int len = strlen(delim);
    //printf("len of %s is %d\n", delim, len);

    if (len>1){
       // printf("Invalid delimiter size\n");
        return 1;
    }
    return 0;
}
int checkFields(int argc, char **argv){
    
    int last = 0;
    int current;

    for (int i = 3; i<argc; i++){
        
        //printf("argv[%d] is %s\n", i, argv[i]);

        char str[10];
        strcpy(str, argv[i]);

        //printf("str is %s\n", str);
        
        for (int o = 0; str[o]!='\0'; o++){  //check if all chars are digits
            if(isdigit(str[o]) == 0){
                //printf("Non-digit character exists in field %s\n", str); //if non-digit character is found, return
                return 1;
            }
        }

        //printf("%s is all numeric\n", str);
        current = atoi(argv[i]);
        //printf("Current: %i\n\n", current);
        
        if (current>100){
            //printf("Field %i is greater than 100\n", current);
            return 1;
        }
        
        if (current<1){
            //printf("Field %i is lesser than 1\n", current);
            return 1;
        }

        if (current<=last){ //if current field is smaller than or equal to the last, then return.
           // printf("The current field ( %d ) is smaller than or equal to the last field ( %d )\n", current, last);
            return 1;
        }
        else{
            last = current;
        }
    }
    return 0;
}
int *getFields(int argc, char **argv, int *fields){

    for (int i = 0; i<argc-3; i++){
        fields[i] = atoi(argv[3+i]);
    }

    return fields;

}
void printFields(char *line, int *fields, int size, char *id, char *od){

    char inputdelim = id[0];
    char outputdelim = od[0];

    char toPrint[1024];
    toPrint[0] = '\0';
    char temp[512];
    temp[0] = '\0';

    int targetField;
    int cur;



    for (int i = 0; i<size; i++){ //print fields
        targetField = fields[i];
        cur = 0;

        for (int o = 0; o<strlen(line); o++)
        {   
            if(line[o] == inputdelim){ //if line detects input delim, increment cur counter
               cur++; 
            }

            if(cur>targetField){ 
                //printf("\n[ %s ] is from field %i\n\n", temp,targetField);
                break;
            }

            if (cur == targetField-1 && inputdelim != line[o]){
                //printf("%c", line[o]);
                strncat(temp, &line[o], 1);
            }
        }
        strcat(toPrint, temp);
        strncat(toPrint, &outputdelim, 1);
        memset(temp, 0, sizeof temp); //clear temp
        
    }
    
    if (cur < fields[size-1]){ //if delimiter in line is lesser than max, then remove trailing output delimiter.
        toPrint[strlen(toPrint)-1] = '\0';  
    }
    if (cur < fields[0]){
        toPrint[strlen(toPrint)-1] = '\0';  
    }

    toPrint[strlen(toPrint)-1] = '\0';



    printf("%s\n", toPrint);
    memset(toPrint, 0, sizeof toPrint); //clear temp as it is static fsr
}