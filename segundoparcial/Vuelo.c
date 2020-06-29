#include "Vuelo.h"

Vuelo* vueloNuevo() {
    return (Vuelo*) malloc(sizeof(Vuelo));
}
Vuelo* vueloNuevoParametros(char* id,char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* hsDespegue, char* hsLlegada) {
    Vuelo* vuelo = (Vuelo*) malloc(sizeof(Vuelo));
    vuelo->idVuelo = atoi(id);
    vuelo->idAvion = atoi(idAvion);
    vuelo->idPiloto = atoi(idPiloto);
    strcpy(vuelo->fecha, fecha);
    strcpy(vuelo->destino, destino);
    vuelo->cantPasajeros = atoi(cantPasajeros);
    vuelo->horaDespegue = atoi(hsDespegue);
    vuelo->horaLlegada = atoi(hsLlegada);
    return vuelo;
}

int vueloSetId(Vuelo* this,int id) {
    int res = -1;
    if(this != NULL && id != NULL) {
        this->idVuelo = id;
        res = 1;
    }
    return res;
}

int vueloGetId(Vuelo* this,int* id) {
    int res = -1;
    if(this != NULL && id != NULL) {
        *id = this->idVuelo;
        res = 1;
    }
    return res;
}

int vueloSetIdAvion(Vuelo* this,int idAvion) {
    int res = -1;
    if(this != NULL && idAvion != NULL) {
        this->idAvion = idAvion;
        res = 1;
    }
    return res;
}

int vueloGetIdAvion(Vuelo* this,int* idAvion) {
    int res = -1;
    if(this != NULL && idAvion != NULL) {
        *idAvion = this->idAvion;
        res = 1;
    }
    return res;
}

int vueloSetIdPiloto(Vuelo* this,int idPiloto) {
    int res = -1;
    if(this != NULL && idPiloto != NULL) {
        this->idPiloto = idPiloto;
        res = 1;
    }
    return res;
}

int vueloGetIdPiloto(Vuelo* this,int* idPiloto) {
    int res = -1;
    if(this != NULL && idPiloto != NULL) {
        *idPiloto = this->idPiloto;
        res = 1;
    }
    return res;
}

int vueloSetFecha(Vuelo* this,char* fecha) {
    int res = -1;
    if(this != NULL && fecha != NULL) {
        strcpy(this->fecha, fecha);
        res = 1;
    }
    return res;
}

int vueloGetFecha(Vuelo* this,char* fecha) {
    int res = -1;
    if(this != NULL && fecha != NULL) {
        strcpy(fecha, this->fecha);
        res = 1;
    }
    return res;
}

int vueloSetDestino(Vuelo* this,char* destino) {
    int res = -1;
    if(this != NULL && destino != NULL) {
        strcpy(this->destino, destino);
        res = 1;
    }
    return res;
}

int vueloGetDestino(Vuelo* this,char* destino) {
    int res = -1;
    if(this != NULL && destino != NULL) {
        strcpy(destino, this->destino);
        res = 1;
    }
    return res;
}

int vueloSetCantPasajeros(Vuelo* this,int cantPasajeros) {
    int res = -1;
    if(this != NULL && cantPasajeros != NULL) {
        this->cantPasajeros = cantPasajeros;
        res = 1;
    }
    return res;
}

int vueloGetCantPasajeros(Vuelo* this,int* cantPasajeros) {
    int res = -1;
    if(this != NULL && cantPasajeros != NULL) {
        *cantPasajeros = this->cantPasajeros;
        res = 1;
    }
    return res;
}

int vueloSetHoraDespegue(Vuelo* this,int hsDespegue) {
    int res = -1;
    if(this != NULL && hsDespegue != NULL) {
        this->horaDespegue = hsDespegue;
        res = 1;
    }
    return res;
}

int vueloGetHoraDespegue(Vuelo* this,int* hsDespegue) {
    int res = -1;
    if(this != NULL && hsDespegue != NULL) {
        *hsDespegue = this->horaDespegue;
        res = 1;
    }
    return res;
}

int vueloSetHoraLlegada(Vuelo* this,int hsLlegada) {
    int res = -1;
    if(this != NULL && hsLlegada != NULL) {
        this->horaLlegada = hsLlegada;
        res = 1;
    }
    return res;
}

int vueloGetHoraLlegada(Vuelo* this,int* hsLlegada) {
    int res = -1;
    if(this != NULL && hsLlegada != NULL) {
        *hsLlegada = this->horaLlegada;
        res = 1;
    }
    return res;
}

int cantidadPasajeros(Vuelo* this) {
    int res = -1;
    if(this != NULL) {
        res = this->cantPasajeros;
    }
    res;
}

int cantidadPasajerosAIrlanda(Vuelo* this) {
    int res = -1;
    if(this != NULL && strcmp(this->destino, PAIS_A_FILTRAR) == 0) {
        res = this->cantPasajeros;
    }
    return res;
}

int vuelosCortos(Vuelo* this) {
    int res = -1;
    if(this != NULL && (this->horaLlegada - this->horaDespegue) < 3) {
        res = 1;
    } else {
        res = 0;
    }
    res;
}

int vuelosAPortugal(Vuelo* this) {
    int res = -1;
    if(this != NULL && strcmp(this->destino, PAIS_A_MOSTRAR) == 0) {
        res = 1;
    } else {
        res = 0;
    }
    return res;
}

int vuelosSinPiloto(Vuelo* this) {
    int res = -1;
    if(this != NULL && this->idPiloto != ID_PILOTO_A_FILTRAR) {
        res = 1;
    } else {
        res = 0;
    }
    return res;
}
