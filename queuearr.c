#include<stdio.h>
#define MAX 5
int queue[MAX], front = 0, rear = -1;
int enqueue(int val)
{
  if (rear == MAX - 1) {
    printf("Queue Overflow\n");
    return 0;
  }
  queue[++rear] = val;
  return 1;
}
int dequeue(int *val)
{
  if (front>rear) {
    printf("Queue Underflow\n");
    return 0;
  }
  *val = queue[front++];
  return 1;
}
void display()
{
  int i;
  if (front>rear) {
    printf("Queue is empty\n&quot");
    return;
  }
  printf("Queue (front to rear): ");
  for (i = front; i <= rear; i++)
    printf("%d", queue[i]);
  printf("\n");
}
int main()
{
  int n, i, val, removed;
  printf("Enter number of elements to enqueue (max %d): ", MAX);
  if (scanf("%d", &n) != 1 || n<1 || n>MAX) {
    printf("Invalid number of elements\n");
    return 1;
  }
  for (i = 0; i<n; i++) {
    printf("Enter element %d: ", i + 1);
    if (scanf("%d", &val) != 1) {
      printf("Invalid input\n");

      return 1;
    }
  enqueue(val);
  }
  printf("\nBefore DEQUEUE:\n");
  display();
  if (dequeue(&removed))
    printf("Dequeued element: %d\n", removed);
  printf("\nAfter DEQUEUE:\n");
  display();
  return 0;
}
