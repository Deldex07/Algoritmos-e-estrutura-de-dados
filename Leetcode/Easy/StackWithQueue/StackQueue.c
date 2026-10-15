#define MAX_DATA 101
typedef struct {
    int data[MAX_DATA];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool EmptyQ(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int val) {
    q->rear = (q->rear + 1) % MAX_DATA;
    q->data[q->rear] = val;
    q->size++;
}

int dequeue(Queue *q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_DATA;
    q->size--;
    return val;
}

int peek(Queue *q) {
    return q->data[q->front];
}

typedef struct {
    Queue q;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&obj->q);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q, x);
    
    int stacking = obj->q.size - 1;
    while (stacking > 0) {
        enqueue(&obj->q, dequeue(&obj->q));
        stacking--;
    }
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q);
}

int myStackTop(MyStack* obj) {
    return peek(&obj->q);
}

bool myStackEmpty(MyStack* obj) {
    return EmptyQ(&obj->q);
}

void myStackFree(MyStack* obj) {
    free(obj);
}