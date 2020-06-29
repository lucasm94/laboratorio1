#include "Controller.h"
#include "parser.h"

/** \brief Carga los datos de los vuelos desde archivo csv (modo texto).
 *
 * \param path char*
 * \param linkedList LinkedList*
 * \param tipo char
 * \return int
 *
 */
int controller_monzon_cargarArchivo(char* path, LinkedList* linkedList, char tipo) {
    int res = -1;
    if(linkedList != NULL) {
        FILE * pFile;
        pFile = fopen(path, "r");
        if(pFile != NULL) {
            if(tipo == VUELO) {
                parserVueloFromText(pFile, linkedList);
                res = 1;
            } else if(tipo == PILOTO) {
                parserPilotoFromText(pFile, linkedList);
                res = 1;
            }
        }
        res = 1;
    }
    return res;
}

/** \brief Muestra los datos de los vuelos.
 *
 * \param linkedList LinkedList*, lista de vuelos
 * \param linkedListP LinkedList*, lista de pilotos
 * \return int
 *
 */
int controller_monzon_mostrarVuelos(LinkedList* linkedList, LinkedList* linkedListP) {
    int res = -1;
    if(linkedList != NULL && linkedListP != NULL && !ll_isEmpty(linkedList) && !ll_isEmpty(linkedListP)) {
        int size = ll_len(linkedList);
        int sizeP = ll_len(linkedListP);
        int id, idAvion, idPiloto, cantPasajeros, hsDespegue, hsLlegada, i, j, idAuxPiloto;
        char fecha[20], destino[20], nombrePiloto[20];
        Vuelo* aux;
        Piloto* auxP;
        printf("%10s %10s %20s %20s %15s %15s %10s %10s\n", "idVuelo", "idAvion", "piloto", "fecha", "destino", "pasajeros", "despegue", "llegada");
        for(i=0; i<size; i++) {
            aux = (Vuelo*) ll_get(linkedList, i);
            vueloGetId(aux, &id);
            vueloGetIdAvion(aux,&idAvion);
            vueloGetIdPiloto(aux, &idPiloto);
            vueloGetFecha(aux,&fecha);
            vueloGetDestino(aux, &destino);
            vueloGetCantPasajeros(aux, &cantPasajeros);
            vueloGetHoraDespegue(aux, &hsDespegue);
            vueloGetHoraLlegada(aux, &hsLlegada);
            auxP = ll_get(linkedListP, 0);
            pilotoGetId(auxP, &idAuxPiloto);
            pilotoGetNombre(auxP, &nombrePiloto);
            for(j = 0; j < sizeP -1 && idPiloto != idAuxPiloto; j++) {
                auxP = ll_get(linkedListP, j+1);
                pilotoGetId(auxP, &idAuxPiloto);
                pilotoGetNombre(auxP, &nombrePiloto);
            }
            printf("%10d %10d %20s %20s %15s %15d %10d %10d\n", id, idAvion, nombrePiloto, fecha, destino, cantPasajeros, hsDespegue, hsLlegada);
        }
        res = 1;
    }
    return res;
}

/** \brief Cantidad de pasajeros totales.
 *
 * \param linkedList LinkedList*
 * \return int
 *
 */
int controller_monzon_cantidadPasajerosTotales(LinkedList* linkedList) {
    int res = -1;
    if(linkedList != NULL && !ll_isEmpty(linkedList)) {
        res = ll_count(linkedList, cantidadPasajeros);
    }
    return res;
}

/** \brief Cantidad de pasajeros que volaron a un destino.
 *
 * \param pais char*
 * \param linkedList LinkedList*
 * \return int
 *
 */
int controller_monzon_cantidadPasajerosFiltrado(char* pais, LinkedList* linkedList) {
    int res = -1;
    if(linkedList != NULL && !ll_isEmpty(linkedList)) {
        res = ll_count(linkedList, cantidadPasajerosAIrlanda);
    }
    return res;
}

/** \brief Genera un archivo con los vuelos de viajes cortos.
 *
 * \param path char*
 * \param linkedList LinkedList*
 * \return int
 *
 */
int controller_monzon_generarArchivoVuelosCortos(char* path, LinkedList* linkedList) {
    int res = -1;
    if(linkedList != NULL && !ll_isEmpty(linkedList)) {
        LinkedList* filterList = ll_filter(linkedList, vuelosCortos);
        if(controller_monzon_generarArchivoComoTexto(path, filterList)!=-1){
            res = 1;
        }
    }
    return res;
}

