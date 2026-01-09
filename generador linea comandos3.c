#include <stdio.h>

typedef struct {
	int codigo;
	int cantidad;
}VENTA;

typedef struct { 
	int codigo; 
	char nombre[30]; 
	float precio;
}PRODUCTO;

int main() {
    FILE *fp = fopen("PRODUCTOS.DAT", "wb");
    FILE *fv = fopen("VENTAS.DAT", "wb");

    PRODUCTO p[] = {{10, "Teclado", 2500.00}, {20, "Mouse", 1200.00}}; //arrays de creacion de ab
    VENTA v[] = {{10, 2}, {20, 5}, {10, 1}}; 

    fwrite(p, sizeof(PRODUCTO), 2, fp);
    fwrite(v, sizeof(VENTA), 3, fv);

    fclose(fp);
	fclose(fv);
	
    printf("\nArchivos .DAT creados con exito\n");
    
    return 0;
}
