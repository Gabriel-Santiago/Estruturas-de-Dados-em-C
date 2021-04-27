

typedef struct arvb ArvB;

/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);
/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);
/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);
/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);
/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);
/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c);
/*Libera o espaço alocado para uma Árvore.*/
void arvb_libera(ArvB *a);
/////////////////////////////////////////////

// numeros de elementos divisiveis por 'n'
int folhas_div_n(ArvB* a, int n);
// arvore degenerada
int isdegenerada(ArvB* a);
// nos de uma arvore binaria
int nos_fb_n(ArvB* a, int n);
// função para verificar o tamanho da avore
int arv_altura(ArvB *a);
//elementos comuns de entre listas
void impressao_arv_elem_comuns(ArvB* a, ArvB* b);
//imprime por niveis
//void impressao_arv_niveis(ArvB* a);
