#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MostrarPersonas(char *V[], int cantPersonas) {
    for (int i = 0; i < cantPersonas; i++) {
        printf("%s\n", V[i]);
    }
}

int BuscarNombre(char *palabra, char *V[], int cantPersonas){
    for (int i = 0; i < cantPersonas; i++)
    {
        if (strstr(V[i], palabra) != NULL)
        {
            return i; //retornamos la posicion del nombre si encuentra coincidencia
        }
    }

    return -1;
}

int main() {
    char *V[5];
    int cantPersonas = 5;
    char buff[100];
    char palabra[100];
    int pos;

    for (int i = 0; i < cantPersonas; i++) {
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        scanf("%s", buff);

        int longNombre = strlen(buff);
        V[i] = malloc((longNombre + 1) * sizeof(char));
        strcpy(V[i], buff);
    }

    MostrarPersonas(V, cantPersonas);

    printf("Ingrese una palabra clave: ");
    scanf("%s", &palabra);

    pos = BuscarNombre(palabra, V, cantPersonas);

    if(pos != -1){
        printf("Persona encontrada : %s", V[pos]);
    }else{
        printf("No hubo coincidencias con la palabra clave ingresada.");
    }

    for (int i = 0; i < cantPersonas; i++) {
        free(V[i]);
    }

    return 0;
}