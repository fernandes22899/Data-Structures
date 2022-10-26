#include "queue.h"
#include <iostream>

using namespace std;
// singly linked list implementation of queue
// empty queue is represented by null front and rear pointers

queue::queue(){
  _front = NULL;
  _rear = NULL;
  _size = 0;
}

queue::~queue(){
  node *n = _front;
  while(n){
    n = _front->next;
    delete _front;
    _front = n;
  }
}

// copy constructor
queue::queue(const queue &v):_front(v._front),_rear(v._rear){
  _front = NULL;
  _rear = NULL;
  _size = 0;

  node *n;
  n = v._front;
  int in;

  while(n){
    in = n->list;
    n = n->next;
    enqueue(in);
  }

}

// assignment operator
queue& queue::operator=(const queue &rhs){
  if( this != &rhs ){
    node *n = _front;
    while( n != 0 ){
      _front = _front->next;
      delete n;
      n = _front;
    }

    _front = NULL;
    _rear = NULL;
    _size = 0;

    node *ne = rhs._front;
    while( ne != rhs._rear->next ){
      enqueue(ne->list);
      ne = ne->next;
    }
  }
  return *this;
}

void queue::enqueue(const TYPE data){
  node *n = new node(data);
  n->list = data;
  n->next = NULL;
  //cout << "yo" << endl;
  if( empty() ){
    _front = n;
    //_rear = n;
    _front->next = NULL;
    //cout << "yo2" << endl;
  }
  else{
    _rear->next = n;
    //_rear = n;
    n->next = NULL;
    //cout << "yo3" << endl;
  }
  _rear = n;
  //cout << "yo out" << endl;
  _size++;
}

TYPE queue::dequeue(){
	TYPE val;
  node *n;
  if( _front == NULL ){
    throw EmptyQueueException();
  }
  else{
    n = _front;
    _front = _front->next;
    val = n->list;
    delete n;
    _size--;

    if( empty() ){
      _front = NULL;
      _rear = NULL;
    }

  }

	return val;
}

void queue::dump(ostream &os){
  node *n = _front;
  while(n){
    cout << n->list << " ";
    n = n->next;
  }
  cout << endl;
}

int queue::size(){
    return _size;
}

bool queue::empty(){
    bool test = false;
    if( _size == 0 )
      test = true;
    return test;
}
