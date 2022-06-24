#include <stdio.h>

void insertionSort(int a[], int length) {
  for(int i = 1; i < length; i++) {
    int key = a[i]; //value to be compared
    int j = i - 1;

    while(j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
}

void printArray(int a[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
  int a[] = {9, 2, 4, 7, 8, 1, 3, 5};
  insertionSort(a, 8);
  printArray(a, 8);
  
  return 0;
}