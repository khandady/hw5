#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "ListNode.h"
using namespace std;

template< typename NODETYPE >
class LinkedList 
{
 public:
  LinkedList(); // constructor
  ~LinkedList(); // destructor

  void insertAtFront( const NODETYPE & );
  void insertAtBack( const NODETYPE & );
  bool removeFromFront( NODETYPE & );
  bool removeFromBack( NODETYPE & );
  bool isEmpty() const;
  void print() const;

  /////////////////////////////////////////////////////////
  // new member functions for HW 5

  // overload array access operator 
  NODETYPE &operator[](int index) const;
  
  // sum up all the values in the linked list, 
  // assuming + is overloaded for NODETYPE
  NODETYPE sum() const; 

  // Sort the linked list in ascending order, 
  // assuming NODETYPE supports <, ==, etc.
  void sort(); 

  // In-place reversal of the linked list, i.e., don't create a new list
  // to perform the reversal, and use the list itself
  void reverse();        
  
  // Check whether the current list and the input l2 share any nodes or not 
  bool shared(const LinkedList< NODETYPE > &l2); 

  // Apply the function func to each element in the linked list
  void map(NODETYPE func(const NODETYPE &, NODETYPE const &)); 

  // Keep only those nodes n where predicate(n) = true 
  void filter(bool predicate(const NODETYPE &)); 

  // Remove all duplicates from the list 
  void removeDup(); 
  
  //
  /////////////////////////////////////////////////////////

 private:
  ListNode< NODETYPE > *firstPtr;   // pointer to first node
  ListNode< NODETYPE > *lastPtr;    // pointer to last node

  // utility function to allocate new node
  ListNode< NODETYPE > *getNewNode( const NODETYPE & );
}; 


template< typename NODETYPE >
LinkedList< NODETYPE >::LinkedList() 
: firstPtr( 0 ), lastPtr( 0 ) 
{ 
  // empty body
} 

template< typename NODETYPE >
LinkedList< NODETYPE >::~LinkedList()
{
  if ( !isEmpty() ) // LinkedList is not empty
    {    
      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 ) // delete remaining nodes
	{  
	  tempPtr = currentPtr;
	  cout << tempPtr->data << '\n';
	  currentPtr = currentPtr->nextPtr;
	  delete tempPtr;
	} 
    } 
} 

// insert node at front of list
template< typename NODETYPE >
void LinkedList< NODETYPE >::insertAtFront( const NODETYPE &value )
{
  ListNode< NODETYPE > *newPtr = getNewNode( value ); // new node

  if ( isEmpty() )                 // LinkedList is empty
    firstPtr = lastPtr = newPtr;   // new list has only one node
  else // LinkedList is not empty
    {
      newPtr->nextPtr = firstPtr;  // point new node to previous 1st node
      firstPtr = newPtr;           // aim firstPtr at new node
    } 
} 

// insert node at back of list
template< typename NODETYPE >
void LinkedList< NODETYPE >::insertAtBack( const NODETYPE &value )
{
  // new node
  ListNode< NODETYPE > *newPtr = getNewNode( value ); 

  if ( isEmpty() )                // LinkedList is empty
    firstPtr = lastPtr = newPtr;  // new list has only one node
  else                            // LinkedList is not empty
    {
      lastPtr->nextPtr = newPtr;  // update previous last node
      lastPtr = newPtr;           // new last node
    }
} 

// delete node from front of list
template< typename NODETYPE >
bool LinkedList< NODETYPE >::removeFromFront( NODETYPE &value )
{
  if ( isEmpty() )                // LinkedList is empty
    return false;                 // delete unsuccessful
  else 
    {
      // hold tempPtr to delete
      ListNode< NODETYPE > *tempPtr = firstPtr; 

      if ( firstPtr == lastPtr )
	firstPtr = lastPtr = 0;   // no nodes remain after removal
      else
	firstPtr = firstPtr->nextPtr; // point to previous 2nd node

      value = tempPtr->data;      // return data being removed
      delete tempPtr;             // reclaim previous front node
      return true;                // delete successful
    } 
} 

// delete node from back of list
template< typename NODETYPE >
bool LinkedList< NODETYPE >::removeFromBack( NODETYPE &value )
{
  if ( isEmpty() )                // LinkedList is empty
    return false;                 // delete unsuccessful
  else 
    {
      ListNode< NODETYPE > *tempPtr = lastPtr; // hold tempPtr to delete

      if ( firstPtr == lastPtr )  // LinkedList has one element
	firstPtr = lastPtr = 0;   // no nodes remain after removal
      else 
	{
	  ListNode< NODETYPE > *currentPtr = firstPtr;

	  // locate second-to-last element            
	  while ( currentPtr->nextPtr != lastPtr )    
            currentPtr = currentPtr->nextPtr; // move to next node

	  lastPtr = currentPtr;    // remove last node
	  currentPtr->nextPtr = 0; // this is now the last node
	} 

      value = tempPtr->data;       // return value from old last node
      delete tempPtr;              // reclaim former last node
      return true;                 // delete successful
    }
} 

// is LinkedList empty?
template< typename NODETYPE > 
bool LinkedList< NODETYPE >::isEmpty() const 
{ 
  return firstPtr == 0; 
} 

// return pointer to newly allocated node
template< typename NODETYPE >
ListNode< NODETYPE > *LinkedList< NODETYPE >::getNewNode( const NODETYPE &value )
{
  return new ListNode< NODETYPE >( value );
}

// display contents of LinkedList
template< typename NODETYPE >
void LinkedList< NODETYPE >::print() const
{
  if ( isEmpty() )           // LinkedList is empty
    {
      cout << "The list is empty\n\n";
      return;
    }

  ListNode< NODETYPE > *currentPtr = firstPtr;

  cout << "The list is: ";

  while ( currentPtr != 0 ) // get element data
    {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;
    } 

  cout << "\n\n";
} 

#endif
