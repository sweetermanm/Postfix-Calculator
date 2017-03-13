#ifndef _LLStacks_H
#define _LLStacks_H

/*------------------------------------------------------------------
A standard linked-list implementation of a stack class.  Given the
linked-list implementation, there is no upper limit on the number
of elements that the stack can contain.

Written by Mikeyg
------------------------------------------------------------------*/

#include <iostream>

using namespace std;

// Definition of what the stack can store.
typedef string sType;

// Definition of a stack node.
struct StackNode {
    sType value;
    StackNode *next;
};


class Stack {

  public:
    // Constructors & destructors
    /*--------------------------------------------------------------
    The default stack constructor provides the caller with an
    	initially empty stack.  (IsEmpty == TRUE).
    --------------------------------------------------------------*/
    Stack ();

    /*--------------------------------------------------------------
    The default stack destructor: deallocates all dynamically
    	allocated memory (i.e. StackNodes).
    --------------------------------------------------------------*/
    ~Stack ();


    // Modification Methods
    /*--------------------------------------------------------------
    The Push method adds the provided value (value) to the stack.
    Precondition: none.
    Postcondition: The number of elements being stored on the stack
    	is one greater than before. (IsEmpty == false)
    --------------------------------------------------------------*/
    void Push (sType value);

    /*--------------------------------------------------------------
    The Pop methods removes the most recently added element that has
    	yet to be removed from the stack, and returns the value to
    	the caller; via the reference parameter.
    	If (IsEmpty) the return value is false, o.w. true.
    Precondition: none.
    Postcondition: The number of elements being stored in the stack
    	is one less than before.
    --------------------------------------------------------------*/
    bool Pop (sType &value);


    // Constant Methods
    /*--------------------------------------------------------------
    The Top method does not alter the contents of the stack.  It
    	returns to the caller the value (via a reference parameter)
    	that will be returned by the next Pop (assuming no Push
	occurs.)  Top reports on the value of the most recently
    	push'ed value that has yet to be pop'ed.
    	If (IsEmpty) the return value is false, o.w. true.
    Preconditions: none.
    Postconditions: none.
    --------------------------------------------------------------*/
    bool Top (sType &value) const;

    /*--------------------------------------------------------------
    IsEmpty is a predicate function that indicates whether
    	the stack is empty or not.  (if (numOfStackEntries == 0)
	then return true, o.w. false.
    Preconditions: none.
    Postconditions: none.
    --------------------------------------------------------------*/
    bool IsEmpty () const;

    /*--------------------------------------------------------------
    numOfStackEntries is a constant member function that returns
    	the number of values currently stored in the stack.
    Preconditions: none.
    Postconditions: none.
    --------------------------------------------------------------*/
    int NumOfStackEntries () const;

    // Friendly Methods
    /*--------------------------------------------------------------
    Overloaded output method.  This method prints out on the
    	console the values currently being stored in the specified
    	stack.
    Preconditions: none.
    Postconditions: none.
    --------------------------------------------------------------*/
    friend ostream& operator << (ostream& outs, const Stack& target);


  private:
    // Object instance data
    StackNode *head;
    int stackSize;

    // Helper Functions
    void DeleteStack ();
};

#endif
