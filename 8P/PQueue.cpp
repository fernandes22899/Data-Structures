#include "PQueue.h"


template<class T, int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue()
{
  _size = 0;
}

template<class T,int MAX_SIZE>
bool PQueue<T, MAX_SIZE>::isEmpty(){
  return _size == 0;
}

template<class T,int MAX_SIZE>
int PQueue<T,MAX_SIZE>::size(){
  return _size;
}

template<class T,int MAX_SIZE>
void PQueue<T, MAX_SIZE>::buildHeap(){
  for( int i = _size/2; i > 0; i-- )
    moveDown(i);
}

template<class T,int MAX_SIZE>
PQueue<T, MAX_SIZE>::PQueue( T* ts, int sz )
{
  _array[0] = 0;
  for( int i = 1; i <= sz; i++)
    _array[i] = ts[i-1];

  _size = sz;
  buildHeap();
}

template<class T,int MAX_SIZE>
void PQueue<T,MAX_SIZE>::insert(T ts){
  _size++;
  _array[_size] = ts;
  moveUp();
}

template<class T,int MAX_SIZE>
T PQueue<T, MAX_SIZE>::findMin(){
  return _array[1];
}

template<class T,int MAX_SIZE>
void PQueue<T, MAX_SIZE>::deleteMin(){
  if( _size >= 0){
    int i = _array[1];
    _array[1] = _array[_size];
    _size--;
    moveDown(1);
  }
}

template<class T,int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveDown(int dw){
  int x = dw*2;
  int y = dw*2+1;
  int z;
  if( x <= _size && _array[x] < _array[dw] )
    z = x;
  else
    z = dw;

  if( y <= _size && _array[y] < _array[z] )
    z=y;
  if( z != dw ){
    int i = _array[z];
    _array[z] = _array[dw];
    _array[dw] = i;
    moveDown(z);
  }
}

template<class T,int MAX_SIZE>
void PQueue<T, MAX_SIZE>::moveUp(){
  int que = _size;
  while( que > 1 && _array[que] < _array[que/2] ){
    int i = _array[que];
    _array[que] = _array[(que)/2];
    _array[(que)/2] = i;
    que = (que)/2;
 }
}
