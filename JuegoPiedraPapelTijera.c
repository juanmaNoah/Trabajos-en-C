#include<stdio.h>
int aleatorio();
int main(){
	int maquina,contador=0,contador1=0;
	int jugador1, tijera, papel, piedra; 
	do{
		
		printf("\nEscriba la opcion que desea: \n");
	printf("1.-tijera \n");
	printf("2.-papel \n");
	printf("3.-piedra \n");
	printf("---------> :");
	scanf("%i", &jugador1);
	printf("\n");
	
	while(jugador1<1 || jugador1>3){
	printf("Opcion incorrecta %i \n");
	printf("\n Escriba la opcion que desea: \n");
	printf("1.-tijera \n");
	printf("2.-papel \n");
	printf("3.-piedra \n");
	printf("---------> :  ");
	scanf("%i", &jugador1);
	}
	
	switch(jugador1){
		case 1:
			printf("\nJugador: Tijera \n");
			break;
			case 2:
				printf("\nJugador: Papel \n");
				break;
				case 3:
					printf("\nJugador: Piedra \n");
					break; 
					case 4:
				if(jugador1>3){
		         puts("\nOpcion inconrrecta\n");
	}
}
	maquina=aleatorio();
	if( (maquina == 1 && jugador1 == 2 )|| (maquina ==2 && jugador1 ==3 )|| (maquina==3 && jugador1 ==1 )){
		
		printf("\nLa maquina gano.\n");
		contador=contador+1;
	}
	if((jugador1==1 && maquina ==2 )|| (jugador1==2 && maquina ==3 )|| (jugador1==3 && maquina==1)){
		
		printf("\nEl jugador  gano. \n");
		contador1=contador1+1;
	}
	if((jugador1==1 && maquina ==1)||(jugador1==2 && maquina==2)||(jugador1==3 && maquina==3)){
		printf("\nEmpate\n");
	}
	
	if (contador1 ==3){
		printf("\nEl ganador es el jugador. \n");
	}
	 if(contador ==3){
		printf("\nEl ganador es la maquina. \n");
	}
	
	printf("\nEl resultado es: %i a %i \n", contador1,contador);

}while(contador1!=3 && contador!=3);

	return 0;
}

int aleatorio(){
	     int numero;
		srand(time(NULL));
	
	numero=rand()%3+1;
	
	switch(numero){
		case 1:
			printf("\nMaquina: tijera \n");
			break;
			case 2:
				printf("\nMaquina: papel \n");
				break; 
				case 3:
					printf("\nMaquina: piedra \n");
					break;
		
	}
	 

	return numero;
}
