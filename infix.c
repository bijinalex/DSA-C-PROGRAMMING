#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char current;
    while ((current = infix[i++]) != '\0') {
        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            push(current);
        } else if (current == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Discard '('
        } else if (isOperator(current)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(current)) {
                postfix[j++] = pop();
            }
            push(current);
        }
    }
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
