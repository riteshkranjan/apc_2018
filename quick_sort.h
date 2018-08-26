void swap(void *a[], int i, int j) {
  void *t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void quick_sort(void *a[], int L, int R, int (*cmp)(void *, void *)) {
  if (R <= L)
    return;
  int last = L;
  for (int i = L + 1; i <= R; i++) {
    if ((*cmp)(a[L], a[i]) > 0) {
      swap(a, ++last, i);
    }
  }
  swap(a, L, last);
  quick_sort(a, L, last - 1, cmp);
  quick_sort(a, last + 1, R, cmp);
}