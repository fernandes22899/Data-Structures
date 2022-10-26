#include "set.h"
#include <iostream>
#include <string>
using namespace std;


//Constructor
Set::Set(){
  _head = new Elem;
  _head->prev = NULL;
  _tail = new Elem;
  _tail->next = NULL;
  _head->next = _tail;
  _tail->prev = _head;

  _size = 0;
}

//Destructor
Set::~Set(){
  clear();
  delete _head;
  delete _tail;
}

//Copy Constructor
Set::Set( const Set &rhs ){
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

  _head->info = rhs._head->info;
  _size = rhs._size;
  noOn = rhs._head;
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

//Inserting an element into the stack
void Set::insert( ELEMENT_TYPE rhs ){
  if( find(rhs) != end() )
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
      while((tmp -> next != _tail) && (tmp->info < str1->info)){
        tmp = tmp -> next;
   }
      str1->next = tmp;
      str1->prev = tmp->prev;
      tmp->prev->next = str1;
      tmp->prev = str1;
   }
   _size++;
}

//Erasing the elements in the set
void Set::erase( ELEMENT_TYPE rhs ){
  if( find(rhs) == end() )
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

//Clearing the set
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

//Size of list
int Set::size() const{
  return _size;
}

void Set::copyCode(const Set & v){
  Set::Iterator it;
  for(it = v.begin(); it!=v.end(); it++){
    insert(*it);
  }
  _size = v._size;
}

Set& Set::operator=(const Set &rhs){ // assignment operator
  if(&rhs!=this)
  {
    clear();
    copyCode(rhs);
  }
  return *this;
}

//---------Iterator-------------------------------------
Set::Iterator::Iterator(){
  _cur = NULL;
}

Set::Iterator::Iterator( Elem *cur ){
  _cur = cur;
}

//-----Overloaded Operators------------
ELEMENT_TYPE& Set::Iterator::operator*(){
  return _cur->info;
}
Set::Iterator Set::Iterator::operator++(int){
  _cur = _cur->next;
  return *this;
}
Set::Iterator Set::Iterator::operator--(int){
  _cur = _cur->prev;
  return *this;
}
bool Set::Iterator::operator==(Iterator it) const{
  return _cur == it._cur;
}
bool Set::Iterator::operator!=(Iterator it) const{
  return _cur != it._cur;
}
//----------------------------------------

//Finding somthing through the iteration
Set::Iterator Set::find( ELEMENT_TYPE rhs ) const{
  Set::Iterator it = begin();

  while( it != end() ){
    if( *it == rhs )
      return it;
    it++;
  }
  return it;
}

//Beginning Iteration through a set
Set::Iterator Set::begin() const{
  Iterator it(_head->next);
  return it;
}

//Ending iteration through a set
Set::Iterator Set::end() const{
  Iterator it(_tail->prev);
  return it;
}
//--------------------------------------------------------

ostream& operator<< (ostream &out, Set &set){
  return set.dump(out, set);
}

//-------Reverse Iterator-----------------------------
Set::Reverse_Iterator::Reverse_Iterator(){
  _cur = NULL;
}

Set::Reverse_Iterator::Reverse_Iterator( Elem *cur ){
  _cur = cur;
}

ELEMENT_TYPE& Set::Reverse_Iterator::operator*(){
  return _cur->info;
}
Set::Reverse_Iterator Set::Reverse_Iterator::operator++(int){
  _cur = _cur->prev;
  Reverse_Iterator it(_cur);
  return it;
}
Set::Reverse_Iterator Set::Reverse_Iterator::operator--(int){
  _cur=_cur->next;
  Reverse_Iterator it(_cur);
  return it;
}
bool Set::Reverse_Iterator::operator==(Reverse_Iterator it) const{
  return _cur == it._cur;
}
bool Set::Reverse_Iterator::operator!=(Reverse_Iterator it) const{
  return _cur != it._cur;
}

Set::Reverse_Iterator Set::rbegin() const{
  Reverse_Iterator it(_tail->prev);
  return it;
}

Set::Reverse_Iterator Set::rend() const{
  Reverse_Iterator it(_head->next);
  return it;
}
//--------------------------------------------------------------------

Set operator-(const Set& foo, const Set& bar){
  /*
  Set difference;
  Set::Iterator itdifference = difference.begin(); //PROBABLY ONLY NEED THE ONE DOWN BELOW
  Set::Iterator itfoo = foo.begin(); //create iterator for foo set
  Set::Iterator itbar = bar.begin(); //create iterator for bar set
  while(itfoo != foo.end()){ //loop through entire set
    difference.insert(itfoo); //insert the value into the output set
    itfoo++; //increment iterator for foo set
  }
  auto itdifference = difference.begin();
  while(itdifference != difference.end()){ //loop through entire set
    if(itdifference == itbar){
      difference.erase(itdifference); //if the values in both sets are equal erase the value from the output set
    }
    itdifference++; //increment iterator for diff set
    itbar++; //increment iterator for bar set
  }
  return difference; //return set with difference of values
  */
}

bool operator==(const Set& s1, const Set& s2){
  Set::Iterator its1 = s1.begin(); //create iterator for foo set
  Set::Iterator its2 = s2.begin(); //create iterator for bar set
  while(its1 != s1.end()){ //loop through entire set
    if(*its1 != *its2){
      return false;
    }
    its1++; //increment iterator for foo set
    its2++; //increment iterator for bar set
  }
  return true; //return set with intersection of values
}

//Return a set of numbers that are the same in both
Set operator|(const Set& s1, const Set& s2){

}
//Union return set that have combined numbers of two sets but with no repeats
Set operator&(const Set& s1, const Set& s2){

}

ostream& Set::dump(ostream& out, const Set &v){
  Set::Iterator it;
  for(it = v.begin(); it != v.end(); it++){
    out << *it << " ";
  }
  return out;
}
