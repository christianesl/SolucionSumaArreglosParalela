#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define chunk 100
#define mostrar 20

void imprimeArreglo(float *d);

int main(int argc, char *argv[]){
	printf("Sumando Arreglos en Paralelo! \n");
	float a[N], b[N], c[N];
	int i;

	for(i = 0; i < N; i++){
		a[i] = i * 10;
		b[i] = (i + 3) * 3.7;
	}

	int pedazos = chunk;

	#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
		for(i = 0; i < N; i++) c[i] = a[i] + b[i];


	printf("Imprimiendo los primeros %d valores del arreglo a: \n", mostrar);
	imprimeArreglo(a);
	printf("Imprimiendo los primeros %d valores del arreglo b: \n", mostrar);
	imprimeArreglo(b);
	printf("Imprimiendo los primeros %d valores del arreglo c: \n", mostrar);
	imprimeArreglo(c);

	return 0;
}

void imprimeArreglo(float *d){
	for(int x = 0; x < mostrar; x++){
		printf(" %f - ", d[x]);
	}
	printf("\n");
}
