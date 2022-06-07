#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int valor;
  struct No *proximo;
} No;

typedef struct Pilha {
  int tamanho;
  No *topo;
} Pilha;

void empilhar(Pilha *pilha, int valor) {
  No *novo = (No *) malloc(sizeof(No));
  
  novo->valor = valor;
  novo->proximo = pilha->topo;
  pilha->topo = novo;
  pilha->tamanho++;
}

void desempilhar(Pilha *pilha) {
  No *ptr = pilha->topo;

  if (!ptr) {
    printf("Pilha vazia. Nada a desempilhar!");
  } else {
    pilha->topo = ptr->proximo;
    free(ptr);
    pilha->tamanho--;
  }
}

void imprime(Pilha *pilha) {
  No *aux;
  aux = pilha->topo;

  system("clear");
  
  printf("\n[ ");
  while(aux != NULL) {
    if (aux->proximo == NULL) {
      printf("%d", aux->valor);
    } else  {
      printf("%d - ", aux->valor);
    }
    aux = aux->proximo;
  }
  printf(" ]\n");

  printf("Tamanho da pilha: %d\n", pilha->tamanho);

}

int main() {
  Pilha pilha;
  pilha.tamanho = 0;
  pilha.topo = NULL;

  empilhar(&pilha, 1);
  empilhar(&pilha, 2);
  empilhar(&pilha, 3);
  empilhar(&pilha, 4);
  empilhar(&pilha, 5);
  empilhar(&pilha, 6);
  imprime(&pilha);

  desempilhar(&pilha);
  desempilhar(&pilha);
  desempilhar(&pilha);

  imprime(&pilha);

  return 0;
}