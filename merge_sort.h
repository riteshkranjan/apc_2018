void merge(void *a[], int L, int R, int mid, void *aux[],
           int (*cmp)(void *, void *)) {
  int i = L;
  int j = mid + 1;
  for (int k = L; k <= R; k++) {
    if (i > mid)
      aux[k] = a[j++];
    else if (j > R)
      aux[k] = a[i++];
    else if ((*cmp)(a[i], a[j]) == 1)
      aux[k] = a[j++];
    else
      aux[k] = a[i++];
  }
  for (int k = L; k <= R; k++)
    a[k] = aux[k];
}

void mergeSort(void *a[], int L, int R, void *aux[],
               int (*cmp)(void *, void *)) {

  if (R <= L)
    return;
  int mid = (L + R) / 2;
  mergeSort(a, L, mid, aux, cmp);
  mergeSort(a, mid + 1, R, aux, cmp);
  merge(a, L, R, mid, aux, cmp);
}