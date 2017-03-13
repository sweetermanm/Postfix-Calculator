/*------------------------------------------------------------------
A standard stack implementation using a linked list implementation.

Written by Mikeyg
------------------------------------------------------------------*/

#include "LLStacks.h"
#include <iostream>
#include <cstdlib>


// ************************** Public Functions *********************
/*------------------------------------------------------------------
The default Stack constructor.

Preconditions: none.
Postconditions: stackSize = 0 and head = NULL.
------------------------------------------------------------------*/
Stack::Stack () {
    head = NULL;
    stackSize = 0;
}


/*------------------------------------------------------------------
The default Stack destructor.

Preconditions: none.
Postconditions: stackSize = 0; head = NULL
------------------------------------------------------------------*/
Stack::~Stack () {
  DeleteStack();
}


/*------------------------------------------------------------------
Push inserts a new value into the stack

Preconditions: none.
Postconditions: stackSize > 0, head != NULL
------------------------------------------------------------------*/
void Stack::Push (sType value) {
    StackNode* temp = new StackNode;
    temp->value = value;
    temp->next = head;
    head = temp;
    stackSize++;
}


/*------------------------------------------------------------------
Pop returns to the user the value of head->value (if defined).

Preconditions: none.
Postconditions: stackSize-- if head != NULL.
	head = head->next if stackSize > 0, NULL o.w.
------------------------------------------------------------------*/
bool Stack::Pop (sType &value) {
    bool retValue = false;

    // Is the stack empty
    if (head != NULL) {
        StackNode* temp = head;
        head = head->next;
        value = temp->value;
        stackSize--;
        retValue = true;
		delete temp;
    }

    return (retValue);
}


/*------------------------------------------------------------------
Top returns to the user the value of head->value (if head != NULL).

Preconditions: none.
Postconditions: none.
------------------------------------------------------------------*/
bool Stack::Top (sType &value) const {
    bool retValue = false;
    if (head != NULL) {
		retValue = true;
		value = head->value;
    }
    return (retValue);
}


/*------------------------------------------------------------------
IsEmpty is a predicate function that determines whether or not the
	stack is empty or not.
Preconditions: none.
Postconditions: none.
------------------------------------------------------------------*/
bool Stack::IsEmpty () const {
    return (head == NULL);
}


/*------------------------------------------------------------------
NumOfStackEntries returns the number of values currently on the
	stack.
Preconditions: none.
Postconditions: none.
------------------------------------------------------------------*/
int Stack::NumOfStackEntries () const {

    return (stackSize);
}


// *********************** Friendly Functions *********************
/*------------------------------------------------------------------
Overloaded output (<<) traveres the stack outputting on the console
each value on the specified stack.

Preconditions: none.
Postconditions: none.
------------------------------------------------------------------*/
ostream& operator << (ostream& outs, const Stack& target) {
    int count = 0;
    StackNode *temp = target.head;
    while (temp != NULL) {
		count++;
		outs << "Item number " << count << " on the stack is: " <<
			temp->value << endl;
		temp = temp->next;
    }

    if (count == 0) {
        outs << endl << "The stack is empty" << endl;
    }

    return(outs);
}


// ************************** Private Functions *********************
/*------------------------------------------------------------------
DeleteStack deallocates all the nodes associated with "this" stack.
Preconditions: none.
Postconditions: stackSize = 0, head = NULL
------------------------------------------------------------------*/
void Stack::DeleteStack () {
    StackNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    stackSize = 0;
}