/** \brief Muestra los vuelos a un destino.
 *
 * \param pais char*
 * \param linkedList LinkedList*
 * \param listPilotos LinkedList*
 * \return int
 *
 */
int controller_monzon_mostrarVuelosAPais(char* pais, LinkedList* linkedList, LinkedList* listPilotos) {
    int res = -1;
    if(linkedList != NULL && listPilotos != NULL && !ll_isEmpty(linkedList) && !ll_isEmpty(listPilotos)) {
        LinkedList* filterList = ll_filter(linkedList, vuelosAPortugal);
        if(controller_monzon_mostrarVuelos(filterList, listPilotos)!=-1) {
            res = 1;
        }
    }
    return res;
}

/** \brief Muestra los vuelos filtrando un piloto.
 *
 * \param path char*
 * \param nombrePiloto char*
 * \param linkedList LinkedList*
 * \param listPilotos LinkedList*
 * \return int
 *
 */
int controller_monzon_mostrarVueloSinPiloto(char* nombrePiloto, LinkedList* linkedList, LinkedList* listPilotos) {
    int res = -1;
    if(linkedList != NULL && !ll_isEmpty(linkedList)) {
        LinkedList* filterList = ll_filter(linkedList, vuelosSinPiloto);
        if(controller_monzon_mostrarVuelos(filterList, listPilotos)!=-1) {
            res = 1;
        }
    }
    return res;
}

/** \brief Carga lista de pilotos.
 *
 * \param linkedList LinkedList*
 * \return int
 *
 */
int controller_monzon_cargarPilotosMock(LinkedList* linkedList) {
    int res = -1;
    if(linkedList != NULL) {
        pilotosMock(linkedList);
        res = 1;
    }
    return res;
}

/** \brief Guarda los datos de los vuelos a un archivo csv (modo texto).
 *
 * \param path char*
 * \param linkedList LinkedList*
 * \return int
 *
 */
int controller_monzon_generarArchivoComoTexto(char* path , LinkedList* linkedList) {
    int res = -1;
    if(linkedList != NULL && !ll_isEmpty(linkedList)) {
        FILE* archivo;
        archivo = fopen(path,"w");
        if(archivo!=NULL) {
            int len = ll_len(linkedList);
            int id, idAvion, idPiloto, cantPasajeros, hsDespegue, hsLlegada;
            char fecha[20], destino[20];
            fprintf(archivo,"idVuelo,idAvion,piloto,fecha,destino,pasajeros,despegue,llegada\n");
            for(int i=0; i<len; i++) {
                Vuelo* aux = (Vuelo*) ll_get(linkedList, i);
                vueloGetId(aux, &id);
                vueloGetIdAvion(aux,&idAvion);
                vueloGetIdPiloto(aux, &idPiloto);
                vueloGetFecha(aux,&fecha);
                vueloGetDestino(aux, &destino);
                vueloGetCantPasajeros(aux, &cantPasajeros);
                vueloGetHoraDespegue(aux, &hsDespegue);
                vueloGetHoraLlegada(aux, &hsLlegada);
                fprintf(archivo,"%d,%d,%d,%s,%s,%d,%d,%d\n", id, idAvion, idPiloto, fecha, destino, cantPasajeros, hsDespegue, hsLlegada);
            }
            fclose(archivo);
            printf("Datos guardados\n");
            res = 1;
        } else {
            printf("No se pudieron guardar los datos\n");
        }
    }
    return res;
}

/** \brief Muestra los pilotos filtrando un piloto.
 *
 * \param listPilotos LinkedList*
 * \return int
 *
 */
int controller_monzon_mostrarPilotosSinPiloto(LinkedList* linkedList) {
    int res = -1;
    if(linkedList != NULL) {
        char nombre[20];
        printf("Ingrese nombre del piloto: ");
        __fpurge(stdin);
        fgets(nombre, 20, stdin);
        nombre[strlen(nombre)-1]='\0';
        LinkedList* pilotos = ll_filter_parametro(linkedList, comparaNombrePiloto, nombre);
        mostrarPilotos(pilotos);
        res = 1;
    }
    return res;
}
