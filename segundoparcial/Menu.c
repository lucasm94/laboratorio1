int opcionMenu(char* paisAFiltrar, char* paisAMostrar, char* pilotoAFiltrar) {
    int opcion;
    printf("--- Menu ---\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir vuelos\n");
    printf("3. Cantidad de pasajeros totales\n");
    printf("4. Cantidad de pasajeros a %s\n", paisAFiltrar);
    printf("5. Filtrar vuelos cortos\n");
    printf("6. Listar vuelos a %s\n", paisAMostrar);
    printf("7. Filtrar a %s\n", pilotoAFiltrar);
    printf("8. Filtrar piloto\n");
    printf("9. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
