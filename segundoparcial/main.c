#include "LinkedList.h"
#include "Controller.h"

int main()
{
    LinkedList* miLista = ll_newLinkedList();
    LinkedList* pilotos = ll_newLinkedList();
    controller_monzon_cargarArchivo(PATH_FILE_PILOTO, pilotos, PILOTO);
    controller_monzon_cargarPilotosMock(pilotos);

    int opcion, count;

    do {

        opcion = opcionMenu(PAIS_A_FILTRAR, PAIS_A_MOSTRAR, PILOTO_A_FILTRAR);

        switch(opcion) {
            case 1:
                if(controller_monzon_cargarArchivo(PATH_FILE_R, miLista, VUELO)) {
                    printf("se cargo el archivo\n");
                } else {
                    printf("No se pudieron cargar los vuelos\n");
                }
                break;
            case 2:
                if(controller_monzon_mostrarVuelos(miLista, pilotos)){
                } else {
                    printf("No se pudieron mostrar los vuelos\n");
                }
                break;
            case 3:
                count = controller_monzon_cantidadPasajerosTotales(miLista);
                if(count != -1){
                    printf("La cantidad de pasajeros totales es: %d\n", count);
                } else {
                    printf("No se pudo mostrar la cantidad de pasajeros totales\n");
                }
                break;
            case 4:
                count = controller_monzon_cantidadPasajerosFiltrado(PAIS_A_FILTRAR, miLista);
                if(count != -1) {
                    printf("La cantidad de pasajeros a %s es: %d\n", PAIS_A_FILTRAR, count);
                } else {
                    printf("No se pudo mostrar la cantidad de pasajeros a %s\n", PAIS_A_FILTRAR);
                }
                break;
            case 5:
                if(controller_monzon_generarArchivoVuelosCortos(PATH_FILE_W, miLista)) {
                } else {
                    printf("No se pudo generar el archivo\n");
                }
                break;
            case 6:
                if(controller_monzon_mostrarVuelosAPais(PAIS_A_MOSTRAR, miLista, pilotos)) {
                } else {
                    printf("No se pudieron mostrar los vuelos a %s\n", PAIS_A_MOSTRAR);
                }
                break;
            case 7:
                if(controller_monzon_mostrarVueloSinPiloto(PILOTO_A_FILTRAR, miLista, pilotos)) {
                } else {
                    printf("No se pudieron mostrar los vuelos sin el piloto %s\n", PILOTO_A_FILTRAR);
                }
                break;
            case 8:
                if(controller_monzon_mostrarPilotosSinPiloto(pilotos)) {
                } else {
                    printf("No se pudieron mostrar los pilotos filtrados\n");
                }
                break;
        }

        if(opcion != 9) {
            system("read -p 'Presionar enter para continuar...' var");
        }
        system("clear");

    } while(opcion != 9);

    return 0;
}
