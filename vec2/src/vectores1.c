/*
 ============================================================================
Ejercicio 5-3:
Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
La carga deberá ser aleatoria (todos los elementos se inicializan en cero por default).
 Determinar el promedio de los positivos, y del menor de los negativos la suma de los antecesores
 (Según la recta numérica de los reales, hasta llegar a cero).

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
void muestroVector(int numeros[],int tam);
void promedioDePositivos(int numeros[], int tam,float* promedioPositivos);
void antecesoresDelMenorNegativo(int numeros[],int tam,int* sumaAntecesores);

int main(void) {

	setbuf(stdout,NULL);

	int numeros[TAM]={0};
	float promedioPositivos;
	int sumaAntecesores;

	for(int i=0; i<TAM;i++){
		printf("Ingrese un numero distinto de 0: ");
		scanf("%d",&numeros[i]);
		while(numeros[i]==0){
			printf("\nError. Ingrese un numero distinto de cero:");
			scanf("%d",&numeros[i]);
		}
	}


	printf("\nLos numeros ingresados fueron:");
	muestroVector(numeros,TAM);

	promedioDePositivos(numeros,TAM,&promedioPositivos);
	printf("\nEl promedio de los numeros positivos es: %.2f",promedioPositivos);

	antecesoresDelMenorNegativo(numeros,TAM,&sumaAntecesores);
	printf("\nLa suma de los antecesores del menor numero negativo es %d",sumaAntecesores);

	return EXIT_SUCCESS;
}


void promedioDePositivos(int numeros[], int tam,float* promedioPositivos){

	int acumuladorPositivos=0;
	int contadorPositivos=0;

	for(int i=0; i<tam; i++){
		if(numeros[i]>=0){
			acumuladorPositivos+=numeros[i];
			contadorPositivos++;
		}
	}

	*promedioPositivos=(float) acumuladorPositivos/contadorPositivos;
}


void antecesoresDelMenorNegativo(int numeros[],int tam,int* sumaAntecesores){


	int menor;
	int indice;
	int acumuladorAntecesores=0;


	 for(int i=0; i<tam; i++){
		 if( numeros[i]<0 && (i==0 ||  numeros[i]<menor)){
			 menor=numeros[i];
			 indice=i;
		 }
	 }


	 for(int i=indice-1; i>=0 ;i--){
          acumuladorAntecesores+=numeros[i];

		 }


	 *sumaAntecesores=acumuladorAntecesores;
}



void muestroVector(int numeros[],int tam){
	 for(int i=0; i<tam; i++){
          printf("%d ",numeros[i]);
	   }
}
