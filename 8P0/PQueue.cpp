template< class T, int MAX_SIZE >
PQueue< T, MAX_SIZE >::PQueue():_size(0){
}

// construct a heap from an array of elements;
template< class T, int MAX_SIZE >
PQueue<T, MAX_SIZE>::PQueue( T * items, int size ){
    _size = size;
    if(_size > MAX_SIZE )
        _size = MAX_SIZE;
    for (int i = 0; i < _size; i++)
        _array[ i + 1 ] = items[ i ];
    buildHeap();
}

// insert an item; duplicates are allowed.
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::insert(T e){
	if( _size == 100 ){
		return;
	}
	_size++;

	_array[ _size ] = e;
	moveUp();
}

// return the smallest item from the queue
template< class T, int MAX_SIZE >
T PQueue< T, MAX_SIZE >::findMin(){
	return _array[1];
}

// remove the smallest item from the queue
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::deleteMin(){
	if( _size == 0 ){
		return;
	}

	_array[1] = _array[_size];
	_size--;

	if( _size > 1 ){
		moveDown( 1 );
	}
}

// test if the priority queue is logically empty
template< class T, int MAX_SIZE >
bool PQueue< T, MAX_SIZE >::isEmpty(){
	if( _size == 0 )
		return true;

	return false;
}

// return queue size
template< class T, int MAX_SIZE >
int PQueue< T, MAX_SIZE >::size(){
	return _size;
}

// linear heap construction
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::buildHeap(){
   int temp = _size / 2;
   while ( temp > 0 ) {
	   moveDown( temp );
	   temp--;
   }
}

// move down element at given index
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::moveDown(int x){
	while ( x <= _size / 2 ) {
	   if( *_array[ x ] <= *_array[ 2 * x ] &&
		  ( 2 * x + 1 > _size ||*_array[ x ] <= *_array[ 2 * x + 1 ] ) )
		   break;
	   else if( *_array[ x ] > *_array[ 2 * x ] &&
			   ( 2 * x + 1 > _size ||*_array[ 2 * x ] <= *_array[ 2 * x + 1 ] ) )
	   {
		   T temp = _array[ 2 * x ];
		   _array[ 2 * x ] = _array[ x ];
		   _array[ x ] = temp;
		   x *= 2;
	   }
	   else if( *_array[ x ] > *_array[ 2 * x + 1 ] &&
			   2 * x + 1 <= _size &&
			   *_array[ 2 * x ] > *_array[ 2 * x + 1 ] )
	   {
		   T temp = _array[ 2 * x + 1 ];
		   _array[ 2 * x + 1 ] = _array[ x ];
		   _array[ x ] = temp;
		   x = 2 * x + 1;
	   }
   }
}

// move up the last element in the heap array
template< class T, int MAX_SIZE >
void PQueue< T, MAX_SIZE >::moveUp()
{
	int x = _size;
       while ( x / 2 > 0 ) {
           if( * _array[ x / 2 ] > * _array[ x ] ){
               T temp = _array[ x ];
               _array[ x ] = _array[ x / 2 ];
               _array[ x / 2 ] = temp;
               x /= 2;
           }
           else
               break;
       }
}
