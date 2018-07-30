#include "linkedlist.h"

void push(int data) { insertFirst(data); }

int pop() { return deleteFirst(); }

int peek() { return getFirst(); }

int isEmpty() { return is_empty(); }

