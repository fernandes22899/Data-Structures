/* CS515 Assignment 0P
File: hello.cpp
Name: Jeffrey Fernandes
Section: 1
Date: 1/24/2020
Collaboration Declaration: None
*/

#include <iostream> // for cin and cout
#include <string> // for string type
using namespace std;

int main( int argc, char ** argv ) {
    string name;

    do{
      cout << "What is your name?" << endl;
      getline( cin, name );
    }while( name.length() == 0 );

    cout << "Hello World!" << endl;
    cout << "Welcome to CS515, " << name << "!" << endl;

    return 0;
}
