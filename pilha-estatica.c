//"Last in, First Out"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 5

typedef struct estrutura_pilha {
  int dados[tamanho];
  int inicio;
  int topo;
} estrutura_pilha;

estrutura_pilha pilha;

void mostrar_pilha();
void mostrar_menu();
void empilhar();
void desempilhar();

int main() {
  setlocale(LC_ALL, "Portuguese");
  int opcao = 1;
  pilha.inicio = 0;
  pilha.topo = 0;

  while(opcao != 0) {
    system("clear");
    mostrar_pilha();
    mostrar_menu();
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        empilhar();
        break;
      case 2:
        desempilhar();
        break;
      case 0:
        system("clear");
        break;
      default:
        printf("Opção inválida!");
    }
  }

  return 0;
}

void mostrar_pilha() {
  printf("\n[");
  for(int i = 0; i < tamanho; i++) {
    printf(" %d ", pilha.dados[i]);
  }
  printf("]\n\n");
}

void mostrar_menu() {
  printf("1 - Empilhar\n");
  printf("2 - Desempilhar\n");
  printf("0 - Sair\n\n");
  printf("Digite a opção desejada: ");
}

void empilhar() {
  if (pilha.topo == tamanho) {
    printf("Pilha cheia!");
    system("pause");
  } else {
    int elemento = 0;
    printf("\nDigite o elemento a ser empilhado: ");
    scanf("%d", &elemento);
    pilha.dados[pilha.topo] = elemento;
    pilha.topo++;
  }
}

void desempilhar() {
  if(pilha.topo == pilha.inicio) {
    printf("A Pilha está vazia.");
  } else {
    pilha.topo--;
    pilha.dados[pilha.topo] = 0;
  }
}