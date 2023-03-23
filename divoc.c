//Archivo divoc.c proyecto Miguel Pastoriza Santaclara

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


int main (){

  char opcion[2];
  int salir = 0;

  struct unPaciente losPacientes[250]; 
  int numPacientes;
  numPacientes=0;

  archivo_pacientes(losPacientes,&numPacientes);
  
  caratula();


  do{
    printf("\n\nR) Register a patient\n");
    printf("S) Search for a patient\n");
    printf("D) Discharge a patient\n");
    printf("L) List patients by age\n");
    printf("P) Mark positive\n");
    printf("\nX) Exit the program");

    get_character("\nChoose an option","RSDLPX",opcion);

    
    switch(toupper(opcion[0])){
    case P_REGISTER:
      p_register(losPacientes, &numPacientes);
      break;
    case P_SEARCH:
      p_search(losPacientes,&numPacientes);
      break;
    case P_DISCHARGE:
      p_discharge(losPacientes,&numPacientes);
      break;
    case P_LIST:
      p_list(losPacientes,&numPacientes);
      break;
    case P_MARK:
      p_mark(losPacientes,&numPacientes);
      break;
    case P_EXIT:
      salir=p_exit(losPacientes,&numPacientes);
      if (salir==1){
      }
      break;
    default:
      printf("\nError de seleccion\n");
      
    
    }
       
    
  }while(salir!=1);
  
  return 0;
}

