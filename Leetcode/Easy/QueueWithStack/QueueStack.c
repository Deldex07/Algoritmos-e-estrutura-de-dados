#define MAX 30000
typedef struct {
    int sIN[MAX];
    int sOUT[MAX];
    int TopIN;
    int TopOUT;
} Stack;

void initStack( Stack *s ) {
    s->TopIN = -1;
    s->TopOUT = -1;
}

void push( Stack *s, int val ) {
    s->sIN[++s->TopIN] = val;
}

int pop( Stack *s ) {
    if (s->TopOUT == -1) {
        while (s->TopIN >= 0) {
            s->sOUT[++s->TopOUT] = s->sIN[s->TopIN--];
        }
    }
    if (s->TopOUT == -1) return -1;
    return s->sOUT[s->TopOUT--];
}

int peek ( Stack *s ) {
    if (s->TopOUT == -1) {
        while (s->TopIN >= 0) {
            s->sOUT[++s->TopOUT] = s->sIN[s->TopIN--];
        }
    }

    if (s->TopOUT == -1) return -1;
    return s->sOUT[s->TopOUT];
}

bool empty( Stack *s ) {
    return (s->TopIN == -1 && s->TopOUT == -1);
}

typedef struct {
    Stack s;    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));
    initStack(&obj->s);
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    push(&obj->s, x);
}

int myQueuePop(MyQueue* obj) {
    return pop(&obj->s);
}

int myQueuePeek(MyQueue* obj) {
    return peek(&obj->s);
}

bool myQueueEmpty(MyQueue* obj) {
    return empty(&obj->s);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/