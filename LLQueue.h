#ifndef _LLQueue_H
#define _LLQueue_H

/*------------------------------------------------------------------
A standard linked-list implementation of a queue class.
Written by Matt Sweeterman
------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

// Definition of what the queue can store.
typedef string sType;

// Definition of a queue node.
struct QueueNode {
    sType value;
    QueueNode * next;
};

class Queue {
  public:
    // Constructors & destructors
    /*--------------------------------------------------------------
    The default queue constructor provides an empty queue
    (IsEmpty == TRUE).
    --------------------------------------------------------------*/
    Queue ();

    /*--------------------------------------------------------------
    The default queue destructor: deallocates all dynamically
    	allocated memory (i.e. QueueNodes).
    --------------------------------------------------------------*/
    ~Queue ();

    // Modification Methods
    /*--------------------------------------------------------------
    The Enqueue method adds a value (value) to the queue.
    Precondition: none.
    Postcondition: size++ (IsEmpty == false)
    --------------------------------------------------------------*/
    void Enqueue (sType value);

    /*--------------------------------------------------------------
    The Dequeue method removes the value (value) that has been in the queue the
    longest
    Precondition: none.
    Postcondition: size--;
    --------------------------------------------------------------*/
    bool Dequeue (sType &value);


    // Constant Methods
    /*--------------------------------------------------------------
    The next method returns the value that were to be returned if
    Dequeue were called except next doesn't change the state of the
    queue.
    Preconditions: none.
    Postconditions: none.
    --------------------------------------------------------------*/
    bool First (sType &value) const;

    /*--------------------------------------------------------------
    IsEmpty indicates whether the queue is empty or not.
    (if (IsEmpty == 0)
	 then return true, o.w. false.
    Preconditions: none.
    Postconditions: none.
    --------------------------------------------------------------*/
    bool IsEmpty () const;

    /*--------------------------------------------------------------
    QueueSize is a function that returns the number of values
    currently stored in the queue.
    Preconditions: none.
    Postconditions: none.
    --------------------------------------------------------------*/
    int QueueSize () const;

  private:
    // Object instance data
    QueueNode * tail;
    int queueSize;

    // Helper Functions
    void DeleteQueue ();
};

#endif
