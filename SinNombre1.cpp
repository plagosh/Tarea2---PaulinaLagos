#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

struct locales{
	char nombre[10];
	int posicionx;
	int posiciony;
	int NBufferLocales;
}local1 = {"Pizza 1", 1, 1, 9}, 
 local2 = {"Pizza 2", 4, 1, 7}, 
 local3 = {"Sandwich", 3, 3, 5}, 
 local4 = {"Sushi 1", 4, 4, 11}, 
 local5 = {"Sushi 2", 1, 4, 7};

struct vehiculos{
	int ID;
	int posicionInicialx;
	int posicionInicialy;
	//0 esta desocupado
	bool flag;
	int NBufferVehiculos;
}vehiculo0 = {1, 5, 3, 0, 3},
 vehiculo1 = {2, 5, 3, 0, 3}, 
 vehiculo2 = {3, 5, 3, 0, 3},
 vehiculo3 = {4, 5, 3, 0, 3},
 vehiculo4 = {5, 5, 3, 0, 3},
 vehiculo5 = {6, 5, 3, 0, 3},
 vehiculo6 = {7, 5, 3, 0, 3},
 vehiculo7 = {8, 5, 3, 0, 3},
 vehiculo8 = {9, 5, 3, 0, 3},
 vehiculo9 = {10, 5, 3, 0, 3};

void mostrarArreglo(int b[][2], int tamano){
	for(int i = 0; i < tamano; i++){
		for( int j = 0; j < 2; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int llenarLocal(int b[][2], int tamano){
	for(int i = 0; i < tamano; i++){
		for( int j = 0; j < 2; j++){
			double tiempo = 1 + rand()%2;
			if(tiempo < 3 && tiempo != 0){
				b[i][1] = 1 + rand()%5;
			}
			b[i][2] = 1 + rand()%5;
		}
	}
}

//se movera primero en el eje x
void desplazamiento(int x1, int y1, int x2, int y2){
	while(x1 != x2){
		if(x1 > x2){
			x1 = x1 - 1;
			printf("Me movi a la izquierda a %i\n", x1);
		}else{
			x1 = x1 + 1;
			printf("Me movi a la derecha a %i\n", x1);
		}
	}
	
	while(y1 != y2){
		if(y1 > y2){
			y1 = y1 - 1;
			printf("Me movi hacia abajo a %i\n", y1);
		}else{
			y1 = y1 + 1;
			printf("Me movi hacia arriba a %i\n", x1);
		}
	}
	
	printf("Ya llegue!\n");
}

void* thread_local1_function(void* );
void* thread_local2_function(void* );
void* thread_local3_function(void* );
void* thread_local4_function(void* );
void* thread_local5_function(void* );
sem_t sem1;

int main(void){
	cout<<"Los locales se encuentran en las siguientes posiciones: \n";
	int cuadras[5][5] = {{4,0,0,0,5},{0,0,0,0,3},{0,0,0,0,0},{1,0,0,0,2}};
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout<<cuadras[i][j];
		}
		cout<<"\n";
	}	

	pthread_t thread_local1, thread_local2, thread_local3, thread_local4, thread_local5;
	
	sem_init(&sem1, 0, 1);
	
	pthread_create(&thread_local1, NULL, thread_local1_function, NULL);
	pthread_create(&thread_local2, NULL, thread_local2_function, NULL);
	pthread_create(&thread_local3, NULL, thread_local3_function, NULL);
	pthread_create(&thread_local4, NULL, thread_local4_function, NULL);
	pthread_create(&thread_local5, NULL, thread_local5_function, NULL);
	
	pthread_join(thread_local1, NULL);
	pthread_join(thread_local2, NULL);
	pthread_join(thread_local3, NULL);
	pthread_join(thread_local4, NULL);
	pthread_join(thread_local5, NULL);
	
	int bufferVehiculo1[vehiculo0.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	int bufferVehiculo2[vehiculo1.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	int bufferVehiculo3[vehiculo2.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	int bufferVehiculo4[vehiculo3.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	int bufferVehiculo5[vehiculo4.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	int bufferVehiculo6[vehiculo5.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	int bufferVehiculo7[vehiculo6.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	int bufferVehiculo8[vehiculo7.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	int bufferVehiculo9[vehiculo8.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	int bufferVehiculo10[vehiculo9.NBufferVehiculos][2] = {{1,2},{1,2},{1,2}};
	
	printf("El buffer del vehiculo 1 es\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			cout<<bufferVehiculo1[i][j];
		}
		cout<<"\n";
	}
	
	getch();			 
	return 0;
}

void* thread_local1_function(void* ){
	sem_wait(&sem1);
	printf("\nLa posicion de la %s es: x=%i y=%i\n", local1.nombre, local1.posicionx, local1.posiciony);
	int bufferLocal1[local1.NBufferLocales][2];
	llenarLocal(bufferLocal1, local1.NBufferLocales);
	mostrarArreglo(bufferLocal1, local1.NBufferLocales);
	
	desplazamiento(vehiculo0.posicionInicialx,vehiculo0.posicionInicialy,local1.posicionx,local1.posiciony);
	sem_post(&sem1);
}

void* thread_local2_function(void* ){
	sem_wait(&sem1);
	printf("\nLa posicion de la %s es: x=%i y=%i\n", local2.nombre, local2.posicionx, local2.posiciony);
	int bufferLocal2[local2.NBufferLocales][2];
	llenarLocal(bufferLocal2, local2.NBufferLocales);
	mostrarArreglo(bufferLocal2, local2.NBufferLocales);
	
	desplazamiento(vehiculo0.posicionInicialx,vehiculo0.posicionInicialy,local2.posicionx,local2.posiciony);
	sem_post(&sem1);
}

void* thread_local3_function(void* ){
	sem_wait(&sem1);
	printf("\nLa posicion de la %s es: x=%i y=%i\n", local3.nombre, local3.posicionx, local3.posiciony);
	int bufferLocal3[local3.NBufferLocales][2];
	llenarLocal(bufferLocal3, local3.NBufferLocales);
	mostrarArreglo(bufferLocal3, local3.NBufferLocales);
	sem_post(&sem1);
}

void* thread_local4_function(void* ){
	sem_wait(&sem1);
	printf("\nLa posicion de la %s es: x=%i y=%i\n", local4.nombre, local4.posicionx, local4.posiciony);
	int bufferLocal4[local4.NBufferLocales][2];
	llenarLocal(bufferLocal4, local4.NBufferLocales);
	mostrarArreglo(bufferLocal4, local4.NBufferLocales);
	sem_post(&sem1);
}

void* thread_local5_function(void* ){
	sem_wait(&sem1);
	printf("\nLa posicion de la %s es: x=%i y=%i\n", local5.nombre, local5.posicionx, local5.posiciony);
	int bufferLocal5[local5.NBufferLocales][2];
	llenarLocal(bufferLocal5, local5.NBufferLocales);
	mostrarArreglo(bufferLocal5, local5.NBufferLocales);
	sem_post(&sem1);
}
