#ifndef VECTORLIST_H
#define VECTORLIST_H

#include <iostream>
#include <vector>
using namespace std;

template< typename NODETYPE >
class VectorList 
{
 public:
  VectorList(); // constructor
  ~VectorList(); // destructor

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
  bool shared(const VectorList< NODETYPE > &l2); 

  // Apply the function func to each element in the linked list
  void map(NODETYPE func(const NODETYPE &, const NODETYPE &)); 

  // Keep only those nodes n where predicate(n) = true 
  void filter(bool predicate(const NODETYPE &)); 

  // Remove all duplicates from the list 
  void removeDup(); 

  //
  /////////////////////////////////////////////////////////

 private:
  vector< NODETYPE > *vList;  // list data as a vector
}; 


template< typename NODETYPE > 
VectorList< NODETYPE >::VectorList()  
//:  // Fill in the missing code 
{  
  // empty body 
}  

template< typename NODETYPE > 
VectorList< NODETYPE >::~VectorList() 
{ 
  // Fill in the missing code 


}  

// insert node at front of list
template< typename NODETYPE >
void VectorList< NODETYPE >::insertAtFront( const NODETYPE &value )
{
  // Fill in the missing code 

} 

// insert node at back of list
template< typename NODETYPE >
void VectorList< NODETYPE >::insertAtBack( const NODETYPE &value )
{
  // Fill in the missing code 

} 

// delete node from front of list
template< typename NODETYPE >
bool VectorList< NODETYPE >::removeFromFront( NODETYPE &value )
{
  // Fill in the missing code 

} 

// delete node from back of list
template< typename NODETYPE >
bool VectorList< NODETYPE >::removeFromBack( NODETYPE &value )
{
  // Fill in the missing code 

} 

// is VectorList empty?
template< typename NODETYPE > 
bool VectorList< NODETYPE >::isEmpty() const 
{ 
  // Fill in the missing code 

} 

// display contents of VectorList
template< typename NODETYPE >
void VectorList< NODETYPE >::print() const
{
  // Fill in the missing code 

} 

#endif
