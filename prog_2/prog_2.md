# Infix To Postfix Conversion And Evaluation
## Objective:
    The objective of this program is to convert an infix expression to a postfix operation
    and perform the evaluation.

### Defining Data-Structures:
```c
#include<ctype.h>   
#define size 20
char operator_stack[size];
int operator_top = -1;
int value_stack[size];
int value_top = -1;
```

**Explanation:**
* `#include<ctype.h>`: is a header file that includes the isdigit() function later used in 
                      the program
* `#define size 20` it initializes the size of the array
* `operator_stack[size]`: sets a character  array for operators of defined size
* `operator_top = -1` initializes the top of the operator stack to be -1
* `value_stack[size]`: sets a character  array for value of defined size
* `value_top = -1` initializes the top of the value stack to be -1

### Functions
* `main()`: The main fuction performs following operations:<br>
          - Declares a character array to store the expression<br>
          - Aceepts the expression from the user<br>
          - Calls the `infix_to_postfix` function<br>
          - Displays the evaluated postfix expression<br>
* `void infix_to_prefix(char infix[],char prefix[]){}`:
          This function converts the provide infix expression to it postfix form.
* `int evaluate_postfix(char postfix[]){}`: This function performs the evaluation on
          the postfix expression
* `int precedance(char x){}`: sets the precedance and returns higher for higher precedance
