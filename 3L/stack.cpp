#include "stack.h"
#include <iostream>

using namespace std;


stack::stack(int size){
  _tos = -1;
  if (size == 0){
    _capacity = INITCAP;
    _arr = new TYPE[_capacity];
  }
  else{
    _capacity = size;
    _arr = new TYPE[_capacity];
  }
}

stack::stack( const stack& a ):_capacity(a._capacity),_tos(a._tos)
{
  _arr = new TYPE[_capacity];
  for (int i = 0; i < _capacity; i++){
    _arr[i]=a._arr[i];
  }
}

stack& stack::operator=( const stack& a ){
  if (this == &a){
    return *this;
  }
  delete []_arr;
  _capacity = a._capacity;
  _tos = a._tos;
  if (_capacity > 0){
    _arr = new TYPE[_capacity];

    for (int i = 0; i < _capacity; i++){
      _arr[i] = a._arr[i];
    }
    return *this;
  }
}

stack::stack(stack&& s){
  _capacity = s.size();
  _tos = s._tos;
  s._tos = 0;
  s._capacity = 0;

  /*
  int i = 0;
  Vector ans( s.size() );
  for( auto value : s )
    ans.setAtIndex( i++, value * value );

  return answer;
  */
}

stack& stack::operator=(stack&& s){
  if( this == &s )
    return *this;
  delete []_arr;
  _capacity = s.size();
  _tos = s._tos;
  //_arr = s._tos;
  s._tos = 0;
  s._capacity = 0;
}

stack::~stack(){
 delete []_arr;
}

void stack::push(const TYPE x){
  if (_tos + 1 == _capacity)
    throw FullStackException();
 else
    _arr[++_tos]=x;
}

void stack::pop(){
  if (_tos<0)
    throw EmptyStackException();
  else
 _tos--;
}

TYPE& stack::top(){
  if (_tos == -1)
    throw EmptyStackException();

  return _arr[_tos];
}


bool stack::empty(){
  if(_tos<0)
    return true;
  else
    return false;
}

int stack::size(){
  return (_tos + 1); //size
}

int stack::capacity(){
  return _capacity;
}
