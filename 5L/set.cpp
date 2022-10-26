#include "set.h"
#include <iostream>

//constructor
Set::Set(){
  _head = new Elem;
  _head->prev = NULL;
  _tail = new Elem;
  _tail->next = NULL;
  _head->next = _tail;
  _tail->prev = _head;
  _size = 0;
}

// copy constructor (you can call copyCode method)
Set::Set( const Set &rhs ){
  Elem *no;
  Elem *noPtr;
  Elem *pos;

  if( !rhs._head )
    _head = NULL;
  else{
     _head = new Elem;
     _tail = new Elem;
     noPtr = rhs._head;
     pos = _head;
  }

  while( noPtr->next != rhs._tail ){
      noPtr = noPtr -> next;
      no = new Elem;
      no -> info = noPtr -> info;
      pos -> next = no;
      pos = pos -> next;
  }
  pos -> next=_tail;
  _tail -> prev = pos;
  _size = rhs._size;
}

// destructor (you can call destructCode method)
Set::~Set(){
  destructCode();
}

//destructCode clears the list and deletes stored values
void Set::destructCode(){
  clear();
  delete _head;
  delete _tail;
  /*
  Elem *n = _head;
  while(n){
    n = n->next;
    delete _head;
    _head = n;
  }

  Elem *r = _tail;
  while(r){
    r = r->next;
    delete _tail;
    _tail = r;
  }
  */
}

// assignment operator (you can call destructCode and copyCode methods)
Set& Set::operator=( const Set &rhs ){
   if( &rhs != this ){
     clear();
     Elem *temp;
     temp = rhs._head->next;
     while( temp != rhs._tail ){
	      insert( temp->info );
	       temp = temp->next;
     }
     _size = rhs._size;
   }
}

// insert an int into the set;
void Set::insert( ELEMENT_TYPE rhs ){
  if( find(rhs) )
      return;

   Elem *tmp = _tail->prev;
   Elem *str1 = new Elem;
   str1 -> info = rhs;

   if( _head->next == _tail ){
     _head->next = str1;
     str1->prev = _head;
     _tail->prev = str1;
     str1->next = _tail;
   }
   else{
      while((tmp -> next != _tail) && (tmp->info < str1->info))														      {
        tmp = tmp -> next;
   }
      str1->next = tmp;
      str1->prev = tmp->prev;
      tmp->prev->next = str1;
      tmp->prev = str1;
   }
   _size++;
}

// remove an int from the set;
void Set::erase( ELEMENT_TYPE rhs ){
  if( !find(rhs) )
    {
       return;
    }
    Elem* tmp = _head->next;
    while(tmp != _tail)
    {
       if( tmp->info == rhs )
       {
	  tmp -> prev -> next = tmp -> next;
	  tmp -> next -> prev = tmp -> prev;
	  _size--;
	  delete tmp;
       }
       tmp = tmp->next;
    }
}

// remove all elements from set
void Set::clear(){
   Elem *cur;
   Elem *next;
   cur = _head->next;
   while( cur != _tail )
   {
     next = cur->next;
     delete cur;
     cur = next;
   }
   _head->next = _tail;
   _tail->prev = _head;
   _size = 0;
}

// return size of the set
int Set::size() const{
  return _size;
}

// return true if an element is found; false otherwise
bool Set::find(ELEMENT_TYPE rhs) const{
    Elem* tmp = _head->next;
    while( tmp != _tail){
      if( tmp -> info != rhs )
	       tmp = tmp->next;
      else if( tmp->info == rhs )
	       return true;
    }
    return false;
}

bool operator==(const Set& s1, const Set& s2)
{
   if((s1.size() == s2.size()) && (s1._head->info == s2._head->info))
	  return true;
   else
	    return false;
}

ostream& operator<< (ostream& os, const Set& s)
{
   s.dump( os, s);
}

ostream& Set::dump(ostream& out, const Set &cur)const
{
   Elem *hold = cur._head;

   while( hold != _tail ){
      hold = hold->next;
      out << hold->info << " ";
   }
   return out;
}

void Set::copyCode( const Set & v )
{
   Elem *newl;
   Elem *noOn;
   Elem *cur;
   Elem *temp;

   _head = new Elem;
   _head->prev = NULL;

   _tail = new Elem;
   _tail->next = NULL;

   _head->next = _tail;
   _tail->prev = _head;
   _size = 0;

   _head->info = v._head->info;
   _size = v._size;
   noOn = v._head;
   cur = _head;

   while( noOn->next != _tail )
   {
    noOn = noOn->next;
    newl = new Elem;
    newl->info = noOn->info;
    newl->prev = cur;
    cur->next->prev = newl;
    newl->next = cur->next;
    cur->next = newl;
    }
}
