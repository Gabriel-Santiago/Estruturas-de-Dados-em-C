

typedef struct fila FilaP;

//cria uma fila de prioridade vazia;
FilaP* filap_cria(void);

//testa se a fila � vazia
int filap_vazia(FilaP *f);
	
//devolve o elemento de maior prioridade na fila;
int heap_maximum(FilaP* f);

//devolve o elemento de maior prioridade e o retira da fila;
int heap_extract_max(FilaP* f);

//modifica a prioridade de determinado elemento no �ndice ind na fila (apenas se chave for maior);
void heap_increase_key(FilaP* f, int ind, int chave);

//insere um novo elemento na fila com prioridade chave.
void max_heap_insert(FilaP* f, int chave);

void Max_Heapify(FilaP *f,int i);
