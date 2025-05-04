#define SIZE 1000000

struct Node
{
  int key, value;
  struct Node *next;
};

struct Node *table[SIZE] = {NULL};

void hash_insert(int key, int value)
{
  int index = key % SIZE;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = table[index];
  table[index] = newNode;
}

int hash_get(int key)
{
  int index = key % SIZE;
  struct Node *current = table[index];
  while (current)
  {
    if (current->key == key)
    {
      return current->value;
    }
    current = current->next;
  }
  return -1;
}

int hash_clear(int key)
{
  int index = key % SIZE;
  struct Node *current = table[index];
  struct Node *prev;
  while (current)
  {
    if (current->key == key)
    {
      if (current == table[index])
        table[index] = NULL;
      else
        prev->next = NULL;
      free(current);
      return key;
    }
    prev = current;
    current = current->next;
  }
  return -1;
}

int *queue;
int queue_size;
int front = 0, rear = 0;

void enqueue(int data)
{
  queue[rear] = data;
  rear = (rear + 1) % queue_size;
}
int dequeue()
{
  if (front == rear)
    return -1;
  int res = queue[front];
  front = (front + 1) % queue_size;
  return res;
}

int get_queue_size()
{
  return (rear + queue_size - front) % queue_size;
}

int getMaximumEatenDishCount(int N, int *D, int K)
{
  // Write your code here
  if (N <= 1)
  {
    return N;
  }

  queue_size = K + 2; // queue size for K+1 diskes, need another one for queue full statement
  queue = (int *)malloc(queue_size * sizeof(int));

  int dishEat = 0;
  for (int i = 0; i < N; i++)
  {
    if (hash_get(D[i]) > 0)
    {
      continue;
    }

    enqueue(D[i]);
    hash_insert(D[i], 1);
    dishEat++;

    if (get_queue_size() > K)
    {
      hash_clear(dequeue());
    }
  }

  free(queue);
  return dishEat;
}