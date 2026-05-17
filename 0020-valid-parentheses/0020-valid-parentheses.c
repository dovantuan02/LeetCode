bool isValid(char* s) {
    char stack[strlen(s)];
    int top = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[top++] = c;
        } else {
            if (top == 0) {
                return false;
            }

            char open = stack[--top];

            if (c == ')' && open != '(') return false;
            if (c == '}' && open != '{') return false;
            if (c == ']' && open != '[') return false;
        }
    }

    return top == 0;
}