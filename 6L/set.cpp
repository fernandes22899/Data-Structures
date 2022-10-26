#include "set.h"

// constructs empty set
Set::Set()
{
  _root = new TrieNode;
  _size = 0;
}

//destructor
Set::~Set()
{
  delete _root;
  delete _size;
}

// insert a key into the set
// return false if key already exists; otherwise insert new key and return true
bool Set::insert( string key )
{
  TrieNode *cur = _root;

  if( find(key) )
    return false;

  for( int i = 0; i < key.length(); i++ ){
    int index = key[i] - 'a';

    //if( !cur->_root[index] )
    //  cur = cur->_root[index];
  }

  return false;
}

// remove a key from the set
// return false if the key doesn't exist; otherwise remove key and return true
bool Set::erase( string key )
{
  if( _root == NULL )
    return false;
  if( find(key) == false )
    return false;



  return false;
}

// search for a key
// return true if an element is found; false otherwise
bool Set::find( string key )
{
  if( _root == NULL )
    return false;

  TrieNode *cur = _root;
  for( int i = 0; i < key.length(); i++ ){
    //cur = cur->_root[key[i]];

    if( cur == NULL )
      return false;
  }
  return true;
}

// return size of the set
int Set::size()
{
  return _size;
}
