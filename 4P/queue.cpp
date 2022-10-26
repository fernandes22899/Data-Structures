#include "queue.h"
using namespace std;

/*CS515 Assignment 4
File: queue.cpp
Section: 01
Collaboration: cplusplus.com
*/

// constructor with default capacity value
queue::queue( int size ){
  _size = -1;
  _front = 0;
  _capacity = size;

  _arr = new TYPE[_capacity];
}

// copy constructor
queue::queue( const queue& a ){
  _capacity = a._capacity;
  _front = a._front;
  _size = a._size;

  _arr = new TYPE[_capacity];

  for( int i = 0; i < _capacity; i++ )
    _arr[i] = a._arr[i];
}

// assignment operator
queue& queue::operator=( const queue& a ){
  if( &a == this )
    return *this;

  _size = a._size;
  _capacity = a._capacity;
  _front = a._front;

  delete [] _arr;
  _arr = new TYPE[_capacity];

  for( int i = 0; i < _capacity; i++ )
    _arr[i] = a._arr[i];

  return *this;
}

// destructor
queue::~queue(){
  delete [] _arr;
}

// add an element to the end of queue (expand if necessary)
void queue::enqueue( int en ){
  if( size() + 1 > _capacity ){
    int *tempArr = _arr;
    int tempCap = _capacity;
    _capacity = _capacity * 2;

    _arr = new TYPE[_capacity];

    for( int i = 0; i < tempCap; i++ )
      _arr[i] = tempArr[i];

    delete [] tempArr;
  }
  _arr[++_size % _capacity] = en;
}

// remove an element from the front of queue
TYPE queue::dequeue(){
  if( _front > _size )
    throw EmptyQueueException();

  return _arr[_front++ % _capacity];
}

// access the element at queue front; does not remove the element
TYPE& queue::front(){
  return _arr[_front % _capacity];
}

// return true if the queue is empty, false otherwise
bool queue::empty(){
  if( _size < _front )
    return true;

  return false;
}

// return the number of elements currently in the queue
int queue::size(){
  if( _size < _front )
    return 0;

  return _size - _front + 1;
}

// return the current capacity of the queue
int queue::capacity(){
  return _capacity;
}

// output queue elements from queue front to queue end
// elements are separated with a white space.
void queue::dump(ostream &os){
  for( int i = _front; i <= _size; i++ )
    os << _arr[i % _capacity] << " ";

  os << endl;
}
