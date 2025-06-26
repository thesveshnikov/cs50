#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

typedef struct
{
    node *head;
    node *tail;
}
queue;

void enqueue(queue *q, int value);
int dequeue(queue *q);
bool is_empty(queue *q);

int main(void)
{
    queue q = {NULL, NULL};

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    return 0;
}

void enqueue(queue *q, int value)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }
    n->value = value;
    n->next = NULL;

    if (q->tail != NULL)
    {
        q->tail->next = n;
    }
    q->tail = n;
    if (q->head == NULL)
    {
        q->head = n;
    }
}

int dequeue(queue *q)
{
    if (is_empty(q))
    {
        printf("Queue underflow\n");
        exit(1);
    }

    node *tmp = q->head;
    int value = tmp->value;
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(tmp);
    return value;
}

bool is_empty(queue *q)
{
    return q->head == NULL;
}
