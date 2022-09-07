/*---------------------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* Autor: Diego Alejandro Morales Escobar
* Curso:       CC3086 - Programación de microprocesadores     Ciclo II - 2022
------------------------------------------------------------------------------*/

#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <iostream>

using namespace std;

//Variables globales
const int productos = 8;
const int nMeses = 2;


//Estructuras

struct constProducto{
    string nombre;
    double precio;
    double costo;
};

struct producto{
    constProducto producto;
    int cantidad;
    double ventas;
    double utilidad;
};

struct mes{
    string nombre; 
    producto productos[productos];
    double totalVentas;
    double totalUtilidad;
    double CostosVariables;
};

mes meses[nMeses];

void VentasMensuales(){
    constProducto PastelChocolate = {"Pastel de chocolate", 60.0, 20.0};
    constProducto WhiteMocca = {"White Mocca", 32.0, 19.20};
    constProducto Americano = {"Cafe Americano", 22.0, 13.2};
    constProducto Latte = {"Latte", 24.0, 17.2};
    constProducto ToffeCoffee = {"Toffe Coffee", 28.0, 20.1};
    constProducto Cappuccino = {"Cappuccino", 24.0, 17.2};
    constProducto SmoresLatte = {"Smores Latte", 32.0, 23.0};
    constProducto CafeMolido = {"Cafe Tostado Molido", 60.0, 20.0};

    meses[0].nombre = "Julio";
    meses[0].productos[0]= {PastelChocolate, 300};
    meses[0].productos[1]= {WhiteMocca, 400};
    meses[0].productos[2]= {Americano, 1590};
    meses[0].productos[3]= {Latte, 200};
    meses[0].productos[4]= {ToffeCoffee, 390};
    meses[0].productos[5]= {Cappuccino, 1455};
    meses[0].productos[6]= {SmoresLatte, 800};
    meses[0].productos[7]= {CafeMolido, 60};
    meses[0].CostosVariables = 45640.0;

    meses[1].nombre = "Agosto";
    meses[1].productos[0]= {PastelChocolate, 250};
    meses[1].productos[1]= {WhiteMocca, 380};
    meses[1].productos[2]= {Americano, 800};
    meses[1].productos[3]= {Latte, 250};
    meses[1].productos[4]= {ToffeCoffee, 600};
    meses[1].productos[5]= {Cappuccino, 1200};
    meses[1].productos[6]= {SmoresLatte, 1540};
    meses[1].productos[7]= {CafeMolido, 15};
    meses[1].CostosVariables = 40590.0;
}

void DataMes(mes* mes){
    double totalVentas = 0;
    double totalUtilidad = 0;
    for(auto producto : mes->productos){
        totalVentas += producto.ventas; 
        totalUtilidad += producto.utilidad;
    }
    mes->totalVentas = totalVentas;
    mes->totalUtilidad = totalUtilidad - mes->CostosVariables;
}

void* DataProducto(void *args){
    auto *producto = (struct producto*) args;
    double precio = producto->producto.precio;
    double costo = producto->producto.costo;
    int cantidad = producto->cantidad;
    producto->ventas = precio * cantidad;
    producto->utilidad = producto->ventas - (producto->cantidad * producto->producto.costo);
    pthread_exit(NULL);
}

void reporte(mes* mes){
    //print linea de separacion
    printf("\n--------------------------------------------\n");
    printf("\nReporte de ventas del mes de %s \n", mes->nombre.c_str());
    printf("\n--------------------------------------------\n");
    printf("\nVentas por producto: \n");
    for(auto producto : mes->productos){
        //print nombre del produto, Q. y ventas del producto
        cout << producto.producto.nombre << " Q." << producto.ventas << endl;
    }
    //print linea de separacion
    printf("\n--------------------------------------------\n");
    //print utilidad del producto 
    printf("\nUtilidad por por producto: \n");
    for(auto producto : mes->productos){
        //print nombre del produto, Q. y utilidad del producto
        cout << producto.producto.nombre << " Q." << producto.utilidad << endl;
    }
    //print linea de separacion
    printf("\n--------------------------------------------\n");
    //print total de ventas del mes
    cout << "Total de ventas del mes: Q. " << mes->totalVentas << endl;
    cout << "Costos variables del mes: Q. " << mes->CostosVariables << endl;
    cout << "Utilidad neta del mes: Q. " << mes->totalUtilidad << endl;
}

int main(){
    VentasMensuales(); 
    pthread_t threads[productos * nMeses];
    int i = 0;
    for(auto &mes : meses){
        for(auto &producto : mes.productos){
            pthread_create(&threads[i], NULL, &DataProducto, (void *)&producto);
            i++;
        }
        pthread_join(threads[i-1], NULL);
        DataMes(&mes);
        reporte(&mes);
    }
}


