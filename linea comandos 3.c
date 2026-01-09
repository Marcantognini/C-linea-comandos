/*
Se dispone de:

PRODUCTOS.DAT con registros:
struct PRODUCTO {
    int codigo;
    char nombre[30];
    float precio;
};

VENTAS.DAT con registros:
struct VENTA {
    int codigo;
    int cantidad;
};

El programa debe recibir por línea de comandos el código de un producto.
Luego debe mostrar:
Nombre del producto.
Unidades vendidas.
Recaudación total (cantidad × precio).
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct  {
    int codigo;
    int cantidad;
}VENTA;

typedef struct  {
    int codigo;
    char nombre[30];
    float precio;
}PRODUCTO;


 // argv[1] = codigo		printf ( PRO.nombre , VEN.cantidad , VEN.cantidad*PRO.precio


int main( int argc , char **argv) {
	if(argc<2){
		printf("USO: %s\n",argv[0]);
		return 1;
	}
	FILE*P;
	FILE*V;
	VENTA *vec;
	PRODUCTO *vec2;
	long n,n2;
	int cod = atoi(argv[1]);
	int i,j;
	
		if (!(V=fopen("VENTAS.DAT","rb")) ) {
		printf("ERROR EN LECTURA");
		exit(1);
	}
	
	if (!(P=fopen("PRODUCTOS.DAT","rb")) ) {
		printf("ERROR EN LECTURA");
		exit(1);
	}	
	
	fseek(V,0,SEEK_END);
	fseek(P,0,SEEK_END);
	
	n=ftell(V)/sizeof(VENTA);
	n2=ftell(P)/sizeof(PRODUCTO);
	rewind(V);
	rewind(P);
	
	vec=malloc(n*sizeof(VENTA));
	vec2=malloc(n2*sizeof(PRODUCTO));
	fread(vec,sizeof(VENTA),n,V);
	fread(vec2,sizeof(PRODUCTO),n2,P);
	
	fclose(V);
	fclose(P);
		printf("\n\n\n");
	for (i=0;i<n;i++) {
		for (j=0;j<n2;j++) {
			float total = vec[i].cantidad * vec2[j].precio;
			if (vec[i].codigo == vec2[j].codigo && vec[i].codigo == cod) {	// cuando encuentro el codigo tipeado x linea de comandos, 
				printf("NOMBRE: %s",vec2[j].nombre);
				printf("\nUNIDADES VENDIDAS: %d",vec[i].cantidad); // muestro lo solicitado
				printf("\nRECAUDACION TOTAL: %.2f",total);	
			}
		}
	}
	free(vec);
	free(vec2);
	return 0;
}

