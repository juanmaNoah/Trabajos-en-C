#include<stdio.h>
#include<string.h>
#define N 2

struct _valor{
	int compra;
	int venta;
	float iva;
};

struct _detalle{
	char descripcion[20];
	int  codigo;
	int stock;
	char marca[20];
	struct _valor valor;
}detalles[N];

void descripcion( int cod);
void archivos();

int main(){
	int i, iva, codigos, ver;
	
    
	for(i=1;i<=N;i++){
		printf("\nProducto numero %i \n", i);

			printf("\nIngrese el codigo del producto: ");
		    scanf("%i", & detalles[i].codigo);
		  
		   fflush(stdin);
		   printf("\nIngrese la marca del producto: ");
		   gets(detalles[i].marca);
		   strupr(detalles[i].marca);
		printf("\nIngrese la descripcion del producto: ");
		gets(detalles[i].descripcion);
		strupr(detalles[i].descripcion);
		fflush(stdin);
	
		printf("\nIngrese el valor de la compra entre $1 y $50.000:");
		scanf("%i", & detalles[i].valor.compra);
		while(detalles[i].valor.compra<1 || detalles[i].valor.compra>50000){
		printf("\nIngrese el valor de la compra entre $1 y $50.000: ");
		scanf("%i", & detalles[i].valor.compra);
		}
		printf("\nIngrese el valor de la venta entre $1 y $50.000: ");
		scanf("%i", & detalles[i].valor.venta);
		while(detalles[i].valor.venta<1 || detalles[i].valor.venta>50000){
		printf("\nIngrese el valor de la venta entre $1 y $50.000: ");
		scanf("%i", & detalles[i].valor.venta);
		}
		
		printf("\nElija el valor del IVA: \n");
		printf("1. 21%\n");
		printf("2. 10.5% \n");
		 printf("---->:");
		 scanf("%i", & iva);
		 
		 switch(iva){
		 	case 1:
		 		detalles[i].valor.iva= (detalles[i].valor.venta * 21) /100;
		 		break;
		 		case 2:
		 			detalles[i].valor.iva= (detalles[i].valor.venta * 10.5) /100;
		 			break;
		 		
		 }
		while(iva<1 || iva >2){
		printf("\nElija el valor del IVA: \n");
		printf("1. 21%\n");
		printf("2. 10.5% \n");
		 printf("---->:");
		 scanf("%i", & iva);
		 
		  
		 switch(iva){
		 	case 1:
		 		detalles[i].valor.iva= (detalles[i].valor.venta * 21) /100;
		 		break;
		 		case 2:
		 			detalles[i].valor.iva= (detalles[i].valor.venta *10.5) /100;
		 			break;
		 		
		 }
	}
	printf("\nIngrese el valor de stock: ");
	scanf("%i", &detalles[i].stock);
	while(detalles[i].stock<0){
	printf("\nIngrese el valor de stock: ");
	scanf("%i", &detalles[i].stock);
	}
	
}
printf("Ingrese el codigo del producto que desee ver: ");
scanf("%i", & codigos);
descripcion(codigos);
printf("\n¿Desea ver algun producto mas? \n");
		printf("1.SI \n");
		printf("2.NO \n");
		printf("----->: ");
		scanf("%i", &ver);
	while(ver == 1){
		printf("Ingrese el codigo del producto que desee ver: ");
scanf("%i", & codigos);
descripcion(codigos);
printf("\n¿Desea ver algun producto mas? \n");
		printf("1.SI \n");
		printf("2.NO \n");
		printf("----->: ");
		scanf("%i", &ver);
	}
			if(ver == 2){
			printf("Gracias por su tiempo \n!");
}
archivos();

return 0;
}


void descripcion(int cod){
	int i;
	for(i=1;i<=N;i++){
		if( detalles[i].codigo == cod){
			printf( "Descripcion del producto: %s \n", detalles[i].descripcion);
			printf("Valor de la venta con IVA : %3.f \n", (detalles[i].valor.venta + detalles[i].valor.iva));
			printf("STOCK: %i \n", detalles[i].stock);
			printf("Marca: %s \n", detalles[i].marca);
		}
		if(cod != detalles[i].codigo){
			printf("\nEl codigo ingresado no corresponde a un producto.\n");
		}
		
		}
	}



void archivos(){
	FILE *f;
	int i;
	
	f= fopen("stock.txt", "w");
	if(f==NULL){
		printf("Error al crear el archivo.\n");
	}
	else{
		fprintf(f,"Codigo \t Producto \t Marca \t Stock \n");
		for(i=0;i<=N;i++){
			fprintf(f," %i \t %s \t %s \t %i \n", detalles[i].codigo, detalles[i].descripcion, detalles[i].marca, detalles[i].stock);
		}
		fclose(f);
		printf("Se ha generado el archivo.\n");
	}
}
