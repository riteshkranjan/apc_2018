#include <assert.h>
#include <stdio.h>
#include "stack.h"
#include "bitwise.h"
void test_stack() {
  printf("Testing bitwise...\n");
  push(1);
  push(2);
  push(3);
  assert(isEmpty() == 0);
  assert(peek() == 3);
  assert(pop() == 3);
  assert(pop() == 2);
  assert(pop() == 1);
  assert(isEmpty() == 1);
  printf("stack : all test cases passed\n");
}

void test_linkedlist() {
  printf("Testing bitwise...\n");
  insertFirst(1);
  insertFirst(2);
  insertFirst(3);
  assert(is_empty() == 0);
  assert(deleteFirst() == 3);
  assert(deleteFirst() == 2);
  assert(deleteFirst() == 1);
  assert(is_empty() == 1);
  printf("linkedlist : all test cases passed\n");
}

void test_bitwise() {
	printf("Testing bitwise...\n");
	assert(sign(-5) == -1);
	assert(sign(0) == 0);
	assert(sign(5) == 1);
	assert(bitAnd(1, 3) == 1);
	assert(bitXor(1, 3) == 2);
	assert(getByte(0xABCD, 0) == 0xCD);
	assert(getByte(0xABCD, 1) == 0xAB);
	assert(logicalShift(-1,30)==3);
	assert(bang(5) == 0);
	assert(bang(-5) == 0);
	assert(bang(0) == 1);
	assert(conditional(5, 4, 6) == 4);
	assert(conditional(0, 4, 6) == 6);
	assert(isPower2(8) == 1);
	assert(isPower2(7) == 0);
	assert(isPower2(-8) == 0);
	printf("bitwise : all test cases passed...\n");
}

int main() {
  test_linkedlist();
  test_stack();
  test_bitwise();
  return 1;
}

