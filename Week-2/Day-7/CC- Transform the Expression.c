Reverse Polish Notation (RPN) is a mathematical notation where every operator follows all of its operands.
For instance, to add three and four, one would write "3 4 +" rather than "3 + 4". 
If there are multiple operations, the operator is given immediately after its second operand; so the expression written "3 − 4 + 5" would be written "3 4 − 5 +" first subtract 4 from 3,then add 5 to that.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 400

char stack[MAX];
int top = -1;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    return op == '^';
}

void toRPN(char* expr) {
    top = -1;

    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];

        if (isalpha(ch)) {
            printf("%c", ch);
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            if (top != -1) top--; 
        } else { // operator
            while (top != -1 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence(ch) ||
                  (precedence(stack[top]) == precedence(ch) && !isRightAssociative(ch)))) {
                printf("%c", stack[top--]);
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        printf("%c", stack[top--]);
    }

    printf("\n");
}

int main() {
    int t;
    char expr[MAX];

    scanf("%d", &t);
    getchar(); 

    while (t--) {
        fgets(expr, MAX, stdin);
        expr[strcspn(expr, "\n")] = '\0'; 
        toRPN(expr);
    }

    return 0;
}
