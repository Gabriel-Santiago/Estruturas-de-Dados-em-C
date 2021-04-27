#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "arvb.h"

struct arvb{
	int info;
	ArvB *esq;
	ArvB *dir;
};



ArvB* arvb_cria_vazia(void){
	return NULL;
}

int arvb_vazia(ArvB *a){
	return a==NULL;
}

ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir,c);
	else if(a->info > c)
		return arvb_busca(a->esq,c);
	else //(a->info == c)
	return a;
}

void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
	}
}

ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}else if(a->info > c)
		a->esq = arvb_insere(a->esq,c);
	else if (a->info < c)
		a->dir = arvb_insere(a->dir,c);
	else
		printf("\nElemento Ja Pertence a Arvore");
	return a;
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c);
		else if (a->info < c)
			a->dir = arvb_remove(a->dir,c);
		else{
			ArvB* t;
			if (a->esq == NULL){
				t = a; a = a->dir;
				free(t);
			}else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}else{
				t = a->esq;
				while(t->dir!=NULL)
				t = t->dir;
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	}
return a;
}

void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}


//////////////////////////////////////////////////////

// numeros de elementos divisiveis por 'n'
int folhas_div_n(ArvB* a, int n){
	static int cont = 0;
	if(!arvb_vazia(a)){
		folhas_div_n(a->esq, n);
		if(a->info % n == 0){
			cont++;
		}
		folhas_div_n(a->dir,n);
	}
	return cont;
}

// arvore degenerada
int isdegenerada(ArvB* a){
	int flag = 0;
	
	if(!arvb_vazia(a)){
		isdegenerada(a->esq);
		if(a->dir != NULL && a->esq!=NULL){
			flag = 0;
			return flag;
		}else{
			flag = 1;
		}
		isdegenerada(a->dir);
	}
	return flag;
}

// nos de uma arvore binaria
int nos_fb_n(ArvB* a, int n){
	int cont = 0;
	
	int nosFb(ArvB* a, int n){
		if(!arvb_vazia(a)){
			int fb = 0;
			if(a->esq == NULL && a->dir == NULL){
				fb = 0;
			}
			else{
				fb = arv_altura(a->dir) - arv_altura(a->esq);
			}
			nosFb(a->esq, n);
			nosFb(a->dir, n);
			if(fb == n){
				cont++;
			}
			return cont;		
		}
	}
	return nosFb(a, n);
}

// função para verificar o tamanho da avore
int arv_altura(ArvB *a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arv_altura(a->esq);
		int hSAD = arv_altura(a->dir);
		if(hSAE > hSAD) 
		return 1+hSAE;
		else
		return 1+hSAD;
	}
}

//elementos comuns de entre listas
void impressao_arv_elem_comuns(ArvB* a, ArvB* b){
	//int k;
	if(!arvb_vazia(b)){
		impressao_arv_elem_comuns(a, b->esq);
		if(arvb_busca(a, b->info) != NULL){
			printf("%d ", b->info);
		}
		impressao_arv_elem_comuns( a, b->dir);
	}
}

