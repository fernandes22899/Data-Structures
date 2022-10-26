#include<iostream>
using namespace std;

/******************************************************************
 *   Calculate the factorial of a number input from keyboard.
 ******************************************************************/

long factorial(int n); // function declaration

int main(){
    int n = 0;
    cin >> n;
    cout << "The factorial of " << n << " is " << factorial(n);
    cout << endl;
    return 0;
}

long factorial(int n)
{
    long result = 1;
    //cout << "testing here " << n << endl;
    while(n){
        result *= n;
        n--;
        //cout << "testing here for result " << result << endl;
    }
    return result;
}
