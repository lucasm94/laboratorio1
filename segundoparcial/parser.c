#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vuelo.h"
#include "Piloto.h"

/** \brief Parsea los datos de los vuelos desde archivo csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parserVueloFromText(FILE* pFile, LinkedList* pArrayList) {
    if(pFile != NULL && pArrayList != NULL) {
        char id[20], idAvion[20], idPiloto[20], fecha[30], destino[20], cantPasajeros[20], hsDespegue[20], hsLlegada[20];
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, idAvion, idPiloto, fecha, destino, cantPasajeros, hsDespegue, hsLlegada);
        while(!feof(pFile)) {
            if(feof(pFile)) {
                break;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, idAvion, idPiloto, fecha, destino, cantPasajeros, hsDespegue, hsLlegada);
            Vuelo* vuelo = vueloNuevoParametros(id, idAvion, idPiloto, fecha, destino, cantPasajeros, hsDespegue, hsLlegada);
            ll_add(pArrayList, vuelo);
        }
        fclose(pFile);
        return 1;
    }
    return 0;
}

/** \brief Parsea los datos de los pilotos desde archivo csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 int parserPilotoFromText(FILE* pFile, LinkedList* pArrayList) {
    if(pFile != NULL && pArrayList != NULL) {
        char id[20], nombre[20];
        fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
        while(!feof(pFile)) {
            if(feof(pFile)) {
                break;
            }
            fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
            Piloto* piloto = pilotoNuevoParametros(id, nombre);
            ll_add(pArrayList, piloto);
        }
        fclose(pFile);
        return 1;
    }
    return 0;
}
