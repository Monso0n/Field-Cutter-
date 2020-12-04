void terminateProgram(char **argv); //function prototypes
int checkDelimiter(char *delim);
int checkArgVectorLen(int argc);
int checkFields(int argc, char **argv); 
int *getFields(int argc, char **argv, int *fields);
void printFields(char *line, int *fields,int size,char *id, char *od);
