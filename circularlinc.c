#include<stdio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
int main() {
  struct Node *head = NULL, *temp, *newNode;
  int n, i, val;
  printf("Enter number of nodes: ");
  scanf("%d", &n);
  for (i = 0; i<n; i++) {
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &val);
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = val;
    if (head == NULL) {
      newNode->next = newNode;
      head = newNode;
    } else {
      temp = head;
      while (temp->next != head)
        temp = temp->next;
      temp->next = newNode;
      newNode->next = head;
   }
}
printf("Circular Linked List: ");
temp = head;
do {
  printf("%d ->", temp->data);
  temp = temp->next;
} while (temp != head);
printf("(head)\n");
return 0;
}
