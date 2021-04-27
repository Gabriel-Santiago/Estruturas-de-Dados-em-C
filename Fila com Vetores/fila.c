#include <stdio.h>
#include<stdlib.h>
#include "fila.h"

#define N 5
typedef struct fila{
	int n;
	int ini;
	int v[N];
}Fila;

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
	printf("Memoria insuficiente!!!\n");
	exit(1);
	}
	f->n = 0;
	f->ini = 0;
	return f;
}

/*Testa se uma fila é vazia.*/
int fila_vazia(Fila *f){
	return f->n==0;
}


void fila_insere(Fila *f, int info){
	int fim;
	if(f->n==N){
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->v[fim]= info;
	f->n++;
}

/*Função que remove um elemento de uma fila.*/
int fila_remove(Fila *f){
	int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->v[f->ini];
	f->ini = (f->ini+1)%N;
	f->n--;
	return a;
}


void fila_imprime(Fila *f){
	int i; int k;
	for(i = 0; i<f->n;i++){
		k = (f->ini+i) % N;
		printf("%d\n",f->v[k]);
	}
}

void fila_libera(Fila *f){
	free(f);
}

///////////////////////////////////////////////////////

// retorna numero de elemento maior que n
int qtd_maior(Fila* f, int n){
	int i;
	int k;
	int maior=0;
 	for(i = 0; i<f->n;i++){
 		k = (f->ini+i) % N;
 		if(f->v[k]>n){
 			maior++;
		 }
 	}
 	return maior;
}

//ordem inversa da fila
Fila* inverte(Fila* f){
	int i = sizeof(f);
	int k;
	Fila* f2 = fila_cria();
	
	for(i;i>f->n;i--){
		k = (f->ini+i) % N;
		fila_insere(f2, f->v[k]);
	}
	return f2;
}

// valores pares da fila
int pares(Fila* f){
	int i; 
	int k;
	int pares = 0;
	for(i = 0; i<f->n;i++){
		k = (f->ini+i) % N;
		if(f->v[k]%2 == 0){
			pares++;
		}
	}
	return pares;
}




