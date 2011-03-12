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
  void map(NODETYPE func(const NODETYPE &)); 

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

  // utility function to check list size
  int listsize() const;
}; 

template< typename NODETYPE>
int LinkedList< NODETYPE >::listsize() const
{
	int i = 0;
	ListNode< NODETYPE > *currentPtr = firstPtr;
	while (currentPtr != 0)
	{
		i++;
		currentPtr = currentPtr->nextPtr;
	}
	return i;
}

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

//overload [] to access list elements, broken atm
template< typename NODETYPE >
NODETYPE & LinkedList< NODETYPE >::operator[](int index) const
{
	int size = listsize();
	ListNode< NODETYPE > *currentPtr = firstPtr;
	if (index < size)
	{
		for (int i = 0;i<index;i++)
		{
			currentPtr = currentPtr->nextPtr;
		}
		NODETYPE thing = currentPtr->getData();
		NODETYPE &node = thing;
		return node;
	}
	else
	{
		cout << "list overrange" << endl;
		NODETYPE thing = 0;
		NODETYPE &node = thing;
		return node;
	}
}

//sum list elements
template< typename NODETYPE >
NODETYPE LinkedList< NODETYPE >::sum() const
{
	if ( isEmpty() )
	{
		cout << "The list is empty\n\n";
	}

	ListNode< NODETYPE > *currentPtr = firstPtr;

	cout << "Sum of elements is: ";
	NODETYPE total = 0;
	while ( currentPtr != 0 )
	{
		total += currentPtr->getData();
		currentPtr = currentPtr->nextPtr;
	}
	return total;
}

/*template< typename NODETYPE >
void LinkedList< NODETYPE >::sort()
{*/

template< typename NODETYPE >
void LinkedList< NODETYPE >::reverse()
{
	unsigned int size= listsize();
	/*ListNode< NODETYPE > *currentPtr = firstPtr;
	while (currentPtr != lastPtr)
	{
		size++;
		currentPtr = currentPtr->nextPtr;
	}*/
	ListNode< NODETYPE > *currentPtr = 0;
	if (size == 2)
	{
		ListNode< NODETYPE > *currentPtr = firstPtr;
		firstPtr = lastPtr;
		firstPtr->nextPtr = currentPtr;
		currentPtr->nextPtr = 0;
	}	
	else if (size > 2)
	{
		currentPtr = firstPtr;
		ListNode< NODETYPE > *prevPtr = currentPtr;
		ListNode< NODETYPE > *storePtr = currentPtr->nextPtr;
		currentPtr->nextPtr = 0;
		currentPtr = storePtr;
		while (currentPtr != lastPtr)
		{
			storePtr = currentPtr->nextPtr;
			currentPtr->nextPtr = prevPtr;
			prevPtr = currentPtr;
			currentPtr = storePtr;
			if (currentPtr == lastPtr)
			{
				currentPtr->nextPtr = prevPtr;
			}
		}
		storePtr = lastPtr;
		lastPtr = firstPtr;
		firstPtr = storePtr;
	}
	else { cout << "List has one or fewer elements" << endl; }
}

template< typename NODETYPE >
bool LinkedList< NODETYPE >::shared(const LinkedList< NODETYPE > &l2)
{
	if ( !l2.isEmpty() )
	{
		ListNode< NODETYPE > *currentPtr = firstPtr;
		ListNode< NODETYPE > *otherPtr = l2.firstPtr;
		while (currentPtr != 0)
		{
			while(otherPtr != 0)
			{
				if (currentPtr == otherPtr)
				{
					return true;
				}
				otherPtr = otherPtr->nextPtr;
			}
			currentPtr = currentPtr->nextPtr;
		}
		return false;
	}
	else {return false;}
}

template< typename NODETYPE >
void LinkedList< NODETYPE >::map(NODETYPE func(const NODETYPE &))
{
	ListNode< NODETYPE > *currentPtr = firstPtr;
	while( currentPtr != 0)
	{
		currentPtr->data = func(currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
	print();
}

template< typename NODETYPE >
void LinkedList< NODETYPE >::filter(bool predicate(const NODETYPE &))
{
	if (!isEmpty()){
	ListNode< NODETYPE > *prevPtr = firstPtr;
	ListNode< NODETYPE > *currentPtr = firstPtr;
	while (currentPtr != 0 )
	{
		if ( isEmpty() )
		{
			cout << "no matching nodes, list empty\n";
			break;
		}
		if (predicate(currentPtr->getData()) == true)
		{
			prevPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		else if (currentPtr == firstPtr)
		{
			prevPtr = firstPtr->nextPtr;
			firstPtr = prevPtr;
			delete currentPtr;
			currentPtr = prevPtr;
		}
		else
		{
			ListNode<NODETYPE>*tempPtr = currentPtr;
			prevPtr->nextPtr = currentPtr->nextPtr;
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
	}}
}}
#endif
