#include<stdio.h>
#include<stdlib.h>

#include "pilha.h"
#include "lista.h"


struct lista{
	int info;
	Lista *prox;
};

struct pilha{
	Lista *prim;
}; 

/*Função que cria uma pilha.*/
Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if(p==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
	return p->prim==NULL;
}

/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
	return a;
}

/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
 }
}

/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p){
	Lista* l = p->prim;
	Lista* lAux;
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(p);
}
/////////////////////////////////////////////////////

//valor armazenado no topo
int topo(Pilha* p){
	Lista* l = p->prim;
	int a = l->info;
	return a;
}

// info com valor ímpar
int impares(Pilha* p){
	Lista* l = p->prim;
	int cont=0;
	while(l!= NULL){
		if(l->info % 2 !=0){
			cont++;
		}
		l=l->prox;
	}
	return cont;
}

//verifica elementos em comum e empilha de forma crescente
Pilha* empilha_elem_comuns(Lista* l1, Lista* l2){
	Pilha* pilhadef = pilha_cria();
	Lista* aux = lst_cria();
	
	while(l2 != NULL){
		if(lst_busca(l1, l2->info) != NULL){
			aux = lst_insere_ordenado(aux,l2->info);
		}
		l2 = l2->prox;
	}
	while(aux != NULL){
		pilha_push(pilhadef,aux->info);
		aux = aux->prox;
	}
	return pilhadef;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//#include "lista.h"

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

Lista* lst_insere_ordenado(Lista *l, int info){
	Lista *lNew = (Lista*)malloc(sizeof(Lista));
	lNew->info = info;
	if(l==NULL){
		lNew->prox = NULL;
		return lNew;
	}else if(l->info>=info){
		lNew->prox = l;
		return lNew;
	}else{
		Lista *lAnt = l;
		Lista *lProx = l->prox;
	while(lProx!=NULL&&lProx->info<info){
		lAnt = lProx;
		lProx = lProx->prox;
	}
		lAnt->prox = lNew;
		lNew->prox = lProx;
		return l;
	}
}







