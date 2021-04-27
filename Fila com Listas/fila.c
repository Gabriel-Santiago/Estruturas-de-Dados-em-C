#include <stdio.h>
#include<stdlib.h>
#include "fila.h"
#include "lista.h"

struct lista {
	int info;
	Lista *prox;
};

struct fila{
	Lista *ini;
	Lista *fim;
};

/*Função que cria uma Fila.*/
Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
	printf("Memoria insuficiente!!!\n");
	exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
 return f;
}

/*Testa se uma Fila é vazia.*/
int fila_vazia(Fila *f){
	return f->ini==NULL;
}

/*Função que adiciona um elemento em uma Fila.*/
void fila_insere(Fila *f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f))
		f->fim->prox = l;
	else
		f->ini = l;
		f->fim = l;
}

/*Função que remove um elemento de uma Fila.*/
int fila_remove(Fila *f){
	Lista *l; 
	int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	if(fila_vazia(f))
		f->fim = NULL;
	return a;
}

/*Função que imprime os elementos de uma Fila.*/
void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

/*Libera o espaço alocado para uma fila.*/
void fila_libera(Fila *f){
	Lista* l = f->ini;
	Lista* lAux;
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(f);
}
//////////////////////////////////////////////

// retorna numero de elemento maior que n
int qtd_maior(Fila* f, int n){
	Lista* l = f->ini;
	int cont=0;
	
	while(l!=NULL){
		if(l->info>n){
			cont++;
		}
		l=l->prox;
	}
	return cont;
}

// ordem inversa da fila
Fila* inverte(Fila* f){
	Lista* in = f->ini;
	Lista* laux = lst_cria();
	
	Fila* f2 = fila_cria();
	
	while(in!=NULL){
		laux = lst_insere(laux, in->info);
		in = in->prox;
	}
	while(laux!=NULL){
		fila_insere(f2, laux->info);
		laux = laux->prox;
	}
	return f2;
}

// valores pares da fila
int pares(Fila* f){
	Lista* aux = f->ini;
	int cont=0;
	while(aux!=NULL){
		if((aux->info)%2==0){
			cont++;
		}
		aux = aux->prox;
	}
	return cont;
}

////////////////////////////////////////////////////////
/* Cria uma lista vazia.*/
Lista* lst_cria(){
	return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l){
	return (l==NULL);
}

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
 	ln->info = info;
 	ln->prox = l;
 	return ln;
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
 	while(lAux!=NULL){
 		if(lAux->info == info)
 		return lAux;
 		lAux = lAux->prox;
	}
	return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l){
 	Lista* lAux = l;
 	while(lAux!=NULL){
 		printf("Info = %d\n",lAux->info);
 		lAux = lAux->prox;
 	}
}

/*Remove da lista*/ 
Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
	 	Lista* lAux = l->prox;
	 	if(l->info==info){
	 		free(l);
	 return lAux;
	 }
	 else{
	 	Lista* lAnt = l;
	 	while(lAux!=NULL ){
	 		if(lAux->info == info){
				 lAnt->prox = lAux->prox;
				 free(lAux);
	 	break;
	 	}	else{
	 			lAnt = lAux;
				 lAux = lAux->prox;
				}
	 	}
	 }
	 return l;
	}
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l){
 	Lista* lProx;
 	while(l!=NULL){
 		lProx = l->prox;
 		free(l);
 		l = lProx;
 	}
}
////////////////////////////////////////////////////////////////////
// Calcular comprimento da lista
int comprimento(Lista *l) {
	int comprimento = 0;
	Lista* no = l;
	while (no != NULL) {
		comprimento++;
		no = no->prox;
	}
	return comprimento;
}
// menores que info
int menores(Lista *l, int n){
	int men = 0;
	Lista* min = l;
	while (min != NULL) {
		if(n> min->info){
			men++;
		}
		min = min->prox;
	}
	printf("quantidade de nos menores que %d: %d\n", n, men);
	return men;
}
// soma dos valores info
int soma(Lista *l){
	int total = 0;
	Lista* soma = l;
	while(soma != NULL){
		total = total + soma->info;
		soma = soma->prox;
	}
	return total;
}

// quantidade de info primos
int primos(Lista *l){
	int qtd = 0;
	int flag=0;
	Lista* prim = l;
	
	while(prim != NULL){
		flag=0;
		int aux = (prim->info)-1;
		while(aux>=2){
			if(prim->info == 2){
				qtd++;
			}
			else if((prim->info) % aux == 0){
				flag++;
			}
			aux--;
		}
		if(flag==0){
			qtd++;
		}
		
			prim = prim->prox;
	}
	return qtd;
}

// nova lista concatenada
Lista* lst_conc(Lista* l1, Lista* l2){
	Lista* l3 = lst_cria();
	while(l2!=NULL){
		l3 = lst_insere(l3, l2->info);
		l2 = l2->prox;
	}
	while(l1!=NULL){
		l3 = lst_insere(l3, l1->info);
		l1 = l1->prox;
	}
	return l3;
}

// diferenca de 2 listas
Lista* lst_diferenca(Lista* l1, Lista* l2){
	Lista* aux = lst_cria();
		while(l2 != NULL){
			if(lst_busca(l1, l2->info) != NULL){
				aux=lst_remove(l1, l2->info);
			}
			l2 = l2->prox;
		}
	return aux;
}

// Imprime uma lista invertida.
void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l))
		return;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("Info: %d\n",l->info);
	}
}






