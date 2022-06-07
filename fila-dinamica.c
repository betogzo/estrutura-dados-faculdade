#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int valor;
  struct No *proximo;
} No;

typedef struct Fila {
  No *inicio;
  No *fim;
  int tamanho;
} Fila;

void entraNaFila(Fila *fila, int valor) {
  No *novo = (No *) malloc(sizeof(No));

  novo->valor = valor;
  novo->proximo = NULL;

  if(fila->inicio == NULL) //se fila vazia 
    fila->inicio = novo; //novo entra no inicio
  else 
    fila->fim->proximo = novo; //se não, fim->proximo aponta para novo
  
  fila->fim = novo; //novo sempre entra no fim da fila
  fila->tamanho++;
}

void sairDaFila(Fila *fila) {
  No* ptr;
  ptr = fila->inicio;

  if(ptr == NULL) {
    printf("Fila vazia. Nada a desenfileirar.");
  } else {
    fila->inicio = ptr->proximo;
    free(ptr);
  }

  fila->tamanho--;
}

int imprimeFila(Fila *fila) {
  No *atual;
  atual = fila->inicio;

  if(atual == NULL) {
    printf("Fila vazia!");
    return -1;
  }

  printf("[ ");
  while(atual != NULL){
    
    if(atual->proximo == NULL) 
      printf("%d", atual->valor);
    else 
      printf("%d - ", atual->valor);
    
    atual = atual->proximo;
  }
  printf(" ]");
  printf("\nTamanho da fila: %d\n\n", fila->tamanho);

  return 0;
}

int main() {
  Fila fila;
  fila.tamanho = 0;
  fila.inicio = NULL;
  fila.fim = NULL;

  entraNaFila(&fila, 1);
  entraNaFila(&fila, 2);
  entraNaFila(&fila, 3);
  entraNaFila(&fila, 4);
  entraNaFila(&fila, 5);
  imprimeFila(&fila);
  sairDaFila(&fila);
  imprimeFila(&fila);

  return 0;
}