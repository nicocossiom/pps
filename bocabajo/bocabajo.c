#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"

void incr (int *pint);

int main(int argc, char *argv[]){
    argv0="bocabajo";
    char lineas[2048 + 1]; //plus a '\0' character to mark the end of the string
    char **matrix;
    int n=0;
    if(argc<2){
        matrix=malloc(sizeof(char *));
        while(fgets(lineas, sizeof lineas, stdin)!=NULL){
            incr(&n);
            matrix=realloc(matrix, (sizeof(char *))*(n+1));
            if(matrix==NULL){
                Error(EX_OSERR, "No se pudo ubicar la memoria dinámica necesaria.");
            }
            matrix[n]=strdup(lineas);
        }
        while(n>=1){
            printf("%s", matrix[n]);
            n--;
        }
        free(matrix);
        exit(0);
    }
    else if(argc==2 && (strcmp(argv[1], "-h")==0 || strcmp(argv[1], "--help")==0) || strcmp(argv[1], "ayuda")==0){
        printf("bocabajo: Uso: bocabajo [ fichero... ]\n bocabajo: Invierte el orden de las lı́neas de los ficheros (o de la entrada).\n", stdout);
        exit(0);
    }
    int arg=1;
    matrix=malloc(sizeof(char *)*(n+1));
    while(argv[arg]!=NULL){
        FILE *ptr;
        char lineas[2049];
        ptr=fopen(argv[arg], "r");
        if(ptr!=NULL){
            while(fgets(lineas, sizeof (lineas), ptr)!=NULL){
                incr(&n);
                matrix=realloc(matrix, (sizeof(char *))*(n+1));
                if(matrix==NULL){
                    Error(EX_OSERR, "No se pudo ubicar la memoria dinámica necesaria.");
                }
                matrix[n]=strdup(lineas);
            }
            fclose(ptr);
            incr(&arg);
        }
        else{
            if (strstr(*ptr, ".txt")==1){
                Error(EX_NOINPUT, "El fichero \"%s\" no puede ser leido.", argv[arg]);
            }
          else{
            
          }
        }
    }
    while(n>=1){
        printf("%s", matrix[n]);
        char *aux=matrix[n];
        if(aux[strlen(aux)-1]!='\n'){
            printf("\n");
        }
        n--;
    }
    free(matrix);
    exit(0);
}
void incr (int *pint) {
    (*pint)++;
}