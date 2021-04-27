typedef struct lista Lista;
/* Cria uma lista vazia.*/
Lista* lst_cria();
/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l);
/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info);
/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);
/* Imprime uma lista.*/
void lst_imprime(Lista *l);
/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info);
/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l);


//Comprimento da lista
int comprimento(Lista *l);
// valores menores que n
int menores(Lista *l, int n);
// soma dos valores info
int soma(Lista *l);
// numeros primos
int primos(Lista* l);
// contatena duas listas
Lista* lst_conc(Lista* l1, Lista* l2);
// compara e modifica uma lista
Lista* lst_diferenca(Lista* l1, Lista* l2);
// insere valores de forma ordenada
Lista* lst_insere_ordenado(Lista *l, int info);
