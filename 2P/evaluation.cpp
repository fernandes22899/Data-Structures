#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**CS515 Assignment 2
File: evaluation.cpp
Name: Jeffrey Fernandes
Section: 1
Date: 2/13/2020
Collaboration Declaration: cplusplus.com
*/

bool checkVar( char x );
bool checkOp( char x );
int pemdas( string x );
int calculationSolver( string exp );
string infToPost( string exp );

stack<int> st;
string ans = " ";

/*
This method solves equation by equation until there is an answer
and it will be no longer called.
*/
int calculationSolver( string exp )
{
	stack<int> s;
	int i;
	for( i = 0; i < exp.length(); i++ ){
		if( checkOp( exp[i] ) ){
			int two = s.top();
			s.pop();
			int one = s.top();
			s.pop();
			int answ;

			if( exp[i] == '+' )
				answ = one + two;
			else if( exp[i] == '-' )
				answ = one - two;
			else if( exp[i] == '*' )
				answ = one * two;
			else if (exp[i] == '/')
				answ = one / two;

			s.push( answ );
		}

		else if( exp[i] <= '9' && exp[i] >= '0'){
			int y = 0;
			int z = i;

			while( z < exp.length() && ( exp[z] >= '0' && exp[z] <= '9' ) ){
			  y = ( y * 10 ) + ( exp[z] - '0' );
				z = z + 1;
			}
			i = z;
			s.push( y );
		}

	}
	return s.top();
}

/*
Changes the string from the user input to postfix, which is easier for the
program to calculate.
*/
string infToPost( string exp )
{
	stack <string> s;

	//Goes through the line
	for( int i = 0; i <= exp.length(); i++ ){

		if( exp[i] <= '9' && exp[i] >= '0' ){ //Checks for number
			int j = i;
			while( j <= exp.length() && ( exp[j] >= '0' && exp[j] <= '9' ) ){ //Checks if number is more than 1 digit
				ans += string(1,exp[j]);
				j = j + 1;
			}
			ans += " ";
			i = j - 1;
		}
		else if( string( 1, exp[i] ) == "(" || string( 1, exp[i] ) == "[" || string( 1, exp[i]) == "{" ){
			s.push( string( 1, exp[i] ) );
		} //Beginning of section
		else if( string( 1, exp[i] ) == ")" || string( 1, exp[i] ) == "]" || string( 1, exp[i] ) == "}" ){ //End of section
			while( !s.empty() &&  ( s.top() != "(" && s.top() != "[" && s.top() != "{" ) ){
				ans += s.top() + " ";
				s.pop();
			}
			s.pop();
		}
		else if( checkOp( exp[i] ) ){
			while( !s.empty() && ( ( pemdas( string( 1, exp[i] ) ) <= pemdas( s.top() ) ) &&  ( s.top() != "("  || s.top() != "["  || s.top() != "{" ) ) ){
				ans += s.top() + " ";
				s.pop();
			}
			st.push( exp[i] );
			s.push( string( 1, exp[i] ) );
		}
	}
	while( !s.empty() ){
		ans += s.top() + " ";
		s.pop();
	}

	return ans;
}

/*
This method is like checkOp, except it checks if the character is a
number or letter.
*/
bool checkVar( char x ){
  bool check = false;
	if( x >= '0' && x <= '9' )
		check = true;
	if( x >= 'a' && x <= 'z')
		check = true;
	if( x >= 'A' && x <= 'Z')
		check = true;

	return check;
}

/*
This method is called to check every character and see if it is an operator.
*/
bool checkOp( char x ){
  bool check = false;
	if( x == '+' || x == '-' || x == '*' || x == '/' )
		check = true;

	return check;
}

/*
This method is called using a string parameter and it check at what operator
should be used first by setting a value to it.
*/
int pemdas( string x ){
	int check = 0;
	if( x == "+" || x == "-" )
		check = 1;
	if( x == "*" || x == "/" )
		check =  2;

	return check;
}


int main( int argc, char **argv )
{
		string input;
		string emp = "";
		int check = 0;
		//cout << "Before while: " << input << endl;
		while( ( !input.empty() || input != "exit" ) || !cin.eof() )
		{
      string ex = "";
		  getline( cin, input ); //Getting user input
			//============================================
			//Checking for words if user wants to exit
      for( int i = 0; i <= input.length(); i++ ) //case incensitive maker
        ex += tolower( input[i] );
      if( ex == "exit"){
				cout << "Expression: ";
        exit(1);
      }
			//============================================
			//Gets rid of spaces
			int i;
			for( i = 0; i <= input.length(); ++i ){
        if( isspace( input[i] ) ){
          input.erase(i,1);
        }
      }

			//============================================
			//Skips blank lines
			if( input != "exit" && !cin.eof() ){
				while( input.empty() ){
					if( !cin.eof() )
					   getline( cin,input );
					else{
						cout << "Expression: ";
						return 0;
					}
				}

			//===========================================

			stringstream st( input );
			string ans = infToPost( input );
			int a = calculationSolver( ans );
			cout << "Expression: ";
			cout << "Answer: " << a << endl;
			}
			else if( cin.eof() && check == 0 ){
				if( input[0] == '{' ){
					stringstream st( input );
					string ans = infToPost( input );
					int a = calculationSolver( ans );
					cout << "Expression: ";
					cout << "Answer: " << a << endl;
					check++;
				}
				else{
					cout << "Expression: ";
	        return 0;
				}

			}
			else{
				cout << "Expression: ";
        return 0;
				}
		}
		cout << "Expression: ";
		return 0;
}
