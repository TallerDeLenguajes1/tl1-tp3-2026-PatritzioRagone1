#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MostrarPersonas(char *V[], int cantPersonas) {
    for (int i = 0; i < cantPersonas; i++) {
        printf("%s\n", V[i]);
    }
}

void BuscarNombre(int id, char *V[], int cantPersonas) {
    if (id >= 0 && id < cantPersonas) {
        printf("Persona encontrada: %s\n", V[id]);
    } else {
        printf("no se encontro el valor buscado\n");
    }
}

int main() {
    char *V[5];
    int cantPersonas = 5;
    char buff[100];
    int id;

    for (int i = 0; i < cantPersonas; i++) {
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        scanf("%s", buff);

        int longNombre = strlen(buff);
        V[i] = malloc((longNombre + 1) * sizeof(char));
        strcpy(V[i], buff);
    }

    MostrarPersonas(V, cantPersonas);

    printf("Ingrese un ID: ");
    scanf("%d", &id);

    BuscarNombre(id, V, cantPersonas);

    for (int i = 0; i < cantPersonas; i++) {
        free(V[i]);
    }

    return 0;
}