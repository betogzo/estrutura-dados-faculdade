#include <stdlib.h>
#include <stdio.h>

void printarray(int * array, int arrayLength) {
  printf("[ ");
  for(int i = 0; i < arrayLength; i++) {
    if(i == arrayLength - 1)
      printf("%d ", array[i]);
    else 
      printf("%d - ", array[i]);
  }
      
  printf(" ]\n");
}

void selectionSort(int * array,int arrayLength) {
  int menor, aux;

  for(int i = 0; i < arrayLength - 1; i++ ){
    menor = i;
    for(int j = i + 1; j < arrayLength; j++) {
      if(array[menor] > array[j])
        menor = j;
    }
    if (i != menor) {
      aux = array[i];
      array[i] = array[menor];
      array[menor] = aux;
    }
  }
}

int main() {
  int array[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int arrayLength = (int) sizeof(array) / (int) sizeof(int);
  
  printarray(array, arrayLength);
  selectionSort(array, arrayLength); 
  printarray(array, arrayLength);

  return 0;
}