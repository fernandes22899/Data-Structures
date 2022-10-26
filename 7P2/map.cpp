// A non-generic Map ADT implemented with a BST data structure
// The BST is not-balanced and non-threaded
#include "map.h"

Map::Map(){
	// create a dummy root node and set up an empty tree
	_root = new Elem;
	_root->left = _root;
	_root->right = 0;
	_size = 0;

}

//Destructor
Map::~Map()
{
	if(_root->left != _root)
		destructCode(_root->left);

	delete _root;
}

//DELETE
void Map::destructCode(Elem *& p){
	if( p->left != NULL ){
		destructCode(p->left);
	}
	if( p->right != NULL ){
		destructCode(p->right);
	}
	delete p;
}


// copy constructor
Map::Map(const Map &v){
	// if empty tree
	if (v._root == v._root->left){
		_root = new Elem;
		_root->left = _root;  // empty tree
		_root->right = 0;
		_size = 0;
	} else {
		_root = new Elem;
		_root->left = _root;
		_root->right = 0;
		copyCode(_root->left, v._root->left);
		_size = v._size;
	}
}

// common copy code for deep copy a tree
void  Map::copyCode(Elem* &newRoot, Elem* origRoot){
	if (origRoot == 0)
		newRoot = 0;
	else{
		newRoot = new Elem;
		newRoot->key = origRoot->key;
		newRoot->data = origRoot->data;
		copyCode(newRoot->left, origRoot->left);
		copyCode(newRoot->right, origRoot->right);
	}
}

bool Map::insert( KEY_TYPE key, VALUE_TYPE val ){

	Iterator it = find(key);

	if( it == end() ){
		//Creating node and inserting values
		Elem *node = new Elem;
		node->key = key;
		node->data = val;
		//Making sure node has no children
		node->right = NULL;
		node->left = NULL;

		//If empty tree, insert node as root
		if( _root->left == _root ){
			_root->left = node;
		}
		else{
			Elem *cur = _root->left;
			Elem *prev = _root;
			while( cur != NULL ){
				if( key < cur->key ){
					prev = cur;
					cur = cur->left;
				}
				else if( key > cur->key ){
					prev = cur;
					cur = cur->right;
				}
			}
			if( key < prev->key ){
				prev->left = node;
			}
			else if( key > prev->key ){
				prev->right = node;
			}
		}
		_size++;
		return true;
	}
	return false;
}

bool Map::erase( KEY_TYPE key ){

	Iterator it = find(key);

	if( it != end() ){
		Elem *cur = _root->left;
		Elem *prev = _root;
		while( true ){
			if( key < cur->key ){
				prev = cur;
				cur = cur->left;
			}
			else if( key > cur->key ){
				prev = cur;
				cur = cur->right;
			}
			else{
				break;
			}
		}
		//Case 0
		if( (cur->left == NULL) && (cur->right == NULL) ){
			if( prev == _root ){
				_root->left = _root;
			}
			else if( cur == prev->left ){
				prev->left = NULL;
			}
			else if( cur == prev->right ){
				prev->right = NULL;
			}
			delete cur;
		}
		//Case 1
		else if( ((cur->left != NULL) && (cur->right == NULL)) || ((cur->left == NULL) && (cur->right != NULL)) ){
			Elem *temp = new Elem;
			//Step1: Find successor
			if( cur->left != NULL ){
				Elem *curleft = cur->left;
				temp->key = curleft->key;
				temp->data = curleft->data;
				while( curleft->right != NULL ){
					curleft = curleft->right;
					temp->key = curleft->key;
					temp->data = curleft->data;
				}
				erase( curleft->key );
			}
			else if( cur->right != NULL ){
				Elem *curright = cur->right;
				temp->key = curright->key;
				temp->data = curright->data;
				while( curright->left != NULL ){
					curright = curright->left;
					temp->key = curright->key;
					temp->data = curright->data;
				}
				erase( curright->key );
			}
			//Step 2: Temporarily store data
			//Setp 3: Call erase on successor's key
			//Step 4: Update cur
			cur->key = temp->key;
			cur->data = temp->data;
		}
		//Case 2
		else{
			//Creates Successor and Successor parent elements
			Elem *sucParent = cur;
			Elem *suc = sucParent->right;
			Elem *temp = new Elem;
			//Step 1: Get successor node
			while( suc->left != NULL ){
				sucParent = suc;
				suc = suc->left;
			}
			//Step 2: Temporarily store data
			temp->key = suc->key;
			temp->data = suc->data;

			//Setp 3: Call erase on successor's key
			erase(suc->key);

			//Step 4: Update cur
			cur->key = temp->key;
			cur->data = temp->data;
		}
		_size--;
		return true;
	}
	return false;
}

int Map::size() const{ //size return function
  return _size;
}

Map& Map::operator=(const Map &rhs){
    if(_root != _root->left){
        destructCode(_root->left);
        delete _root;
    }
    Elem *el = rhs._root;
    copyCode(_root, el);
    _size = rhs._size;
    return *this;
}

Map::Iterator Map::find( KEY_TYPE key ) const{

	Elem *le = _root->left;

	if( _root->left == _root ){
		return end();
	}
	else{
		while( le != NULL  ){
			if( key < le->key ){
				le = le->left;
			}
			else if( key > le->key ){
				le = le->right;
			}
			else{
				break;
			}
		}
		Map::Iterator iter(le);
		if( le == NULL ){
			iter = end();
		}
		return iter;
	}
}

//Beginning Iteration through a set
Map::Iterator Map::begin() const{
	Elem *begin = _root->left;
    if(begin->left != NULL){
        while(begin->left != NULL){
            begin = begin->left;
        }
    }
    Map::Iterator it(begin);
    return it;
}

//Ending iteration through a set
Map::Iterator Map::end() const{
	Map::Iterator it(_root);
    return it;
}

bool Map::insert(Elem *& root, const KEY_TYPE& key, const VALUE_TYPE& data)
{

	return true;
}

VALUE_TYPE& Map::operator[]( KEY_TYPE key ){
	Iterator it = find(key);
	VALUE_TYPE val;
    if ( it == end() )
		{
        Map::insert( key, val );
        it = find (key );
    }
    return it->data;
}

//-----Overloaded Operators------------
Map::Elem& Map::Iterator::operator*(){
  return *_cur;
}
Map::Elem* Map::Iterator::operator->(){
  return _cur;
}
bool Map::Iterator::operator==(Iterator it) const{
  return _cur == it._cur;
}
bool Map::Iterator::operator!=(Iterator it) const{
  return _cur != it._cur;
}
//----------------------------------------

//
//  Do Not Modify Below Here
//
//
// output the structure of tree. The tree is output as "lying down"
// in which _root is the LEFT most Elem.
void Map::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		printTree(out, level+1, p->right);
		for(i=0;i<level;i++) {
			out << "\t";
		}
		out << p->key << " " << p->data << '\n';
		printTree(out, level+1, p->left);
	}
}

// outputs information in tree
ostream& Map::dump(ostream& out) const{
	if ( _root == _root->left) { // tree empty
		return out;
	}
	printTree(out, 0, _root->left);   // print tree structure
	return out;
}

// outputs using overloaded << operator
ostream& operator<< (ostream& out, const Map& v){
	v.dump(out);
	return out;
}
