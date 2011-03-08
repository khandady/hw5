#ifndef LISTNODE_H
#define LISTNODE_H

template< typename NODETYPE > class LinkedList;                            

template< typename NODETYPE >
class ListNode 
{
   friend class LinkedList< NODETYPE >;    // make List a friend

public:
   ListNode( const NODETYPE & );     
   NODETYPE getData() const; 

private:
   NODETYPE data;                    // data
   ListNode< NODETYPE > *nextPtr;    // next node in list
}; 

template< typename NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
   : data( info ), nextPtr( 0 ) 
{ 
   // empty body
} 

// return copy of data in node
template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const 
{ 
   return data; 
} 

#endif
