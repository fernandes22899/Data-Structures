#include "btree.h"

// helper method for tree display
void BTreeNode::indent(int depth){
    for(int i=0; i<depth; i++)
        cout << "\t";
}

BTreeNode * BLeaf::insert(int &newKey, string item){
    // find position for insert into current node
    int pos=size-1;
    while (pos>=0 && newKey<keys[pos]) {
        keys[pos+1] = keys[pos];
        data[pos+1] = data[pos];
        pos--;
    }
    keys[pos+1] = newKey;
    data[pos+1] = item;
    size++;

    if(size < ORDER) // if curent leaf node does not overflow
        return 0;

    else { // need split
        // create new leaf
        BLeaf *sibling = new BLeaf();

        // copy upper half of the current node's elements over
        for(int i=0; i < ORDER/2; i++){
            sibling->data[i] = data[i + (ORDER + 1)/2];
            sibling->keys[i] = keys[i + (ORDER + 1)/2];
        }

        // update size for both nodes
        sibling->size = ORDER/2;
        size -= ORDER/2;

        // send back new key by reference
        newKey = sibling->keys[0]; // sibling->keys[0] same as keys[(ORDER + 1)/2]

        // and return pointer to new node
        return sibling;
    }
}

void BLeaf::dump(int depth){
    indent(depth);
    int i;
    for(i = 0; i<size-1; i++)
        cout << keys[i] << ":" << data[i] << " ";
    cout << keys[i] << ":" << data[i] << endl;
}

BTreeNode * BInternal::insert(int &newKey, string item){
    // you fill in here...
    // find the child pointer for further insertion
    // recursively insert into child node
    // if returns a non-zero value, it indicates child node was split
    // include new added-key and child reference to current node
    // check if this node overflows. If so, split and return a pointer
    // to the new node (remember to update the size)

    int curChild = 0;
    int cnt = 0;

    while( cnt < curChild -1 && newKey > keys[cnt] )
		    cnt++;

	  BTreeNode * insert = child[cnt]->insert(newKey, item);

    if(insert){
		    for( int i = curChild - 1; i >= cnt + 1; i-- ){
			       keys[ i + 1 ] = keys[i];
			       child[ i + 1 ] = child[i];
		    }

		    child[ cnt + 1 ] = insert;
		    keys[ cnt + 1 ] = newKey;
	      curChild++;
        int MAX = cnt;

		    if(curChild > MAX){
			       BInternal * insert = new BInternal();

			       for(int i = 0; i < ( ( MAX + 1 ) / 2 ); i++){
				           insert->child[i] = child[( ( MAX + 2 ) / 2 ) + i];
				           insert->keys[i] = keys[( ( MAX + 2 ) / 2) + i];
			       }

			       insert->child = ( MAX + 1 ) / 2 ;
			       curChild -= ( MAX + 1 ) / 2;
			       newKey = keys[ ( MAX + 2 ) / 2 ];
			       return insert;
		    }

	  }
    return 0;
}

void BInternal::dump(int depth){
    indent(depth);
    cout << "[";
    int i;
    for(i=1; i<size-1; i++) // keys[0] not displayed
        cout << keys[i] << ",";
    cout << keys[i] << "]" << endl;

    // call dump on all children
    for(int i=0; i<size; i++)
        child[i]->dump(depth+1);
}

void BTree::insert(int newKey, string item){
    BTreeNode *split = root->insert(newKey, item);
    if(split) {
        // splitting root; new root now has two children
        BInternal *newRoot = new BInternal();
        newRoot->child[0] = root;
        newRoot->child[1] = split;
        newRoot->keys[1] = newKey;
        newRoot->size = 2;
        root = newRoot;
    }
}
