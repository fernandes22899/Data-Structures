#include "HuffTree.h"
#include "PQueue.h"
#include <iostream>
/**
CS515 Assignment 9
File: HuffTree.cpp
Name: Yulin Yang
Section: 1
Date: 4/4, 2019
Collaboration Declaration:
A
ssistance received from TA, PAC and online resources etc.
...
*/
//constructor
HuffTree::HuffTree(){
    _root = new HuffNode;
}

//copy constructor
HuffTree::HuffTree( const HuffTree& rhs ){
    _root = new HuffNode;
    copyCode( _root->left, rhs._root ->left );
}

HuffTree & HuffTree::operator=( const HuffTree & rhs ){
    destructCode( _root->left );
    _root->left = 0;
    copyCode( _root->left, rhs._root->left );
    return* this;
}

//destructor
HuffTree::~HuffTree(){
    if( _root->left )
        destructCode( _root->left );
    delete _root;
}
// --------- copyCode -------------
void HuffTree::copyCode( HuffNode*& n1, HuffNode* n2){
    if ( n2 == 0 )
        n1 = 0;
    else{
        n1 = new HuffNode(0, 0, n2->freq, n2->data, n2->code );
        copyCode( n1->left, n2->left);
        copyCode( n1->right, n2->right);
    }
}

//helper function for distructor
void HuffTree::destructCode( HuffNode* n ){
    if ( n == 0 )
        return;

    if( n->left )
        destructCode( n->left );
    if( n->right )
        destructCode( n->right );
    delete n;
}

void HuffTree::printTree( HuffNode* node ){
    if ( node == 0 )
        return;
    if( node->left )
        printTree( node->left );
    if( node->right )
        printTree( node->right );
    cout << node->freq << endl;
}

// get Huffman code and return it as a string
string HuffTree::getCode( char ch ){
    string str = "";
    readCode( _root->left, ch, str);
    return str;
}

void HuffTree::readCode( HuffNode* n, char ch , string& s ){
    if( n == 0 )
        return;
    if( n->left )
        readCode( n->left, ch, s );
    if(n->right)
        readCode( n->right, ch,s );

    if( n->data == ch )
        s = n->code;
}

// build Huffman tree from an array of characters
// and and an array of their corresponding freqencys;
// the size of both arrays is given
void HuffTree::buildTree(char * chs, int * freqs, int size){
    destructCode( _root->left );
    _root->left = 0;

    if( size == 0 )
        return;

    HuffNode* _array[ size ];
    for( int i = 0; i < size; i++ )
        _array[i] = new HuffNode( 0, 0, freqs[ i ], chs[ i ], "" );

    PQueue< HuffNode*, 100 >q ( _array, size );

    while ( q.size() > 1 ) {
        HuffNode* temp1 = q.findMin();
        q.deleteMin();
        HuffNode* temp2 = q.findMin();
        q.deleteMin();
        HuffNode* temp3 = new HuffNode( temp1, temp2, temp1 -> freq + temp2 -> freq, '\0', "" );
        q.insert( temp3 );
    }
    //update _root pointer
    _root->left = q.findMin();
    HuffNode* cur = _root->left;

    //update code
    string s = "";
    if( size > 1 )
        updateCode( _root->left, s );
    else
        _root->left->code = s + '0';
}

void HuffTree::updateCode( HuffNode* node, string s ){
    if( !node )
        return;
    if( node->left )
        updateCode( node->left, s + '0' );

    if( node->right )
        updateCode( node->right, s + '1' );

    if( node->data != '\0' )
        node->code = s;
    if( !node->left && !node->right){
        node->code = s;
    }
}
