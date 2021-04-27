#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct lista {
	int info;
	Lista *prox;
};
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
	int flag=0;
	
	while(l2 != NULL){
		if(lst_busca(l1, l2->info) != NULL){
			aux = lst_remove(l1, l2->info);
			flag++;
		}
		l2 = l2->prox;
	}
	if(flag!=0){
		return aux;
	}else{
		return l1;
	}
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



