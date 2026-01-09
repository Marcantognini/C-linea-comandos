/*
Una empresa de comidas rapidas tiene varias sucursales.
Se disponen de dos archivos:

El arhivo FATURACION registra los ingresos de cada sucrusal, Sus registros tienen la forma:
struct {
char NOM[20];
int FACT;
};
Donde NOM es el nombre de la sucursal ( no hay nombres repetidos ) y FACT es el valor de facturacion anual.

El archivo COSTOS tiene informacion referedia a los gastos de cada suursal y sus registros tienen la forma:
struct {
char NOM[20];
int COSTO_ANUAL;
};
Donde NOM es el nombre de la sucursal y COSTO_ANUAL son los gastos anuales que tiene esa sucursal.

Se pide: construir un programa que reciba por linea de comandos el beneficio minimo anual que se espera para cada sucrusal.
El beneficio es FACTURACION-COSTO.
Mostrar en pantalla los nombres de las sucursales que no cumplen con el requisito.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char NOM[20];
	int FACT;
}FAC;

typedef struct {
	char NOM[20];
	int COSTO_ANUAL;
}COS;
// 				FACTURACION.FACT - COSTOS.COSTO_ANUAL ( argv[1] ) = por ej: 25000 x linea de comandos
 //				if ( FACTURACION.FACT - COSTOS.COSTO_ANUAL < argv[1] ) 		printf NOM 
int main(int argc, char **argv ) {
	if(argc<2){
		printf("USO: %s\n",argv[0]);
		return 1;
	}
FILE*FA;
FILE*CO;

FAC *vec;
COS *vec2;

int beneficio = atoi(argv[1]);
long n,n2;
int i,j,bene;

if (!(FA=fopen("FACTURACION.DAT","rb")) ) {
	printf("ERROR EN LECTURA");
	exit(1);
}
if (!(CO=fopen("COSTOS.DAT","rb")) ) {
	printf("ERROR EN LECTURA");
	fclose(FA);
	exit(1);
}

fseek(FA,0,SEEK_END);
fseek(CO,0,SEEK_END);

n=ftell(FA)/sizeof(FAC);
n2=ftell(CO)/sizeof(COS);

rewind(FA);
rewind(CO);

vec=malloc(n*sizeof(FAC));
vec2=malloc(n2*sizeof(COS));

fread(vec,sizeof(FAC),n,FA);
fread(vec2,sizeof(COS),n2,CO);

fclose(FA);
fclose(CO);


printf("\n\n\n");
printf("SUCURSALES QUE NO CUMPLEN BENEFICIO MINIMO");
for (i=0;i<n;i++) {
	for (j=0;j<n2;j++) {
		if (strcmp (vec[i].NOM , vec2[j].NOM )==0) {
			bene = vec[i].FACT - vec2[j].COSTO_ANUAL;
			if ( bene < beneficio ) {
				printf("%s\n",vec[i].NOM);
			}	
		}
	}
}

free(vec);
free(vec2);

return 0;
}
