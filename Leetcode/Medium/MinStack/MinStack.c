typedef struct {
    int tab[30005];
    int min[30005];
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack* s = (MinStack*)malloc(sizeof(MinStack));
    s->top = -1;
    return s;
}

void minStackPush(MinStack* s, int value) {
    s->top++;
    s->tab[s->top] = value;
    if(0 == s->top || value < s->min[s->top - 1]){
        s->min[s->top] = value;
    }else{
        s->min[s->top] = s->min[s->top-1];
    }
}

void minStackPop(MinStack* s) {
    s->top--;
}

int minStackTop(MinStack* s) {
    return s->tab[s->top];
}

int minStackGetMin(MinStack* s) {
    return s->min[s->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/