//20 . Valid Parentheses
#include<stdbool.h>

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char current = s[i];
        
        if (current == '(' || current == '[' || current == '{') {
            stack[++top] = current;
        } else {
            if (top == -1) return false;
    
            char lastOpen = stack[top--]; 

            if (current == ')' && lastOpen != '(') return false;
            if (current == ']' && lastOpen != '[') return false;
            if (current == '}' && lastOpen != '{') return false;
        }
    }
    return top == -1;
}

/*
O(n) e O(n), espaço e tempo
*/