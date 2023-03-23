//Archivo inout.c proyecto Miguel Pastoriza Santaclara

#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#include <stdlib.h>

#include "database.h"
#include "inout.h"

#define TITULO "DIVOC_" 
#define CARACTER_1 '-'
#define CARACTER_2 '|'


#define P_REGISTER 'R'
#define P_SEARCH 'S'
#define P_DISCHARGE 'D'
#define P_LIST 'L'
#define P_MARK 'P'
#define P_EXIT 'X'


#define SYM_F 'F'
#define SYM_S 'S'
#define SYM_T 'T'
#define SYM_M 'M'
#define SYM_N 'N'


void stripe(){

  int j;
  
  for(j=0;j<50;j++){
    printf("%c",CARACTER_1); }
  
  return ;
}


void headline () {

  int i,j;

  int numEspacios;
  numEspacios=((50-2-strlen(TITULO))/2);

  printf("\n%c",CARACTER_2);

  for(i=0;i<numEspacios;i++){
    printf(" ");}
  printf("%s",TITULO);

  for(j=0;j<numEspacios;j++){
    printf(" ");}
  printf("%c\n",CARACTER_2);
 
  return;         
}


int yes_or_no (char *mensaje) {

  char lectura[256];
  char decision;
  char extra_char[256];
  int num_valores;
  int salir=0;
  
  do{

    printf("%s",mensaje);
    fgets(lectura,sizeof(lectura),stdin);

    if (strlen(lectura)==1){
    }
    else {
      num_valores=sscanf(lectura,"%c%s",&decision,extra_char);
      
      if (num_valores==1){
	if(toupper(decision)=='Y' || toupper(decision)=='N')
	  salir=1;
	else
	  salir=0;
      }
    }
  } while (salir!=1);
  
  if (toupper(decision)=='Y')
    return 1;
  else
    return 0;
}
      
void get_string (char *mensaje,char *cadena,int min,int max){

  char palabra[max];
  char extra_char[256];
  char lectura[256];
  int valores;
  int longuitud;
  longuitud=0;
  
  do{
    printf("%s",mensaje);
    
    fgets(lectura,sizeof(lectura),stdin);

    if (strlen(lectura)==1){
    }
    else{
	valores=sscanf(lectura,"%s%s",palabra,extra_char);
	if (valores==1)
	  longuitud=strlen(palabra);
    }
  } while (longuitud<min || longuitud > max);

  if (min==max){
    palabra[8]=toupper(palabra[8]);
  }
  strcpy(cadena,palabra);
  return; 
}

int get_integer(char *mensaje,short int *edad,int min, int max){
  
  int numero;
  int valores;
  int salir=0;
  char lectura[256];
  char extra_char[256];
  
  do{
    
    printf("%s",mensaje);
    
    fgets(lectura,sizeof(lectura),stdin);

    if(strlen(lectura)==1){
    }
    else{
      valores=sscanf(lectura,"%d%s",&numero,extra_char);
      if (valores==1)
	salir=1;
    }
  } while (numero<min || numero > max || salir!=1);

  return(*edad=numero);
}

int verify_dni(char *dni){
  
  int i;
  char indice_dni[]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};

  i=atoi(dni);
  i=i%23;

  if (toupper(dni[8])==toupper(indice_dni[i]))
    return 1;
  else
    return 0;
}


void get_character (char *mensaje,char *comparacion,char *la_cadena){

  char lectura[256];
  char caracter;
  char extra_char[256];
  int num_valores;
  int salir=0;

  do{

    printf("\n%s (%s):",mensaje,comparacion);
    
    fgets(lectura,sizeof(lectura),stdin);

    if (strlen(lectura)==1){
    }
    else {
      num_valores=sscanf(lectura,"%c%s",&caracter,extra_char);
      if (num_valores==1){
	caracter=toupper(caracter);
	if (strchr(comparacion,caracter)!=NULL){
	  strcpy(la_cadena,&caracter);
	  salir=1;
	}
      }   
    }
  }while (salir!=1);
  
  return;
}

void display_patient (struct unPaciente *elPaciente,int *numero){

  int i;
  i=(*numero);
  
  printf(">\t%s;%s;%d;%d;%d;%s;\n",elPaciente[i].nombre,elPaciente[i].dni,elPaciente[i].edad,elPaciente[i].fiebre,elPaciente[i].tos,elPaciente[i].sintoma);
}


void archivo_pacientes (struct unPaciente *elPaciente, int *numero){


  char cadena[256];

  FILE *pacientes;

  if ((pacientes=fopen("patients.txt","r"))!=NULL){
    while((fgets(cadena,sizeof(cadena),pacientes))!=NULL){
      sscanf(cadena,"%s %s %hd %d %d %c",elPaciente[*numero].nombre,elPaciente[*numero].dni,&elPaciente[*numero].edad,&elPaciente[*numero].fiebre,&elPaciente[*numero].tos,elPaciente[*numero].sintoma);
      (*numero)++;
    }

    fclose(pacientes);
    return;
  }
}

void caratula(){
  stripe();
  headline();
  stripe();
  printf("\n");
  return;
}
    
