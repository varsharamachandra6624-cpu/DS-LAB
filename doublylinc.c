#include<stdio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *createNode(int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

int insertEnd(struct Node **head, struct Node **tail, int data) {
  struct Node *newNode = createNode(data);
  if (newNode == NULL) {
    return 0;
  }
  if (*head == NULL) {
    *head = newNode;
    *tail = newNode;
  } else {
    newNode->prev = *tail;
    (*tail)->next = newNode;
    *tail = newNode;
  }
return 1;
}

void displayForward(struct Node *head) {
  struct Node *temp = head;
  printf("Forward: ");
  while (temp != NULL) {
    printf("%d <->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}
void displayBackward(struct Node *tail) {
  struct Node *temp = tail;
  printf("Backward: ");
  while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->prev;
  }
  printf("NULL\n");
}

void freeList(struct Node *head) {
  struct Node *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}
int main(void) {
  struct Node *head = NULL;
  struct Node *tail = NULL;
  int n, i, data;
  printf("Enter number of nodes: ");
  if (scanf("%d", &n) != 1 || n < 0) {
    printf("Invalid number of nodes.\n");
    return 1;
  }
  for (i = 0; i < n; i++) {
    printf("Enter data for node %d: ", i + 1);
    if (scanf("%d", &data) != 1) {
      printf("Invalid data input.\n");
      freeList(head);
      return 1;
    }
    if (!insertEnd(&head, &tail, data)) {
      printf("Unable to insert node.\n");
      freeList(head);
      return 1;
    }  
  }
  displayForward(head);
  displayBackward(tail);
  freeList(head);
  return 0;
}
