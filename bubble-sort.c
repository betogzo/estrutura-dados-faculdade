#include <stdlib.h>
#include <stdio.h>

void printArray(int * array, int arrayLength) {
  printf("[ ");
  for(int i = 0; i < arrayLength; i++) {
    if(i == arrayLength - 1)
      printf("%d ", array[i]);
    else 
      printf("%d - ", array[i]);
  }
      
  printf(" ]\n");
}

void bubbleSort(int * array, int arrayLength) {
  int aux = 0;

  for(int i = 0; i < arrayLength - 1; i++) {
    for (int j = i+1; j < arrayLength; j++)
      if (array[i] > array[j]) {
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
      }
  }
}

int main() {
  int array[11] = {9, 7, 2, 5, 3, 1, 10, 8, 0, 4, 6};
  int arrayLength = (int) sizeof(array) / (int) sizeof(int);
  
  printArray(array, arrayLength);
  bubbleSort(array, arrayLength); 
  printArray(array, arrayLength);

  return 0;
}