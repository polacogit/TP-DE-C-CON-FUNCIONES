#include <stdio.h>


typedef struct {
    int id;
    char titulo[50];
    char descripcion[500];
    int dificultad;
    char fechaCreacion[50];
    char fechaVencimiento[50];
    int estado;

} Tarea;


// FUNCION PARA VER TAREAS
void verTareas(Tarea tareas[], int cantidad)
{
    int i;
    int opcionVer;

    if(cantidad == 0) {
        printf("No se cargo ninguna tarea.\n");
        return;
    }

    printf("1. Todas\n");
    printf("2. Pendientes\n");
    printf("3. En curso\n");
    printf("4. Terminadas\n");
    printf("Opcion: ");
    scanf("%d", &opcionVer);

    while(opcionVer < 1)
    {
        printf("Opcion invalida. Ingrese una opcion del 1 al 4: ");
        scanf("%d", &opcionVer);
    }

    while(opcionVer > 4)
    {
        printf("Opcion invalida. Ingrese una opcion del 1 al 4: ");
        scanf("%d", &opcionVer);
    }

    for(i = 0; i < cantidad; i++) {

        if(opcionVer == 1) {

            printf("\nID: %d\n", tareas[i].id);
            printf("Titulo: %s\n", tareas[i].titulo);
            printf("Descripcion: %s\n", tareas[i].descripcion);
            printf("Dificultad: %d\n", tareas[i].dificultad);

            printf("Estado: ");

            if(tareas[i].estado == 0)
                printf("Pendiente\n");
            else if(tareas[i].estado == 1)
                printf("En curso\n");
            else if(tareas[i].estado == 2)
                printf("Terminada\n");

            printf("Fecha de creacion: %s\n", tareas[i].fechaCreacion);
            printf("Fecha de vencimiento: %s\n", tareas[i].fechaVencimiento);
            printf("----------------------\n");
        }

        else if(opcionVer == 2) {

            if(tareas[i].estado == 0) {

                printf("\nID: %d\n", tareas[i].id);
                printf("Titulo: %s\n", tareas[i].titulo);
                printf("Descripcion: %s\n", tareas[i].descripcion);
                printf("Dificultad: %d\n", tareas[i].dificultad);
                printf("Estado: Pendiente\n");
                printf("Fecha de creacion: %s\n", tareas[i].fechaCreacion);
                printf("Fecha de vencimiento: %s\n", tareas[i].fechaVencimiento);
                printf("----------------------\n");
            }
        }

        else if(opcionVer == 3) {

            if(tareas[i].estado == 1) {

                printf("\nID: %d\n", tareas[i].id);
                printf("Titulo: %s\n", tareas[i].titulo);
                printf("Descripcion: %s\n", tareas[i].descripcion);
                printf("Dificultad: %d\n", tareas[i].dificultad);
                printf("Estado: En curso\n");
                printf("Fecha de creacion: %s\n", tareas[i].fechaCreacion);
                printf("Fecha de vencimiento: %s\n", tareas[i].fechaVencimiento);
                printf("----------------------\n");
            }
        }

        else if(opcionVer == 4) {

            if(tareas[i].estado == 2) {

                printf("\nID: %d\n", tareas[i].id);
                printf("Titulo: %s\n", tareas[i].titulo);
                printf("Descripcion: %s\n", tareas[i].descripcion);
                printf("Dificultad: %d\n", tareas[i].dificultad);
                printf("Estado: Terminada\n");
                printf("Fecha de creacion: %s\n", tareas[i].fechaCreacion);
                printf("Fecha de vencimiento: %s\n", tareas[i].fechaVencimiento);
                printf("----------------------\n");
            }
        }
    }
}


// FUNCION PARA BUSCAR TAREA
void buscarTarea(Tarea tareas[], int cantidad)
{
    int i;
    int idBuscado;

    if(cantidad == 0) {
        printf("No hay tareas cargadas.\n");
        return;
    }

    printf("Buscar tarea\n");
    printf("Ingrese el ID de la tarea: ");
    scanf("%d", &idBuscado);

    while(idBuscado < 1)
    {
        printf("El ID debe ser mayor que 0.\n");
        printf("Ingrese nuevamente el ID: ");
        scanf("%d", &idBuscado);
    }

    for(i = 0; i < cantidad; i++) {

        if(tareas[i].id == idBuscado) {

            printf("\nID: %d\n", tareas[i].id);
            printf("Titulo: %s\n", tareas[i].titulo);
            printf("Descripcion: %s\n", tareas[i].descripcion);
            printf("Dificultad: %d\n", tareas[i].dificultad);

            printf("Estado: ");

            if(tareas[i].estado == 0)
                printf("Pendiente\n");
            else if(tareas[i].estado == 1)
                printf("En curso\n");
            else if(tareas[i].estado == 2)
                printf("Terminada\n");

            printf("Fecha de creacion: %s\n", tareas[i].fechaCreacion);
            printf("Fecha de vencimiento: %s\n", tareas[i].fechaVencimiento);

            return;
        }
    }

    printf("No se encontro una tarea con ese ID.\n");
}


