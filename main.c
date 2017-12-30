/* 
 * File:   main.c
 * Author: Iván Larios López
 *
 * Created on 11 de diciembre de 2017, 18:14
 */

#include <stdio.h>
#include <windows.h>
#include <string.h>

int leerquantum(char *res, FILE *fich){
int quantum;
char cadena[100], formato[8]="quantum", auxformat[100];
fscanf(fich,"%[a-z0-9]:%d\n",auxformat, &quantum);
if (quantum==0||strcmp(formato,auxformat)) printf("El formato de quantum es incorrecto. Escribalo con el siguiente formato: quantum:n \n");
else {
 printf("El valor del quantum es %d\n", quantum);
return quantum;
}
}

int nprocesos(char *res, FILE *fich){
int nprocesos;
char cadena[100], formato[8]="nproces", auxformat[100];
fscanf(fich,"%[a-z0-9]:d\n", auxformat, &nprocesos);
//printf("%s\n%s\n%d\n",auxformat, formato,nprocesos); //Esto es solo para probar porque las ptas cadenas no coinciden
if (nprocesos==0/*||strcmp(formato,auxformat)*/) printf("El formato de nprocesos es incorrecto. Escribalo con el siguiente formato: nprocesos:n \n");
else {
printf("El nprocesos es es %d\n",nprocesos);
res = fgets(cadena,100,fich);
return nprocesos;
}
}

void leerprocesos(char *res, FILE *fich, int llegadas[], int duraciones[], int nproceso){
int i = 0;
char cadena[100];
do{
fscanf(fich,"%d",&llegadas[i]);
printf("El proceso %d llega en  %d  ||",i ,llegadas[i]);
i++;
} while (i<nproceso);
i=0;
printf ("\n");
res = fgets(cadena,100,fich);
do{
fscanf(fich,"%d",&duraciones[i]);
printf("El proceso %d dura %d  ||",i ,duraciones[i]);
i++;
} while (i<nproceso);
i=0;
}



void leer(){
int quantum, nproceso;
FILE *fich = fopen("C:\\PRUEBASDESO\\fichero.txt","r");
char *res;
quantum= leerquantum(res, fich);
nproceso= nprocesos(res, fich);
int llegadas[nproceso], duraciones[nproceso];
leerprocesos(res, fich, llegadas, duraciones, nproceso);
fclose(fich);
}


int main (int argc, char *argv[]) {
    char fichero[100];
    printf("Por favor, introduzca la ruta completa del fichero de entrada: ");
    scanf("%s",&fichero);
    printf("\n");
    leer();
    /*
float dato1[10];
int i=0;
FILE *fich = fopen("C:\\PRUEBASDESO\\fichero.txt","r");
char cadena[100];
char *res;
do{
fscanf(fich,"%f",&dato1[i]);
printf("Leído dato %d: %f  ||",i ,dato1[i]);
i++;
} while (i<4);
i=0;
res = fgets(cadena,100,fich);
printf ("\n");
while (res!=NULL){
do{
fscanf(fich,"%f",&dato1[i]);
printf("Leído dato %d: %f  ||",i ,dato1[i]);
i++;
} while (i<4);
printf ("\n");
i=0;
res = fgets(cadena,100,fich);
} 
fclose(fich); 
     */
}
