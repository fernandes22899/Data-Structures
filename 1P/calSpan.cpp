/* CS515 Assignment 1P
File: calSpan.cpp
Name: Jeffrey Fernandes
Section: 1
Date: 2/12/19
Collaboration Declaration: None
*/

#include <iostream>
#include <string> // for string type
#include <fstream> // for file import
#include <vector> //for vector
#include <ctype.h> //isdigit() function


using namespace std;

int main( int argc, char ** argv ) {

  string line, file, strin;
  ifstream myfile;     //declaring an ifstream to insert a file
  vector <double> vec; //declaring vec with no specific amount
  double pb, horl;
  int check = 0, cpp;
  bool oor, ch;
  string ex = "";


  if( argc == 2 )  //check if there's right number of arguments from the command line
  		file = argv[1]; //file names put into a string
  else{					   //if not then error will occur
  		cerr << "Wrong number of arguments" << endl;
  		return 1;
	}

  myfile.open( file ); //opens file from command line input

  if( !myfile.is_open() ){ //if file isn't open then send an error
    cerr << "Error opening file" << endl;
    return 1;
  }


  while( myfile >> line ){ //inserts numbers into the vector from the ifstream

    for( int i = 0; i < line.length(); i++ ){
      if( !isdigit(line[i]) && line[i] != '.' && line[i] != '-' ) //checks for bad digits
        line = "-1"; //value set to -1 to use later
      else if( stod(line) > 100 || stod(line) < -100 ) //inside boundaries [-100,100]
        line = "-1"; //value set to -1 to use later
    }

    pb = stod( line );
    vec.push_back( pb );
  }
/*
  //while loop testing
  for( int i = 0; i < vec.size() + 1; i++ ){
    cout << "vec values: " << vec[i] << endl;
  }
*/

  while( true ){
    oor = false;

    cout << "Which minute to query? ";
    cin >> strin;

    int x = atoi( strin.c_str() );        //converts string into number
    //cout << "X value: " << x << endl;   //checking x value

    for( int i = 0; i < strin.length(); i++ ) //case incensitive maker
      ex += tolower( strin[i] );

    for( int i = 0; i < strin.length(); i++ )
      if( !isdigit(strin[i]) )
        check++;

    if( vec[0] == '-' ){
			cout << "Query minute out of range" << endl;
      oor = true;
		}

    //cout << vec[x] << endl;
    if( check == 0 && stoi(strin) < vec.size() )
    {
      cpp = 0;                          //declared for -minute(s) high
      horl = vec.at(x);
      ch = false;

      for(int i = x; i >= 0; i--)
			{
				if( horl >= vec.at(i))
					cpp++;
				if(vec.at(x) == -1)
					ch = true;
				if( horl < vec.at(i))
					break;
			}

      if( !ch ){
        cout << "Data at minute " << x << " is a "
          << cpp << "-minute(s) high." << endl;
      }
      else{
        cout << "Data at minute " << x << " is corrupted. " << endl;
      }

   }
   else if( check != 0 ){
     if( strin == "exit" )                  //exits code if user types in exit
       exit(1);
     else if( oor == false ){
       cout << "Wrong query input." << endl;
     }
   }
   else if( stoi(strin) > vec.size() - 1 ){ //if user input greater than vec inputs
     cout << "Query minute out of range" << endl;
   }
  }
  myfile.close();                   //closes ifstream file

  return 0;
}
