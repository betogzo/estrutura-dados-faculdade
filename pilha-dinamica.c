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

  if(pilha->tamanho == 0)
    printf("Pilha vazia!");

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

  if(pilha->tamanho > 0)
    printf("Tamanho da pilha: %d\n", pilha->tamanho);
}

void limparPilha(Pilha *pilha) {
  if(pilha->tamanho == 0)
    printf("Nada a limpar. A pilha já está vazia!");
  
  int tamanho = pilha->tamanho;

  while(tamanho > 0) {
    desempilhar(pilha);
    tamanho--;
  }
  system("clear");
  printf("\n[ ] A pilha foi limpa com sucesso.\n");
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
  desempilhar(&pilha);
  imprime(&pilha);

  // limparPilha(&pilha);

  return 0;
}