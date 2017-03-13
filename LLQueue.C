/*------------------------------------------------------------------
A standard linked-list implementation of a queue class.
   Written by Matt Sweeterman
------------------------------------------------------------------*/
#include"LLQueue.h"
#include <iostream>


// ************************** Public Functions *********************
// Constructors & destructors
/*--------------------------------------------------------------
The default queue constructor provides an empty queue
(IsEmpty == TRUE).
--------------------------------------------------------------*/
Queue::Queue () {
   tail = NULL;
   queueSize = 0;
}

/*--------------------------------------------------------------
The default queue destructor: deallocates all dynamically
  allocated memory (i.e. QueueNodes).
--------------------------------------------------------------*/
Queue::~Queue () {
   DeleteQueue ();
}

// Mutator Methods
/*--------------------------------------------------------------
The Enqueue method adds a value (value) to the queue.
Precondition: none.
Postcondition: size++ (IsEmpty == false)
--------------------------------------------------------------*/
void Queue::Enqueue (sType value) {
    QueueNode * temp = new QueueNode;
    temp -> value = value;

    if(tail == NULL){
      temp -> next = temp;
    }
   else{
    temp->next = tail->next;
    tail->next = temp;
    }
    tail = temp;
    queueSize++;

}

/*--------------------------------------------------------------
The Dequeue method removes the value (value) that has been in the queue the
longest
Precondition: none.
Postcondition: size--;
--------------------------------------------------------------*/
bool Queue::Dequeue (sType &value) {
    bool retValue = false;

    if (tail != NULL) {
      retValue = true;
      queueSize--;
      QueueNode * old = tail->next;
      value = old->value;
      tail->next = old->next;
      delete old;
      if(queueSize == 0){
         tail = NULL;
      }
   }
    return (retValue);
}

// Accessor Methods
/*--------------------------------------------------------------
The next method returns the value that were to be returned if
Dequeue were called except next doesn't change the state of the
queue.
Preconditions: none.
Postconditions: none.
--------------------------------------------------------------*/
bool Queue::First (sType &value) const {
    bool retValue = false;
    if (tail != NULL) {
		retValue = true;
		value = tail->next->value;
    }
    return (retValue);
}

/*--------------------------------------------------------------
IsEmpty indicates whether the queue is empty or not.
(if (IsEmpty == 0)
then return true, o.w. false.
Preconditions: none.
Postconditions: none.
--------------------------------------------------------------*/
bool Queue::IsEmpty () const {
    return (tail->next == NULL);
}

/*--------------------------------------------------------------
QueueSize is a function that returns the number of values
currently stored in the queue.
Preconditions: none.
Postconditions: none.
--------------------------------------------------------------*/
int Queue::QueueSize () const {

    return (queueSize);
}

// ************************** Private Functions *********************
/*------------------------------------------------------------------
DeleteQueue deallocates all the nodes associated with "this" queue.
Preconditions: none.
Postconditions: QueueSize = 0, tail->next = NULL
------------------------------------------------------------------*/
void Queue::DeleteQueue () {
    QueueNode * temp;
    while (queueSize > 0) {
        temp = tail->next;
        tail->next = temp->next;
        delete temp;
        queueSize--;
    }
    queueSize = 0;
    tail = NULL;
};
