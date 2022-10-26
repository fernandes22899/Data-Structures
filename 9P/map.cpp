// A generic Map implemented with right-threaded BST
// BST is not balanced

#include <map> // helper container for thread copying
#include <iostream> //for cout

template <typename KEY, typename T>
Map<KEY, T>::Map(){
	// create a dummy root node
	_root = new Elem;
	_root->left = _root;  // empty tree
	_root->right = 0;
	_root->rightThread = false;
	_size = 0;

}

// copy constructor
template <typename KEY, typename T>
Map<KEY, T>::Map(const Map<KEY,T> &v){
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
		copyCode(_root->left, v._root->left); // to deep copy the tree without dummy nodes
		copyThread(_root, v._root); // to copy the threading; must pass dummy nodes to complete the threads
		_size = v._size;
	}
}

// construct a key-element map to rethread the new tree
// the map contains all nodes key values and their corresonding elem node address
// for furture lookup in setting up threads
template <typename KEY, typename T>
void Map<KEY, T>::addToMap(Elem* root, map<KEY, Elem*> &keyElemMap){
	if (root) {
		keyElemMap[root->key] = root;
		addToMap(root->left, keyElemMap);
		if (!root->rightThread)
			addToMap(root->right, keyElemMap);
	}
}

// common copy code for thread copying
template <typename KEY, typename T>
void Map<KEY, T>::copyThread(Elem* &newRoot, Elem* origRoot){
	// construct the key-element map for new and orig tree
	map<KEY, Elem*> newKeyElemMap;
	map<KEY, Elem*> origKeyElemMap;
	addToMap(newRoot->left, newKeyElemMap);
	addToMap(origRoot->left, origKeyElemMap);

	// start at the last element in the tree, which threads to root
	typename std::map<KEY, Elem*>::reverse_iterator it = origKeyElemMap.rbegin();
	newKeyElemMap[it->first] -> rightThread = true;
	newKeyElemMap[it->first] -> right = newRoot;

	// then thread the rest of the tree backwardly
	it++;
	while(it != origKeyElemMap.rend()){
		if (it->second->rightThread){
			newKeyElemMap[it->first] -> rightThread = true;
			newKeyElemMap[it->first] -> right = newKeyElemMap[ origKeyElemMap[it->first]->right->key ];
		}
		it++;
	}
}

// common copy code for deep copy a tree without copying threads
template <typename KEY, typename T>
void  Map<KEY,T>::copyCode(Elem* &newRoot, Elem* origRoot){
	if (origRoot == 0)
		newRoot = 0;
	else{
		newRoot = new Elem;
		newRoot->key = origRoot->key;
		newRoot->data = origRoot->data;
		newRoot->rightThread = origRoot->rightThread;
		copyCode(newRoot->left, origRoot->left);
		if (!origRoot->rightThread)
			copyCode(newRoot->right, origRoot->right);
	}
}
//_____________________________________________________________________
template <typename KEY, typename T>
Map<KEY, T>::~Map()
{
	delete _root;

	cout << "deallocation" << endl;
}


template <typename KEY, typename T>
bool Map<KEY, T>::insert(KEY key, T data)
{
	if( key == NULL ){
		return false;
	}
	if( key == _root ){
		return false;
	}
	



	return true;
}

template <typename KEY, typename T>
bool Map<KEY, T>::erase(KEY key)
{


	return true;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::begin() const {  // return the left most (smallest) tree node
	// fill in here
	Elem newRoot = new Elem;
	if( _root->left == NULL ){
		return _root;
	}
	newRoot = _root->left;
	while( newRoot->left != NULL ){
		newRoot = newRoot->left;
	}
	return newRoot;
	delete newRoot;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::end() const {  // return the dummy root node
	// fill in here
	return _root;
}


template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::Iterator::operator++(int){
	// fill in here

}

template <typename KEY, typename T>
typename Map<KEY, T>::Elem& Map<KEY, T>::Iterator::operator*(){
	// fill in here
}

template <typename KEY, typename T>
typename Map<KEY, T>::Elem* Map<KEY, T>::Iterator::operator->(){
	// fill in here
}
/*
template <typename KEY, typename T>
typename Map<KEY, T>::Bool Map<KEY, T>::Iterator::operator==(Iterator it){
	// fill in here
}

template <typename KEY, typename T>
typename Map<KEY, T>::Bool Map<KEY, T>::Iterator::operator!=(){
	// fill in here
}
*/

//__________________________________________________________________
template <typename KEY, typename T>
int Map<KEY, T>::size() const{
	return _size;
}

// output the structure of tree. The tree is output as "lying down"
// in which _root is the LEFT most Elem.
template <typename KEY, typename T>
void Map<KEY, T>::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		if (p->right && !p->rightThread)
			printTree(out, level+1,p->right);
		for(i=0;i<level;i++) {
			out << "\t";
		}
		out << p->key << " " << p->data << '\n';
		printTree(out, level+1,p->left);
	}
}

// outputs information in tree in inorder traversal order
template <typename KEY, typename T>
ostream& Map<KEY, T>::dump(ostream& out) const{
	if ( _root == _root->left) {// tree empty
		return out;
	}
	printTree(out, 0, _root->left);   // print tree structure
	return out;
}


// outputs using overloaded << operator
template<typename KEY, typename T>
ostream& operator<< (ostream& out, const Map<KEY, T>& v){
	v.dump(out);
	return out;
}
