#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"
#include "Vuelo.h"
#include "Piloto.h"

int controller_monzon_cargarArchivo(char* path, LinkedList* linkedList, char tipo);
int controller_monzon_mostrarVuelos(LinkedList* linkedList, LinkedList* linkedListP);
int controller_monzon_cantidadPasajerosTotales(LinkedList* linkedList);
int controller_monzon_cantidadPasajerosFiltrado(char* pais, LinkedList* linkedList);
int controller_monzon_generarArchivoVuelosCortos(char* path, LinkedList* linkedList);
int controller_monzon_mostrarVuelosAPais(char* pais, LinkedList* linkedList, LinkedList* listPilotos);
int controller_monzon_mostrarVueloSinPiloto(char* nombrePiloto, LinkedList* linkedList, LinkedList* listPilotos);
int controller_monzon_cargarPilotosMock(LinkedList* linkedList);
int controller_monzon_generarArchivoComoTexto(char* path , LinkedList* pArrayList);
int controller_monzon_mostrarPilotosSinPiloto(LinkedList* pArrayList);

#endif // CONTROLLER_H_INCLUDED
