/*-----------------------------------------------------------
This is a class to represent a caculator. Only to use for
postfix notation expressions.

Written by: Matthew Sweeterman
------------------------------------------------------------*/

#include <iostream>
#include <cstdlib>
#include <string>
#include "LLQueue.h"
#include "LLStacks.h"

using namespace std;

string GetUserInput();
Queue* ParseInput(string expression);
//Queue* CreateQueue(string expression);
string Evaluate(Queue* inputqueue);
//string InfixEvaluate(string expression);
bool IsOperator(string combine);
int DoOperation(string line, int operand1, int operand2);
/*-------------------- Public Functions --------------------*/
/*-----------------------------------------------------------
The main method outlines in what order the set the of methods,
external from any class, should run.

Preconditions: none
Postconditions: none
------------------------------------------------------------*/
int main() {
   string expression;
   string result;
   Queue *inputQueue;
   //user inputs thier expression
   cout << "Insert expression Here: ";
   expression = GetUserInput();
   //cout << endl << "YES" << expression<< endl;
   inputQueue = ParseInput(expression);
   //cout << endl << "Input parsed" << endl;
   result = Evaluate(inputQueue);
   //returns result
   cout << "Result is: " << result << "\n";
}

/*-----------------------------------------------------------
This method obtains the string the user input from the
terminal window.

Preconditions: none
Postconditions: return input user provided
------------------------------------------------------------*/

string GetUserInput () {
  string response;
  cout << "\n";
  getline(cin, response);
  return(response);
}


/*-----------------------------------------------------------
This method parseses the user inputted string and returns
it as a queue.

Preconditions: none.
Postconditions: returns queue with each varibale parsed.
------------------------------------------------------------*/

Queue* ParseInput(string expression) {
   string substr;
   int x;
   int space;
   string token;
   Queue* inputqueue = new Queue();
   cout << endl << "Expression is: " << expression << endl;

   while(expression.size() > 0) {
    //finds leading spaces
    x = expression.find_first_not_of(" ", 0);
    cout << endl << "X is: " << x << endl;

    //deletes leading spaces
    expression.erase(0, x);
    cout << endl << "X erased is: " << x << endl;

    //finds next space
    space = expression.find(" ");
    cout << endl << "Space is: " << space << endl;

    token = expression.substr(0, space);
    cout << endl << "Token is: "<< token << endl;

    //enqueues token into queue
    inputqueue->Enqueue(token);
    cout << endl << "Token is: " << token << endl;

    //erases token
    token.erase(token.begin(), token.end());
    cout << endl << "Substring Erased!" << endl;
  }

  //returns queue
  return(inputqueue);
}
/*
Queue* CreateQueue(string expression){
   Queue* prsexpres = new Queue();
   prsexpres -> Enqueue("2");
   prsexpres -> Enqueue("4");
   prsexpres -> Enqueue("+");
   return(prsexpres);
   cout << endl << prsexpres << endl;
}
*/

/*----------------------------------------------------------
This method evaluates the expression, in postfix that
was inputted by the user and returns the result as
a string.

Preconditions: none.
Postconditions: returns result of the expression
------------------------------------------------------------*/
string Evaluate(Queue* inputqueue){
   string items;
   string token;
   string returnMe;
   string operand1;
   string operand2;
   bool flag;
   //string expression;
   Stack* operators = new Stack;
   //cout << endl << "Stack Made" << endl;

   flag = inputqueue->Dequeue(items);
   //cout << endl << "Token Dequeued" << endl;
   //cout << endl << operators << endl;

  while(inputqueue->QueueSize() > 0){
    //if the value is a number
    if(IsOperator(items) == false){
      //cout << endl << "False" << endl;

      operators->Push(items);
      //cout << endl << "Pushed Token" << endl;
    }
    //if the value is an operator
    else {
      flag = operators->Pop(operand1);
      //cout << endl << "Pop 1" << endl;

      flag = operators->Pop(operand2);
      //cout << endl << "Pop 2" << endl;

      int fvalue = std::stoi(operand1);
      int svalue = std::stoi(operand2);

      int result = DoOperation(items, fvalue, svalue);
      //cout << endl << "Operation Successful" << endl;

      returnMe = to_string(result);
      //cout << endl << "Is a string" << endl;

      operators->Push(returnMe);
      //cout << endl << "String Pushed" << endl;
    }
  }
  //return value that is left on top
  return(returnMe);
  cout << endl << "Returned: " << returnMe << endl;

  delete operators;
  //cout << endl << "Stack Deleted" << endl;
}


/*-----------------------------------------------------------
This method changes the user inputted expression, in infix
notation, and changes it to postfix notation and then
evaluates the expression.

Preconditions: none
Postconditions: returns result of expression.
------------------------------------------------------------*/
/*-----------------------------------------------------------
string InfixEvaluate(string expression){
   Queue* postfixQ = new Queue();
   Stack* postfixS = new Stack();
   GetUserInput();
   while(expression > 0){
   if(IsOperator(foo) == false){
      postfixQ->Enqueue(expression());
   }
   else{

   }
}
------------------------------------------------------------*/


/*-----------------------------------------------------------
This method determines if the next item in the queue is an
operator.

Preconditions: none
Postconditions: return bool result.
------------------------------------------------------------*/

bool IsOperator(string combine){
  if(combine == "+" || combine == "-" || combine == "*" || combine == "/" || combine == "%") {
    return true;
  }
  return false;
}

/*-----------------------------------------------------------
This method combines the two operands together and returns
result using the proper operator.

Preconditions: none
Postconditions: returns result.
------------------------------------------------------------*/
int DoOperation(string line, int operand1, int operand2){
  if(line == "+"){
      return operand1 + operand2;
   }
  else if(line == "-"){
      return operand1 - operand2;
   }
  else if(line == "*"){
  return operand1 * operand2;
  }
  else if(line == "/"){
  return operand1 / operand2;
  }
  else if(line == "%"){
   return operand1 % operand2;
}
  else{
      cout<<"Unexpected Error \n";
      return -1;
   }
}
