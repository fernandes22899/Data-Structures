#include <iostream>
#include <string>
#include "HuffTree.h"
#include <cctype> // for check the cahracter is whether alphabetic or digit.
#include <fstream> //reading from the file
#include <ctype.h>
#include <iomanip>
using namespace std;

/**
CS515 Assignment 9
File: HuffmanCoder.cpp
Name: Yulin Yang
Section: 1
Date: 4/4, 2019
Collaboration Declaration:
A
ssistance received from TA, PAC and online resources etc.
...
*/
int main( int argc, char** argv){
    if( argc != 2 ){
        cout<< "Wrong number of arguments" <<endl;
        return 0;
    }
    int freq[26];
    char list[26];
    for( int i = 0; i < 26; i++){
        freq[i] = 0;
        list[i] = 'a' + i;
    }

    ifstream input( argv[1]);
    if( input.fail()){
        cout << "Fail to open file" << endl;
        return 1;
    }

    char ch;
    int allBits = 0;// before compression total number of bits
    int other = 0;
    while( input.get( ch )){
        allBits++;
        if( isalpha(ch)){
            ch = tolower(ch);
            freq[ch - 'a' ]++;
        }
        else{
            other++;
        }
    }
    input.close();

    HuffTree huffTree;
    huffTree.buildTree( list, freq, 26);
    int totalBits = 0; // total bits after compression
    for( int i = 0; i < 26; i++){
        totalBits += freq[i] * huffTree.getCode(list[i]).length();
    }

    int finalOriginalBits = allBits * 8;
    int finalAfterBits = totalBits + 8 * other;
    float result = 100*(float)(finalOriginalBits - finalAfterBits)/finalOriginalBits;

    cout << "original bits: "<< finalOriginalBits << endl;
    cout << "bits after compression: " << finalAfterBits <<endl;
    cout << "compression rate: " << setprecision(4) << result <<"%"<<endl;
}
