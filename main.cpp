#include <iostream>
#include <string>
#include "LinkedList.h"
#include "VectorList.h"
using namespace std;

// display program instructions to user
void instructions()
{
   cout << "Enter one of the following:\n"
      << "  1 to insert at beginning of list\n" 
      << "  2 to insert at end of list\n" 
      << "  3 to delete from beginning of list\n" 
      << "  4 to delete from end of list\n" 
      << "  5 to end list processing\n"
      << "  6 to sum list elements\n"
      << "  7 to access a list element\n"
      << "  8 to reverse list order\n"
      << "  9 to test shared\n";
} 
// function to test map member function
template< typename T >
T timesfive(const T &anum)
{
	return anum * 5;
}
// function to test filter
template< typename T >
bool even(const T &anum)
{
	if ( anum % 2 == 0)
	{return true;}
	else {return false;}
}

// function to test a LinkedList
template< typename T >
void testLinkedList( LinkedList< T > &listObject, const string &typeName )
{
   cout << "Testing a LinkedList of " << typeName << " values\n";
   instructions();       // display instructions

   int choice;           // store user choice
   T value;              // store input value

   do                    // perform user-selected actions
   {
      cout << "? ";
      cin >> choice;

      switch ( choice ) 
      {
         case 1:         // insert at beginning
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtFront( value );
            listObject.print();
            break;
         case 2:         // insert at end
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtBack( value );
            listObject.print();
            break;
         case 3:         // remove from beginning
            if ( listObject.removeFromFront( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 4:          // remove from end
            if ( listObject.removeFromBack( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 6:
	    cout << listObject.sum() << endl;
	    break;
	 case 7:
	    {cout << "Enter element subscript : ";
	    cin >> value;
	    T something = listObject[value];
	    cout << "\nEntry is : " << something << endl;
 	    break;}
	 case 8:
	    listObject.reverse();
            listObject.print();	    
	    break;
      }
   } while ( choice != 5 ); 

   cout << "End list test\n\n";
} 

// function to test a VectorList
template< typename T >
void testVectorList( VectorList< T > &listObject, const string &typeName )
{
   cout << "Testing a VectorList of " << typeName << " values\n";
   instructions();       // display instructions

   int choice;           // store user choice
   T value;              // store input value

   do                    // perform user-selected actions
   {
      cout << "? ";
      cin >> choice;

      switch ( choice ) 
      {
         case 1:         // insert at beginning
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtFront( value );
            listObject.print();
            break;
         case 2:         // insert at end
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtBack( value );
            listObject.print();
            break;
         case 3:         // remove from beginning
            if ( listObject.removeFromFront( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 4:          // remove from end
            if ( listObject.removeFromBack( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
      }
   } while ( choice < 5 ); 

   cout << "End list test\n\n";
} 

int main()
{
   // test LinkedList of int values
   LinkedList< int > integerLinkedList;
   testLinkedList( integerLinkedList, "integer" ); 

   // test VectorList of int values
   VectorList< int > integerVectorList;
   testVectorList( integerVectorList, "integer" ); 

   // test LinkedList of double values
   LinkedList< double > doubleLinkedList;
   testLinkedList( doubleLinkedList, "double" ); 

   // test VectorList of double values
   VectorList< double > doubleVectorList;
   testVectorList( doubleVectorList, "double" ); 
   cout << "testing shared : " << integerLinkedList.shared(integerLinkedList) << endl;
   //int &anum;
   cout << "testing map :\n";  
   integerLinkedList.map(timesfive);
   cout << "testing filter\n";
   integerLinkedList.filter(even);
   integerLinkedList.print();
   return 0;
} 

