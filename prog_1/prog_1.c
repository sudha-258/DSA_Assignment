#include <stdio.h>
#include <string.h>

#define size 20     //defining the size of the array

char stack[size];   //initializing the array for stack
int top = -1;       //initializing the top to be -1


//Defining the push function
void push(char x) {     
    if (top == size - 1) {      //checks the condition for full stack
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = x;
}

//Defining the function for pop
char pop() {
    if (top == -1) {    //checks the condition for empty
        return '\0';   
    }
    return stack[top--];
}


int isMatching(char open, char close) {         //check if the opening and closing bracket matches
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}


int isbalanced(char exp[]) {        //checks if the opening bracket has respective closing bracket
    for (int i = 0; exp[i] != '\0'; i++) {      //runs loops for the no. of char
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {      
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char open = pop();
            if (open == '\0' || !isMatching(open, ch)) {    //handles cases for null and mismatch
                return 0;   
            }
        }
    }
    return (top == -1);   
}

int main() {
    char exp[50];

    printf("Enter the expression: ");
    scanf("%s", exp);

    if (isbalanced(exp))
        printf("The expression is balanced\n");
    else
        printf("The expression is not balanced\n");

    return 0;
}