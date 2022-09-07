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
    int precio;
    int costo;
};

struct producto{
    constProducto producto;
    int cantidad;
    int ventas;
    int utilidad;
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
    constProducto WhiteMocca = {"White Mocca", 32.0, 19.0};
    constProducto Americano = {"Cafe Americano", 22.0, 13.2};
    constProducto Latte = {"Latte", 24.0, 17.2};
    constProducto ToffeCoffee = {"Toffe Coffee", 28.0, 20.1};
    constProducto Cappuccino = {"Cappuccino", 24.0, 17.2};
    constProducto SmoresLatte = {"Smores Latte", 32.0, 13.0};
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


