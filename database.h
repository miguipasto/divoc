//Archivo database.h proyecto Miguel Pastoriza Santalcra
struct unPaciente{
  char nombre[25];
  char dni[10];
  short int edad;
  int fiebre;
  int tos;
  char sintoma[2];
};

int p_register(struct unPaciente *nuevoPaciente,int *numero);
int p_discharge(struct unPaciente *elPaciente, int *numero);
int p_list(struct unPaciente *elPaciente, int *numero); 
int p_search(struct unPaciente *elPaciente,int *numero);
void p_mark(struct unPaciente *elPaciente,int *numero);
int p_exit(struct unPaciente *elPaciente,int *numero);
