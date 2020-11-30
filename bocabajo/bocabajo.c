#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"

void incr (int *pint);

int main(int argc, char *argv[]){
    argv0="bocabajo";
    char lineas[2048 + 1]=NULL; //plus a '\0' character to mark the end of the string
    char **arrLineas=NULL;
    int counter=0;
    if(argc<2){
        arrLineas=malloc(sizeof(char *));
        while(fgets(lineas, sizeof lineas, stdin)!=NULL){
            incr(&counter);
            arrLineas=realloc(arrLineas, (sizeof(char *))*(counter+1));
            if(arrLineas==NULL){
                Error(EX_OSERR, "No se pudo ubicar la memoria dinámica necesaria.");
            }
            arrLineas[counter]=strdup(lineas); }
        while(counter>=1){ 
            printf("%s", arrLineas[counter]); 
            counter--; } 
            free(arrLineas); 
            exit(0); } 
            else if(argc==2 && (strcmp(argv[1], "-h")==0 || strcmp(argv[1], "--help")==0) || strcmp(argv[1], "ayuda")==0){ 
                printf("bocabajo: Uso: bocabajo [ fichero... ]\n bocabajo: Invierte el orden de las lineas de los ficheros (o de la entrada).\n", stdout);
            exit(0);
    }
    int numfile = sizeof(argv[])/sizeof (*char);
    arrLineas=malloc(sizeof(char *)*(counter+1));
    while(argv[numfile]!=NULL){
        FILE *ptr;
        char *lineas[2048 + 1];
        ptr=fopen(argv[numfile], "r");
        if(ptr!=NULL){
            while(fgets(lineas, sizeof (lineas), ptr)!=NULL){
                counter++;
                arrLineas=realloc(arrLineas, (sizeof(char *))*(counter+1));
                if(arrLineas==NULL){
                    Error(EX_OSERR, "Fallo al ubicar datos en memoria dinamica");
                }
            strcpy(arrLineas[counter], strdup(lineas));
            }
            fclose(ptr);
            numfile--;
        }
        else{
            
          }
        }
    }
    while(counter>=1){
        printf("%s", arrLineas[counter]);
        char *aux=arrLineas[counter];
        if(aux[strlen(aux)-1]!='\n'){
            printf("\n");
        }
        counter--;
    }
    free(arrLineas);
    exit(0);
}