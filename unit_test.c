#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void test_stack() {
  push(1);
  push(2);
  push(3);
  assert(isEmpty() == 0);
  assert(peek() == 3);
  assert(pop() == 3);
  assert(pop() == 2);
  assert(pop() == 1);
  assert(isEmpty() == 1);
  printf("test_stack.c : all test cases passed\n");
}

void test_linkedlist() {
  insertFirst(1);
  insertFirst(2);
  insertFirst(3);
  assert(is_empty() == 0);
  assert(deleteFirst() == 3);
  assert(deleteFirst() == 2);
  assert(deleteFirst() == 1);
  assert(is_empty() == 1);
  printf("test_linkedlist : all test cases passed\n");
}

int main() {
  test_linkedlist();
  test_stack();
  return 1;
}

