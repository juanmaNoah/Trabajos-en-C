#include <stdio.h>
#include <conio.h>
#include <string.h>
#define TAM 3

int lDesp (int nSur, char *tComb);
int usoSurt (int nSub, char *pSub);

struct est_combustible{
	char tipo[14];
	int litros;
};

struct est_ypf{
	int carga;
	char playero[20];
	int surtidor;
	struct est_combustible combustible;
}datos[TAM];

int main (){
	int i;
	int numPlayero, numSurtidor, numCombustible, cantCombustible, ns, tc, nsC, cantComb, nSub, sSub, nPlayero, nSurtidor;
	char tcC[20]; 
	char pSub[20];
	
	for(i=1; i<=TAM; i++){
		printf("Ingrese los datos de la carga %i \n\n", i); 
		datos[i].carga = i;
			
		do {
			printf("Quien realizo la carga: \n");
			printf("Ingrese \n");
			printf("1: si fue Javier \n");
			printf("2: si fue Jose \n");
			printf("3: si fue Victoria \n\n");
			scanf("%i", &numPlayero);
			
			switch(numPlayero){
				case 1:
					strcpy(datos[i].playero, "Javier");
					break;
				case 2:
					strcpy(datos[i].playero, "José");
					break;
				case 3: 
					strcpy(datos[i].playero, "Victoria");
					break;
				default: printf("Debes seleccionar un numero entre 1 y 3\n\n");
			}
		}while(numPlayero< 1||numPlayero >3);
			
		do{
			printf("Cual de los 4 surtidores utilizo?\n\n");
			scanf("%i", &numSurtidor);
				switch(numSurtidor){
					case 1:
						datos[i].surtidor = 1;
						break;
					case 2:
						datos[i].surtidor = 2;
						break;
					case 3: 
						datos[i].surtidor = 3;
						break;
					case 4: 
						datos[i].surtidor = 4;
						break;
					default: printf("Debes seleccionar un numero entre 1 y 4\n\n");
				}
		}while(numSurtidor< 1|| numSurtidor >4);
		
		do{
			printf("Que tipo de combustible Cargo\n");
			printf("Ingrese \n");
			printf("1: Nafta Super \n");
			printf("2: Nafta Premium \n");
			printf("3: Diesel Super \n");
			printf("4: Diesel Premium \n\n");
			scanf("%i", &numCombustible);
			switch(numCombustible){
				case 1:
						strcpy(datos[i].combustible.tipo, "nafta super");
						break;
					case 2:
						strcpy(datos[i].combustible.tipo, "nafta premium");
						break;
					case 3: 
						strcpy(datos[i].combustible.tipo, "diesel super");
						break;
					case 4: 
						strcpy(datos[i].combustible.tipo, "diesel premium");
						break;
					default: printf("Debes seleccionar un numero entre 1 y 4\n\n");
			}
		}while(numCombustible< 1|| numCombustible >4);
		fflush(stdin);
		
		do{
			fflush(stdin);
			printf("Cuantos litros cargo\n");
			scanf("%i", &cantCombustible);
			
			fflush(stdin);
			if(cantCombustible>0 || cantCombustible>1000){
				datos[i].combustible.litros = cantCombustible;	
			}else{
				printf("La cantidad ingresada no es correcta");
			}
		}while(cantCombustible<0 || cantCombustible>1000);
	}
	
	do{
		printf("Elije cual de los 4 surtidores queres verificar \n\n");
		scanf("%i", &ns);
				switch(ns){
					case 1:
						nsC = 1;
						break;
					case 2:
						nsC = 2;
						break;
					case 3: 
						nsC = 3;
						break;
					case 4: 
						nsC = 4;
						break;
					default: printf("Debes seleccionar un numero entre 1 y 4\n\n");
				}
		}while(ns< 1|| ns >4);
		
	do{
		printf("Elije el tipo de combustible que queres verificar \n\n");
		printf("1: Nafta Super \n");
		printf("2: Nafta Premium \n");
		printf("3: Diesel Super \n");
		printf("4: Diesel Premium \n\n");
		scanf("%i", &tc);
		switch(tc){
			case 1:
				strcpy(tcC, "nafta super");
				break;
			case 2:
				strcpy(tcC, "nafta premium");
				break;
			case 3: 
				strcpy(tcC, "diesel super");
				break;
			case 4: 
				strcpy(tcC, "diesel premium");
				break;
			default: printf("Debes seleccionar un numero entre 1 y 4\n\n");		
		}
	}while(tc< 1|| tc >4);
	
	cantComb = lDesp (nsC, tcC);
	printf("El surtidor %i cargo el total de %i litros. \n\n", nsC, cantComb);
	
	do{
		printf("Elije cual de los 4 surtidores queres verificar \n\n");
		scanf("%i", &nSurtidor);
			switch(nSurtidor){
				case 1:
					nSub = 1;
					break;
				case 2:
					nSub = 2;
					break;
				case 3: 
					nSub = 3;
					break;
				case 4: 
					nSub = 4;
					break;
				default: printf("Debes seleccionar un numero entre 1 y 4\n\n");
			}
	}while(nSurtidor< 1|| nSurtidor >4);
	
	do {
		printf("Que playero lo Utilizo? \n");
		printf("Ingrese \n");
		printf("1: Javier \n");
		printf("2: Jose \n");
		printf("3: Victoria \n\n");
		scanf("%i", &nPlayero);
		
		switch(nPlayero){
			case 1:
				strcpy(pSub, "Javier");
				break;
			case 2:
				strcpy(pSub, "José");
				break;
			case 3: 
				strcpy(pSub, "Victoria");
				break;
			default: printf("Debes seleccionar un numero entre 1 y 3\n\n");
		}
	}while(nPlayero< 1||nPlayero >3);
	
	printf("El surtidor %i fue utilizado %i veces por el playero %s", nSub, usoSurt(nSub, pSub), pSub);
	return 0;
}

int lDesp (int nSur, char *tComb){
	int i;
	int resultado = 0;
	
	for(i=1; i<=TAM; i++){
			if(datos[i].surtidor == nSur){
				if(strcmp(tComb, datos[i].combustible.tipo) == 0){
					resultado += datos[i].combustible.litros;
				}
			}
	}
	return resultado;
}

int usoSurt (int nSub, char *pSub){
	int i;
	int resultado = 0;
	
	for(i=1; i<=TAM; i++){
			if(datos[i].surtidor == nSub){
				if(strcmp(pSub, datos[i].playero) == 0){
					resultado += 1;
				}
			}
	}
	return resultado;
}