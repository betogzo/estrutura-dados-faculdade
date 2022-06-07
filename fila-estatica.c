//"First in, First out"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 5

typedef struct estrutura_fila {
  int dados[tamanho];
  int inicio;
  int fim;
} estrutura_fila;

estrutura_fila fila;

void mostrar_fila();
void mostrar_menu();
void fila_entrar();
void fila_sair();

int main() {
  setlocale(LC_ALL, "Portuguese");
  int opcao = 1;
  fila.inicio = 0;
  fila.fim = 0;

  while(opcao != 0) {
    system("clear");
    mostrar_fila();
    mostrar_menu();
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        fila_entrar();
        break;
      case 2:
        fila_sair();
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

void mostrar_fila() {
  printf("\n[");
  for(int i = 0; i < tamanho; i++) {
    printf(" %d ", fila.dados[i]);
  }
  printf("]\n\n");
}

void mostrar_menu() {
  printf("1 - Entrar na fila\n");
  printf("2 - Sair da fila\n");
  printf("0 - Sair da aplicação\n\n");
  printf("Digite a opção desejada: ");
}

void fila_entrar() {
  if (fila.fim == tamanho) {
    printf("fila cheia!");
    system("pause");
  } else {
    int elemento = 0;
    printf("\nDigite o elemento a ser emfilado: ");
    scanf("%d", &elemento);
    fila.dados[fila.fim] = elemento;
    fila.fim++;
  }
}

void fila_sair() {
  if(fila.fim == fila.inicio) {
    printf("A fila está vazia.");
  } else {
    for (int i = 0; i < tamanho; i++) {
      fila.dados[i] = fila.dados[i+1];
    }
    fila.dados[fila.fim] = 0;
    fila.fim--;
  }
}