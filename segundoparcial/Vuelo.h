#ifndef VUELOS_H_INCLUDED
#define VUELOS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "Properties.h"

typedef struct {
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[20];
    char destino[20];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
} Vuelo;

Vuelo* vueloNuevo();
Vuelo* vueloNuevoParametros(char* id,char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* hsDespegue, char* hsLlegada);
int vueloSetId(Vuelo* this,int id);
int vueloGetId(Vuelo* this,int* id);
int vueloSetIdAvion(Vuelo* this,int idAvion);
int vueloGetIdAvion(Vuelo* this,int* idAvion);
int vueloSetIdPiloto(Vuelo* this,int idPiloto);
int vueloGetIdPiloto(Vuelo* this,int* idPiloto);
int vueloSetFecha(Vuelo* this,char* fecha);
int vueloGetFecha(Vuelo* this,char* fecha);
int vueloSetDestino(Vuelo* this,char* destino);
int vueloGetDestino(Vuelo* this,char* destino);
int vueloSetCantPasajeros(Vuelo* this,int cantPasajeros);
int vueloGetCantPasajeros(Vuelo* this,int* cantPasajeros);
int vueloSetHoraDespegue(Vuelo* this,int hsDespegue);
int vueloGetHoraDespegue(Vuelo* this,int* hsDespegue);
int vueloSetHoraLlegada(Vuelo* this,int hsLlegada);
int vueloGetHoraLlegada(Vuelo* this,int* hsLlegada);
int cantidadPasajeros(Vuelo* this);
int cantidadPasajerosAIrlanda(Vuelo* this);
int vuelosCortos(Vuelo* this);
int vuelosAPortugal(Vuelo* this);
int vuelosSinPiloto(Vuelo* this);

/*
int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);
*/


#endif // VUELOS_H_INCLUDED
