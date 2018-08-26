#include "merge_sort.h"
#include "quick_sort.h"
#include <stdio.h>
#include <stdlib.h>

int intCmp(void *i, void *j) {
  int *x = (int *)i;
  int *y = (int *)j;
  if (*x > *y)
    return +1;
  if (*x == *y)
    return 0;
  return -1;
}

void print(int **a, int c) {
  for (int i = 0; i <= c; i++) {
    printf("%d->", *((int *)*(a + i)));
  }
  printf("End\n");
}

int main() {
  printf("enter input size:");
  int n;
  scanf("%d", &n);
  int **b = (int **)malloc(sizeof(int *) * n);

  int i;
  for (i = 0; i < n; i++) {
    printf("enter input:");
    int *num = (int *)malloc(sizeof(int *));
    scanf("%d", num);
    b[i] = num;
  }
  printf("input = ");
  print(b, n - 1);
  printf("enter sorting algo to be used : 1 (merge) or 0 (quick) :");
  int algo;
  scanf("%d", &algo);
  if (algo) {
    printf("running merge sort...\n");
    int **aux = (int **)malloc(sizeof(int *) * n);
    mergeSort((void **)b, 0, n - 1, (void **)aux,
              (int (*)(void *, void *))intCmp);
  } else {
    printf("running quick sort...\n");
    quick_sort((void **)b, 0, n - 1, (int (*)(void *, void *))intCmp);
  }
  printf("sorted output = ");
  print(b, n - 1);
}
