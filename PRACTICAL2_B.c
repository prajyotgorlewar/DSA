#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct Stack {
    int top;
    char items[100]; // Define the maximum stack size here
};


void initialize(struct Stack *stack) {
    stack->top = -1;
}
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
int isFull(struct Stack *stack) {
    return stack->top == 9; 
}


void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}


int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    struct Stack stack;
    initialize(&stack);
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        }
         else if (token == '(') 
        {
            push(&stack, token);
        } 
        else if (token == ')') 
        {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == '(') {
                pop(&stack); 
            } else {
                printf("Invalid expression\n");
                return;
            }
        } 
        else 
        {
            while (!isEmpty(&stack) && getPrecedence(token) <= getPrecedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }

        i++;
    }
  
    while (!isEmpty(&stack)) 
    {
        if (stack.items[stack.top] == '(') {
            printf("Invalid expression\n");
            return;
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char *postfix) 
{
    struct Stack stack;
    initialize(&stack);
    int i = 0;

    while (postfix[i] != '\0') 
    {
        char token = postfix[i];
        if (isdigit(token)) 
        {
            push(&stack, token - '0'); 
        } 
        else 
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            
            switch (token) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) 
                    {
                        push(&stack, operand1 / operand2);
                    } 
                    else 
                    {
                        printf("Invalid\n");
                        return 0; 
                    }
                    break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }
        }

        i++;
    }

    if (!isEmpty(&stack)) 
    {
        return pop(&stack);
    } 
    else 
    {
        printf("Invalid postfix expression\n");
        return 0;
    }
}

int main()
{
    char infix[10];
    char postfix[10];
    printf("Enter infix Expression : ");
    scanf("%s",infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Value postfix expression: %d\n", result);
}