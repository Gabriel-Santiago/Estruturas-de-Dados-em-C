
typedef struct fila Fila;
/*Fun��o que cria uma Fila.*/
Fila* fila_cria(void);
/*Testa se uma Fila � vazia.*/
int fila_vazia(Fila *f);
/*Fun��o que adiciona um elemento em uma Fila.*/
void fila_insere(Fila *f, int info);
/*Fun��o que remove um elemento de uma Fila.*/
int fila_remove(Fila *f);
/*Fun��o que imprime os elementos de uma Fila.*/
void fila_imprime(Fila *f);
/*Libera o espa�o alocado para uma Fila.*/
void fila_libera(Fila *f);

//////////////////////////////////////////////
// retorna numero de elemento maior que n
int qtd_maior(Fila* f, int n);
//ordem inversa da fila
Fila* inverte(Fila* f);
// valores pares da fila
int pares(Fila* f);
