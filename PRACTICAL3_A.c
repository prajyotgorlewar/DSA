#include <stdio.h>
#include <stdlib.h>

int currentElements = 0;

struct cirq
{
  int size;
  int f;
  int r;
  int *arr;
};

int isFull(struct cirq *q)
{
  if (q->r + 1 % q->size == q->f)
  {
    return 1;
  }

  return 0;
}

int isEmpty(struct cirq *q)
{
  if (q->r == q->f)
  {
    return 1;
  }

  return 0;
}

void enqueue(struct cirq *q, int val)
{
  if (isFull(q))
  {
    printf("Queue is Full");
  }

  else
  {
    q->r = (q->r + 1) % q->size;
    q->arr[q->r] = val;
    currentElements++;
  }
}

int dequeue(struct cirq *q)
{
  int a = -1;

  if (isEmpty(q))
  {
    printf("Queue is Empty");
  }

  else
  {
    q->f = (q->f + 1) % q->size;
    a = q->arr[q->f];
    currentElements--;
  }

  return a;
}

int front(struct cirq *q)
{
  int front;
  front = q->arr[q->f + 1];
  return front;
}

int main()
{
  struct cirq q;
  q.size = 10;
  q.f = q.r = -1;
  q.arr = (int *)malloc(q.size * sizeof(int));

  int choise;
  int element;
  int stopper = 0;

  printf("CIRUCLAR QUEUE\n");

  while (stopper == 0)
  {
    printf("Choose '1' to Enqueue, '2' to Dequeue,'3' to check isEmpty, '4' to return number of elements,'5' to return front element, '6' to return\n");
    scanf("%d", &choise);

    switch (choise)
    {

    case 1:
      if (!isFull(&q))
      {
        printf("Enter Element to Enqueue : ");
        scanf("%d", &element);
        enqueue(&q, element);
        break;
      }
      else
      {
        stopper = 1;
        break;
      }

    case 2:
      if (isEmpty(&q))
      {
        printf("No elements found to Dequeue\n");
      }
      else
      {
        printf("Dequeueing element %d\n", dequeue(&q));
      }
      break;

    case 3:
      if (isEmpty(&q))
      {
        printf("Queue is Empty\n");
      }
      else
      {
        printf("Queue is not Empty\n");
      }
      break;

    case 4:
      printf("There are %d elements present in circular queue\n", currentElements);
      break;

    case 5:
      if (isEmpty(&q))
      {
        printf("No elements found in queue\n");
      }
      else
      {
        printf("Front element of the queue is %d\n", front(&q));
      }
      break;

    case 6:
      stopper = 1;
      break;

    default:
      printf("Invalid Choise\n");
      break;
    }
  }
}