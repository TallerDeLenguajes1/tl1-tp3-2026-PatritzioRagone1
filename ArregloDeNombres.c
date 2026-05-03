#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MostrarPersonas(char *V[], int cantPersonas) {
    for (int i = 0; i < cantPersonas; i++) {
        printf("%s\n", V[i]);
    }
}


int BuscarNombrePorPalabra(char *palabra, char *V[], int cantPersonas){
    for (int i = 0; i < cantPersonas; i++)
    {
        if (strstr(V[i], palabra) != NULL)
        {
            return i; //retornamos la posicion del nombre si encuentra coincidencia
        }
    }

    return -1;
}


void BuscarNombrePorId(int id, char *V[], int cantPersonas) {
    if (id >= 0 && id < cantPersonas) {
        printf("Persona encontrada: %s\n", V[id]);
    } else {
        printf("no se encontro el valor buscado\n");
    }
}


int main() {
    //Declaracion de variables:
    char **V; //V va a apuntar a un vector de punteros a nombres
    int cantPersonas;
    char buff[100];
    char palabra[100];
    int pos,id, opcion;
    
    //pedimos la cantidad de personas:
    printf("Ingrese la cantidad de Personas: ");
    scanf("%d", &cantPersonas);

    V = malloc(cantPersonas * sizeof(char *)); 

    printf("\n-------CARGA DE NOMBRES-------\n");
    for (int i = 0; i < cantPersonas; i++) {
        printf("Ingrese el nombre de la persona %d: \n", i + 1);
        scanf("%s", buff);//lee el nombre que escribe el usuario y lo guarda temporalmente en buff(sin "&")

        int longNombre = strlen(buff);                      
        V[i] = malloc((longNombre + 1) * sizeof(char)); //segun la longitud de cada nombre ingresado pedimos el espacio a ocupar en la memoria
        strcpy(V[i], buff); //copiamos lo que hay en el buff en nuestro vector V segun la posicion i.
    }

    //mostramos los nombres cargados:
    MostrarPersonas(V, cantPersonas);


    //interfaz de usuario:
    printf("\n -MENU DE BUSQUEDA-\n");
    printf("1.BUSCAR POR ID \n");
    printf("2.BUSCAR POR NOMBRE \n");
    printf("Ingrese una opcion: ");
    scanf("%d", opcion);

    if (opcion == 1)
    {
        printf("Ingrese un ID: ");
        scanf("%d", &id);
        BuscarNombrePorId(id, V, cantPersonas);
    }else if (opcion == 2)
    {
        printf("Ingrese una palabra clave: ");
        scanf("%s", palabra);

        pos = BuscarNombrePorPalabra(palabra, V, cantPersonas);

        if(pos != -1){
            printf("Persona encontrada : %s", V[pos]);
        }else{
            printf("No hubo coincidencias con la palabra clave ingresada.");
        }
        
    }else
    {
        printf("OPCION INVALIDA.\n");
    }
    
    //liberamos memoria:
    for (int i = 0; i < cantPersonas; i++) {
        free(V[i]);
    }

    free(V);

    return 0;
}