#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
}queue;
typedef struct Q
{
    queue *front;
    queue *rear;
}Q;
void init(Q *p)
{
    p->front = p->rear = NULL;
}
int isEmpty(Q *p)
{
    if(p->front == NULL)
        return 1;
    return 0;
}
void enqueue(Q *p, int value)
{
    queue *q;
    q = (queue*)malloc(sizeof(queue));
    q->next = NULL;
    q->data = value;
    if(isEmpty(p))
    {
        p->front = p->rear = q;
    }
    else
    {

        (p->rear)->next = q;
        p->rear = q;

    }
}
int dequeue(Q *p)
{
    int x ;
    queue *q;
    q = p->front;
    x = q->data;
    if(q == p->rear)
        init(p);
    else
        p->front = q->next;
    free(q);
    return x;
}

void display(Q *p)
{
    queue *q;
    q = p->front;
    while(q != NULL)
    {
        printf("%d\n", q->data);
        q = q->next;
    }
}
queue* search(Q *p, int item)
{
    queue *q;
    q = p->front;
    while(q != NULL)
    {
        if(q->data == item)
            return q;
        q = q->next;
    }
    printf("Element NOT Found.");
}
int main()
{
    int x, choice, value, item;
    Q q;
    init(&q);
    do
    {
    printf("\n1: Enqueue \n");
    printf("2: Dequeue \n");
    printf("3: Display \n");
    printf("4: Search \n");
    printf("5: EXIT \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;

        case 2:
            if(!isEmpty(&q))
            {
                int del_item = dequeue(&q);
                printf("Deleted Item is: %d", del_item);
            }

            else
                printf("UNDERFLOW");
            break;
        case 3:
            if(!isEmpty(&q))
                display(&q);
            else
                printf("UNDERFLOW");

            break;
        case 4:
            printf("Enter element to search: ");
            scanf("%d", &item);
            if(!isEmpty(&q))
            {
                queue item_loc = search(&q, item);
                printf("%d is located at Address: %u", item, item_loc);

            }

            else
                printf("UNDERFLOW");
            break;
        }
    }while(choice != 5);
}
