//Archivo inout.h proyecto Miguel Pastoriza Santaclara
void stripe();
void headline();
void caratula();
int yes_or_no(char *mensaje);

void get_string (char *mensaje,char *la_cadena,int min, int max);
int get_integer(char *mensaje,short int *edad,int min, int max);
void get_character(char *mensaje,char *comparacion, char *la_cadena);
void display_patient (struct unPaciente *elPaciente,int *numero);
void archivo_pacientes (struct unPaciente *elPaciente, int *numero);


int verify_dni(char *dni);