// FUNCION PARA AGREGAR TAREA
int agregarTarea(Tarea tareas[], int cantidad)
{
    if(cantidad == 100) {
        printf("No se pueden agregar mas tareas.\n");
        return cantidad;
    }

    printf("Agregar tarea\n");

    tareas[cantidad].id = cantidad + 1;

    printf("Ingrese el titulo: ");
    scanf("%s", tareas[cantidad].titulo);

    printf("Ingrese la descripcion: ");
    scanf("%s", tareas[cantidad].descripcion);

    printf("Ingrese la dificultad: ");
    scanf("%d", &tareas[cantidad].dificultad);

    while(tareas[cantidad].dificultad < 1)
    {
        printf("La dificultad debe estar entre 1 y 5.\n");
        printf("Ingrese nuevamente la dificultad: ");
        scanf("%d", &tareas[cantidad].dificultad);
    }

    while(tareas[cantidad].dificultad > 5)
    {
        printf("La dificultad debe estar entre 1 y 5.\n");
        printf("Ingrese nuevamente la dificultad: ");
        scanf("%d", &tareas[cantidad].dificultad);
    }

    printf("Ingrese la fecha de creacion: ");
    scanf("%s", tareas[cantidad].fechaCreacion);

    printf("Ingrese la fecha de vencimiento: ");
    scanf("%s", tareas[cantidad].fechaVencimiento);

    tareas[cantidad].estado = 0;

    cantidad++;

    printf("Tarea agregada correctamente.\n");

    return cantidad;
}


// FUNCION PARA EDITAR TAREA
void editarTarea(Tarea tareas[], int cantidad)
{
    int i;
    int idBuscado;

    if(cantidad == 0) {
        printf("No hay tareas cargadas.\n");
        return;
    }

    printf("Ingrese el ID de la tarea a editar: ");
    scanf("%d", &idBuscado);

    while(idBuscado < 1)
    {
        printf("El ID debe ser mayor que 0.\n");
        printf("Ingrese nuevamente el ID: ");
        scanf("%d", &idBuscado);
    }

    for(i = 0; i < cantidad; i++) {

        if(tareas[i].id == idBuscado) {

            printf("Nuevo titulo: ");
            scanf("%s", tareas[i].titulo);

            printf("Nueva descripcion: ");
            scanf("%s", tareas[i].descripcion);

            printf("Nueva dificultad: ");
            scanf("%d", &tareas[i].dificultad);

            while(tareas[i].dificultad < 1)
            {
                printf("La dificultad debe estar entre 1 y 5.\n");
                printf("Ingrese nuevamente la dificultad: ");
                scanf("%d", &tareas[i].dificultad);
            }

            while(tareas[i].dificultad > 5)
            {
                printf("La dificultad debe estar entre 1 y 5.\n");
                printf("Ingrese nuevamente la dificultad: ");
                scanf("%d", &tareas[i].dificultad);
            }

            printf("Nuevo estado: ");
            scanf("%d", &tareas[i].estado);

            while(tareas[i].estado < 0)
            {
                printf("Estado invalido.\n");
                printf("0 = Pendiente\n");
                printf("1 = En curso\n");
                printf("2 = Terminada\n");
                printf("Ingrese nuevamente el estado: ");
                scanf("%d", &tareas[i].estado);
            }

            while(tareas[i].estado > 2)
            {
                printf("Estado invalido.\n");
                printf("0 = Pendiente\n");
                printf("1 = En curso\n");
                printf("2 = Terminada\n");
                printf("Ingrese nuevamente el estado: ");
                scanf("%d", &tareas[i].estado);
            }

            printf("Nueva fecha de creacion: ");
            scanf("%s", tareas[i].fechaCreacion);

            printf("Nueva fecha de vencimiento: ");
            scanf("%s", tareas[i].fechaVencimiento);

            printf("Tarea modificada correctamente.\n");

            return;
        }
    }

    printf("No se encontro una tarea con ese ID.\n");
}


// MAIN
int main()
{
    Tarea tareas[100];

    int cantidad = 0;
    int opcion = 0;

    while(opcion != 5) {

        printf("\nHola, ¿que desea hacer?\n");
        printf("1. ver tareas\n");
        printf("2. buscar tarea\n");
        printf("3. agregar tarea\n");
        printf("4. editar tarea\n");
        printf("5. salir\n");
        printf("Opcion: ");

        scanf("%d", &opcion);

        while(opcion < 1)
        {
            printf("Opcion invalida. Ingrese una opcion del 1 al 5: ");
            scanf("%d", &opcion);
        }

        while(opcion > 5)
        {
            printf("Opcion invalida. Ingrese una opcion del 1 al 5: ");
            scanf("%d", &opcion);
        }

        switch(opcion) {

            case 1:
                verTareas(tareas, cantidad);
                break;

            case 2:
                buscarTarea(tareas, cantidad);
                break;

            case 3:
                cantidad = agregarTarea(tareas, cantidad);
                break;

            case 4:
                editarTarea(tareas, cantidad);
                break;

            case 5:
                printf("Salir\n");
                break;
        }
    }

    return 0;
}