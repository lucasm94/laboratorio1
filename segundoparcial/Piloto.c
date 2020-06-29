#include "Piloto.h"

static char* id[] = {"1000", "2000", "3000", "4000", "5000"};
static char* nombres[] = {"Alex Lifeson", "Richard Bach", "John Kerry", "Erwin Rommel", "Stephen Coonts"};

Piloto* pilotoNuevo() {
    return (Piloto*) malloc(sizeof(Piloto));
}

Piloto* pilotoNuevoParametros(char* id,char* nombre) {
    Piloto* piloto = (Piloto*) malloc(sizeof(Piloto));
    piloto->id = atoi(id);
    strcpy(piloto->nombre, nombre);
    return piloto;
}

int pilotosMock(LinkedList* pilotos) {
    int res = -1;
    if(pilotos != NULL) {
        for(int i = 0; i < 5; i++) {
            Piloto* piloto = pilotoNuevoParametros(id[i], nombres[i]);
            ll_add(pilotos, piloto);
        }
        res = 1;
    }
    return res;
}

int pilotoSetId(Piloto* this,int id) {
    int res = -1;
    if(this != NULL && id != NULL) {
        this->id = id;
        res = 1;
    }
    return res;
}

int pilotoGetId(Piloto* this,int* id) {
    int res = -1;
    if(this != NULL && id != NULL) {
        *id = this->id;
        res = 1;
    }
    return res;
}

int pilotoSetNombre(Piloto* this,char* nombre) {
    int res = -1;
    if(this != NULL && nombre != NULL) {
        strcpy(this->nombre, nombre);
        res = 1;
    }
    return res;
}

int pilotoGetNombre(Piloto* this,char* nombre) {
    int res = -1;
    if(this != NULL && nombre != NULL) {
        strcpy(nombre, this->nombre);
        res = 1;
    }
    return res;
}

int comparaNombrePiloto(Piloto* this, char nombre[]) {
    int res = -1;
    if(this != NULL && strcmp(this->nombre, nombre) == 0) {
        res = 1;
    } else {
        res = 0;
    }
    return res;
}

void mostrarPilotos(LinkedList* linkedList) {
    int res = -1;
    if(linkedList != NULL && !ll_isEmpty(linkedList)) {
        int size = ll_len(linkedList);
        int id;
        char nombrePiloto[20];
        Piloto* auxP;
        printf("%10s %10s\n", "id", "nombre");
        for(int i=0; i<size; i++) {
            auxP = (Piloto*) ll_get(linkedList, i);
            pilotoGetId(auxP, &id);
            pilotoGetNombre(auxP, &nombrePiloto);
            printf("%10d %10s\n", id, nombrePiloto);
        }
        res = 1;
    }
    return res;
}
