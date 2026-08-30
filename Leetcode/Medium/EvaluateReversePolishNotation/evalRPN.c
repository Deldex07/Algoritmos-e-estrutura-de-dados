int evalRPN( char** tokens, int tokensSize ) {
    int top = -1;
    int stack[tokensSize];

    for ( int i = 0; i < tokensSize; i++ ) {

        if ( strlen( tokens[i] ) == 1 && ( tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/' ) ) {
            
            int b = stack[top--]; 
            int a = stack[top--];

            int res = 0;
            switch ( tokens[i][0] ) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            stack[++top] = res;

        } else {

            int val = atoi( tokens[i] );
            stack[++top] = val;
        }
    }

    return stack[top];
}