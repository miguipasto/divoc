//Archivo database.c proyecto Miguel Pastoriza Santaclara

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

int p_register(struct unPaciente *nuevoPaciente, int *numero){

  int tos;
  int fiebre;
  short int edad;
  char sintoma[256];
  char nombre[256];
  char dni[256];
  
  printf("\nRegister\n");

  
  get_string("\nName (1-24 char):",nombre,1,24);
  
  do{
    get_string("\nDNI (9-9 char):",dni,9,9);
    if (verify_dni(dni)==0){
      printf("\nInvalid DNI");
    }
  } while(verify_dni(dni)==0);
  
  get_integer("\nDate [1900-2020]:",&edad,1900,2020);
  
  fiebre=yes_or_no("\nFever (y/n):");
  
  tos=yes_or_no("\nCough (y/n):");
  
  get_character("Symptom","FSTMN",sintoma);


  
  strcpy(nuevoPaciente[*numero].nombre,nombre);
  strcpy(nuevoPaciente[*numero].dni,dni);
  nuevoPaciente[*numero].edad=edad;
  nuevoPaciente[*numero].fiebre=fiebre;
  nuevoPaciente[*numero].tos=tos;
  strcpy(nuevoPaciente[*numero].sintoma,sintoma);
      

  printf("\nNew patient:\n");
  
  display_patient(nuevoPaciente,numero);

  (*numero)++;



  return 0;
}

int p_search(struct unPaciente *elPaciente,int *numero){

  char busqueda[10];
  int i;
  int comprobacion=0;
 
  printf("\nSearch\n\n");

  if((*numero)==0)
    printf("\nNo patients yet\n");
  else{
    
    do{
     get_string("\nDNI (9-9 char):",busqueda,9,9);
     for (i=0;i<(*numero);i++){
       if(strcmp(busqueda,elPaciente[i].dni)==0){
	 printf("\nPatient data:\n");
	 display_patient(elPaciente,&i);
	 i=(*numero);
	 comprobacion=1;
       }
       else
	 comprobacion=0;
     }
     if (comprobacion!=1){
       printf("\nUnknown patient\n");
       comprobacion=1;
     }
    } while(comprobacion!=1);
    
  }
  return 0;
}

int p_discharge (struct unPaciente *elPaciente, int *numero){
  
  char busqueda[10];
  int i,j;
  int comprobacion=0;
 
  printf("\nDischarge\n");

  if((*numero)==0)
    printf("\nNo patients yet\n");
  else{
    
    do{
     get_string("\nDNI (9-9 char):",busqueda,9,9);
     for (i=0;i<(*numero);i++){
       
       if(strcmp(busqueda,elPaciente[i].dni)==0){
	 for(j=i;j<(*numero);j++){
	   elPaciente[j]=elPaciente[j+1];
	 }
	 printf("\nDischarged patient\n");
	 comprobacion=1;
	 (*numero)--;
       }
     }
     if (comprobacion!=1){
       printf("\nUnknown patient\n");
       comprobacion=1;
     }
     
    } while(comprobacion!=1);
    
  }
  return 0;
}

int p_list (struct unPaciente *elPaciente, int *numero){

  short int edad_busqueda;
  int i;

  printf("\nList\n\n");
 
  if((*numero)==0){
    printf("No patients yet\n");
  }
  else{
    do{
      get_integer("\nDate [1900-2020]:",&edad_busqueda,1900,2020);
      printf("\nPatients born before %d:\n",edad_busqueda);
      for(i=0;i<(*numero);i++){
	if (edad_busqueda>=elPaciente[i].edad){
	  display_patient(elPaciente,&i);
	}
	else {
	}
      }
    }while(edad_busqueda<1900 || edad_busqueda>2020);
  }
   
  return 0;
}


void p_mark(struct unPaciente *elPaciente,int *numero){
  int i;

  printf("\nPositives\n\n");

  if((*numero)==0){
    printf("No patients yet\n");
  }
  else{
    printf("Positive patients:\n");
    for(i=0;i<(*numero);i++){
      if(elPaciente[i].fiebre==1 && elPaciente[i].tos==1 && strcmp("N",elPaciente[i].sintoma)!=0){
	display_patient(elPaciente,&i);
      }}}      
}

int p_exit(struct unPaciente *elPaciente,int *numero){
  
  FILE *paciente;
  int i;
  
  printf("\nExit\n");

  if(yes_or_no("\nAre you sure you want to exit the program? (y/n) : ")==1){

    paciente=fopen("patients.txt","w");

    for(i=0;i<(*numero);i++){
      fprintf(paciente,"%s %s %d %d %d %s\n",elPaciente[i].nombre,elPaciente[i].dni,elPaciente[i].edad,elPaciente[i].fiebre,elPaciente[i].tos,elPaciente[i].sintoma);
    }
    fclose(paciente);
    return 1;
  }
  else
    return 0;
}
 



    
    
      

