<h1>Checking balance number of parenthesis</h1> </br>
<b>Objective:</b>
The objective of this program is the analyze  mathematical expression and check
if it has balanced number of parenthesis '()','{}','[]' or not.

<b>Defining Data-Structures:</b></br>
  #define size 20 
  char stack[size];  
  int top = -1;
  
<b>Explanation:</b></br>
•#define size 20 it initializes the size of the array</br>
•stack[size] sets a character array of defined size</br>
•top = -1 initializes the top of stack to be -1</br>
<b>Functions:</b></br>
•push(char x): push function is used to insert an item into the stack.</br>
•pop(): Pop function is used to remove an item from a stack.</br>
•isMatching: This function check if the opening parenthesis matches with the closing parenthesis.</br>
•isBalanced: This function check if the opening parenthesis has its matching closing parenthesis    and returns if the mathematical expression is balanced or not.</br>
•main(): The main fuction performs following operations:</br>
- Declares a character array to store the expression
- Aceepts the expression from the user
- Calls the isbalanced() function
- Displays whether the expression is balanced or not
