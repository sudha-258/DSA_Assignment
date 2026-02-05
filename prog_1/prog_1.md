@@ -1,15 +1,31 @@
# Checking balance number of parenthesis
## Objective:
    The objective of this program is the analyze a mathematical expression and check
    if it has balanced number of parenthesis '()','{}','[]' or not.
### Defining Data-Structures:
```c
#define size 20    
char stack[size];   
int top = -1; ```
```

**Explanation:**
```c
*`#define size 20` it initializes the size of the array
* `stack[size]` sets a character array of defined size
* `top = -1` initializes the top of stack to be -1

<b>**Functions:**</b>
* `push(char x)`: push function is used to insert an item into the stack.
* `pop()`: Pop function is used to remove an item from a stack.
* `isMatching`: This function check if the opening parenthesis matches with the closing parenthesis.
* `isBalanced`: This function check if the opening parenthesis has its matching closing parenthesis and returns if the mathematical expression is balanced or not.
* `main()`: The main fuction performs following operations:<br>
          - Declares a character array to store the expression<br>
          - Aceepts the expression from the user<br>
          - Calls the isbalanced() function<br>
          - Displays whether the expression is balanced or not<br>
