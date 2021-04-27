#include <stdio.h>
#include<stdlib.h>
#include "filaprio.h"

#define MAX 10
#define PAI(i) ((i-1)/2)
#define Right(i) (2*i + 2)
#define Left(i) (2*i + 1)

struct fila{
	int v[MAX];
	int t_heap;
};

//cria uma fila de prioridade vazia;
FilaP* filap_cria(void){
	FilaP *f = (FilaP*)malloc(sizeof(FilaP));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->t_heap = 0;
 	return f;
}

int filap_vazia(FilaP *f){
	return f->t_heap==0;
}

//insere um novo elemento na fila com prioridade chave.
void max_heap_insert(FilaP* f, int chave){
	f->t_heap = f->t_heap+1;
	f->v[f->t_heap-1] = -1;
	heap_increase_key(f, f->t_heap-1, chave);
	
}


//devolve o elemento de maior prioridade na fila;
int heap_maximum(FilaP* f){
	if(!filap_vazia(f)){
		return f->v[0];
	}

}
 
//devolve o elemento  de maior prioridade e o retira da fila;
int heap_extract_max(FilaP* f){
	int max;
	if(!filap_vazia(f)){
		if(f->t_heap<1){
			printf("heap underflow\n");
		}
		max = f->v[0];
		f->v[0]=f->v[f->t_heap-1];
		f->t_heap = f->t_heap-1;
		
		Max_Heapify(f,0);
		return max;
	}
}

void Max_Heapify(FilaP *f,int i){
	int l = Left(i);
	int r = Right(i);
 	int maior, x=0;
	
	if(l<=f->t_heap && f->v[l] > f->v[i]){
		maior = l;
	}else{
		maior = i;
	}
	if(r<=f->t_heap && f->v[r] > f->v[maior]){
	 	maior = r;
	}
	if(maior!=i){
		x=f->v[i];
		f->v[i]=f->v[maior];
		f->v[maior] = x;
		Max_Heapify(f,maior);
	}
}

//modifica a prioridade de determinado elemento no índice ind na fila (apenas se chave for maior);
void heap_increase_key(FilaP* f, int i, int chave){
	int x;
	if(!filap_vazia(f)){
		if (chave < f->v[i]){
			printf("nova chave eh menor que chave atual\n");
		}
		f->v[i]=chave;
		while(i>0 && f->v[PAI(i)]<f->v[i]){
			x = f->v[i];
			f->v[i] = f->v[PAI(i)];
			f->v[PAI(i)] = x;
			i = PAI(i);
		}
	}
}


 


