#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable
 // “CantidadProductosAPedir”
};


//iv)
float costoTotalProducto(struct Producto p){ // p es una variable del tipo struct Producto 
        return (p.Cantidad * p.PrecioUnitario);
}


int main (){

    //
    int cantClientes;
    struct Cliente *clientes; //puntero al bloque de clientes
    char buff[100];
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    srand(time(NULL));

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);

    clientes = malloc(cantClientes * sizeof(struct Cliente)); //resevo memoria para los clientes
    
    

    for (int i = 0; i < cantClientes; i++)
    {
        clientes[i].ClienteID = i + 1;
        printf("Ingrese el nombre del cliente %d: ", i + 1);
        scanf("%s", buff);
        clientes[i].NombreCliente = malloc((strlen(buff)+1) * sizeof(char)); //Reserva memoria para el nombre del cliente[i]
        strcpy(clientes[i].NombreCliente, buff); //Copia el nombre a esa memoria
        clientes[i].CantidadProductosAPedir = (rand()%5 + 1);
        clientes[i].Productos = malloc((clientes[i].CantidadProductosAPedir) * sizeof(struct Producto));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].Cantidad = (rand()%10 + 1);
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5 ]; //da valores de 0 a 4.
            clientes[i].Productos[j].PrecioUnitario = (rand() % 91 + 10); //rand() % (max - min + 1) + min
        }
        

    }


    printf("\n--INFORMACION CLIENTES--\n");

    for (int i = 0; i < cantClientes; i++)
    {
        float totalCliente = 0; //se declara dentro xq cada cliente tiene su propio total

        printf("ID Cliente: %d\n",clientes[i].ClienteID);
        printf("Nombre Cliente: %s\n",clientes[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d\n", clientes[i].CantidadProductosAPedir);
        

        printf("\n--PRODCUTOS--\n");
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("Tipo Producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("ID producto: %d\n",  clientes[i].Productos[j].ProductoID);
            printf("Cantidad Producto: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Precio Unitario: %f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("Costo total : %.2f\n", costoTotalProducto(clientes[i].Productos[j]));

            totalCliente += costoTotalProducto(clientes[i].Productos[j]); //el producto número j del cliente número i
        }

        printf("\nTOTAL A PAGAR: %.2f",totalCliente);
        
    }
    

    for (int i = 0; i < cantClientes; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }

    free(clientes);

    return 0;
}