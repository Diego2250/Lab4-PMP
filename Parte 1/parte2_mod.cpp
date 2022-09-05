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

pthread_mutex_t mutex;
float total = 0;
void *serie(void *arg){
    float resultado = 0.0; 
    float *n = (float *)arg;
    float n_sum = *n; 
    pthread_mutex_lock(&mutex);
    resultado = 1/((n_sum)*(n_sum+1));
    total = total + resultado;
    pthread_mutex_unlock(&mutex);
    printf("Cuando n es: %.0f el resultado es: %.5f\n", *n, total);  

}
using namespace std;
int main(void) { 
    int valor_n; 
    pthread_t threads;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_mutex_init(&mutex, NULL);
    printf("Ingrese el numero maximo: ");
    scanf("%d", &valor_n);
    //imprime valor n
    printf("Valor n: %d\n", valor_n);
    int i;
    for(i = 1; i <= valor_n; i++){
        float j = (float)i;
        pthread_create(&threads, &attr, serie, (void *)&j);
        pthread_join(threads, NULL);
        
    }
    printf("El resultado de la serie es: %.5f\n", total);
    pthread_attr_destroy(&attr);
	pthread_exit(NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}