#include "PQueue0.h"
#include <cstdlib>

PQueue::PQueue(){
 _size = 0;
}

PQueue::PQueue( int* its, int sz ){
  _array[0] = 0;
  for( int i = 1; i <= sz; i++)
    _array[i] = its[i-1];

  _size = sz;
  buildHeap();
}

void PQueue::insert( T ts ){
  _size++;
  _array[_size] = ts;
  moveUp();
}

T PQueue::findMin(){
  return _array[1];
}

void PQueue::deleteMin(){
  if( _size >= 0 ){
  int it = _array[1];
  _array[1] = _array[_size];
  _size--;
  moveDown(1);}
}

bool PQueue::isEmpty(){
  return _size == 0;
}

int PQueue::size(){
  return _size;
}

void PQueue::buildHeap(){
  for( int i = _size/2; i > 0; i-- )
    moveDown(i);
}

void PQueue::moveDown( int dw ){
  int x = dw*2;
  int y = dw*2+1;
  int z;

  if( x <= _size && _array[x] < _array[dw])
    z = x;
  else
    z = dw;

  if( y <= _size && _array[y] < _array[z] )
    z = y;
  if( z != dw ){
    int it = _array[z];
    _array[z] = _array[dw];
    _array[dw] = it;
    moveDown(z);
  }
}

void PQueue::moveUp(){
  int pos = _size;
  while( pos>1 && _array[pos] < _array[pos/2] ){
  int it = _array[pos];
  _array[pos] = _array[(pos)/2];
  _array[(pos)/2] = it;
  pos = (pos)/2;
 }
}
