#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>   
#define size 20

// for stacking operators
char operator_stack[size];
int operator_top = -1;

//for stacking integers for evaluation
int value_stack[size];
int value_top = -1;

void operator_push(char x){
        operator_stack[++operator_top]=x; 
}


char operator_pop(){  
        return operator_stack[operator_top--];
}

void value_push(int y){
        value_stack[++operator_top]=y; 
}

int value_pop(){  
        return value_stack[operator_top--];
}

//setting the precedance and returns higher for higher precedance
int precedance(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    
    if(x == '*' || x == '/' || x== '%'){
        return 2;
    }
    return 0;
}

//converts a infix expression to postfix expression
void infix_to_postfix(char infix[], char postfix[]){
    int i = 0, j= 0;
    char ch;

    //run while loop for the characters in infix array
    while((ch = infix[i++]) != '\0'){
        if(isdigit(ch)){                //check if the char is a digit or operator
            postfix[j++] = ch;
        }

        else if (ch == '('){            
            operator_push(ch);
        }
        else if (ch == ')'){            //if char is a ')' the pops the operator stack until '('
            while (operator_stack[operator_top] != '('){
                postfix[j++] = operator_pop();

            }
            operator_pop();
        }

        else{
            //while the operator stack is not empty , it compares the operator in stack with the current
            //operator and pops if the opertor in stack is of higher precedence else push the current operator
            while(operator_top != -1 && precedance(operator_stack[operator_top]) >= precedance(ch)){
                postfix[j++]  = operator_pop();
            }
            operator_push(ch);
        }

    }
    //Until the operator stack is empty it pops the stack and stors it in the postfix array
    while (operator_top != -1){
        postfix[j++] = operator_pop();
        
    }
    postfix[j]= '\0';           //marks the end of a string
}

//performs the evauation on the expression
int evaluate_postfix(char postfix[]) {
    int i = 0;
    char ch;
    int a, b;

    while ((ch = postfix[i++]) != '\0') {

        // Operand
        if (isdigit(ch)) {              //check if the the char is a digit or an operator
            value_push(ch - '0');       //converts character into a integer
        }

        // Operator
        else {
            b = value_pop();    //pops the top value from value stack and assigns it to b
            a = value_pop();    //pops the top value from value stack and assigns it to a

            switch (ch) {           //check the operator and performs the respective operation
                case '+': value_push(a + b); break;
                case '-': value_push(a - b); break;
                case '*': value_push(a * b); break;
                case '/': value_push(a / b); break;
                case '%': value_push(a % b); break;
            }
        }
    }
    return value_pop();
}



int main() {
    char infix[size], postfix[size];
    int result;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    result = evaluate_postfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}