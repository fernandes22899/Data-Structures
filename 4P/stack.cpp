#include "stack.h"
using namespace std;

/*CS515 Assignment 4
File: stack.cpp
Section: 01
Collaboration: cplusplus.com
*/

// constructor with default capacity value
stack::stack( int size ){
  _arr = new TYPE[size];
  _capacity = size;
  _tos = -1;

  for( int i = 0; i < size; i++ )
    _arr[i] = 0;
}

// copy constructor
stack::stack( const stack& a )
:_capacity(a._capacity), _tos(a._tos){
  _arr = new TYPE[_capacity];
  for( int i = 0; i < _capacity; i++ )
    _arr[i] = a._arr[i];
}

// assignment operator
stack& stack::operator=( const stack& a ){
  _capacity = a._capacity;
  _tos = a._tos;

  delete [] _arr;
  _arr = new TYPE[_capacity];
  for( int i = 0; i < _capacity; i++ )
    _arr[i] = a._arr[i];

  return *this;
}

// destructor
stack::~stack(){
  delete []_arr; //delete for no memory leaks
}

// push an element, expanding if necessary;
void stack::push( const TYPE a ){
  if( _tos + 1 < _capacity )
    _arr[++_tos] = a;
 else{
   int *tempArr = _arr;
   int tempCap = _capacity;

   _capacity = _capacity * 2;
   _arr = new int[_capacity];

   for( int i = 0; i < tempCap; i++ )
    _arr[i] = tempArr[i];

   delete [] tempArr;
   _arr[++_tos] = a;
 }
}

// remove and element; throw EmptyStackException when stack is empty
void stack::pop(){
  if( empty() )
    throw EmptyStackException();
  else
    _tos--;
}

// return a reference to the top element without popping;
//throw EmptyStackException when stack is empty
TYPE& stack::top(){
  if( _tos < 0 ) //if tos is -1 then there is no top since -1 means there's nothing
    throw EmptyStackException();

  return _arr[_tos];
}

// return true if the stack is empty, false otherwise
bool stack::empty(){
  if( _tos < 0 ) //if top of stack is -1 then it's empty
    return true;
  else
    return false;
}

// return the number of elements currently on the stack
int stack::size(){
  return _tos + 1; //gets top of stack index and adds 1 for size
}

// return the current capacity of the stack
int stack::capacity(){
  return _capacity; //returns capacity
}

// output stack elements from stack top to stack bottom
// elements are separated with a white space.
void stack::dump(ostream &os){
  for( int i = _tos; i > -1; i-- ) //prints out all values to ostream
    os << _arr[i] << " ";

  os << endl;
}
