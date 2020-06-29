#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "Properties.h"

typedef struct {
    int id;
    char nombre[20];
} Piloto;
Piloto* pilotoNuevo();
Piloto* pilotoNuevoParametros(char* id,char* nombre);
int pilotosMock(LinkedList* pilotos);
int pilotoSetId(Piloto* this,int id);
int pilotoGetId(Piloto* this,int* id);
int pilotoSetNombre(Piloto* this,char* nombre);
int pilotoGetNombre(Piloto* this,char* nombre);
int comparaNombrePiloto(Piloto* this, char nombre[]);
void mostrarPilotos(LinkedList* pilotos);

#endif // PILOTO_H_INCLUDED
