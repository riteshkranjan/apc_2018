#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head;

struct node *createNode(int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void insertFirst(int data) {
  struct node *temp = createNode(data);
  temp->next = head;
  head = temp;
}

int deleteFirst() {
  struct node *temp = head;
  int data = temp->data;
  head = head->next;
  return data;
}

int is_empty() { return !head; }

int getFirst(){ return head->data; }

