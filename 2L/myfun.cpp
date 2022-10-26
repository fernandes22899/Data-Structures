#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <sstream>
using namespace std;

/*  Interprets an integer value in a byte string pointed to by str.
    Function discards any whitespace characters until first non-whitespace
    character is found. Then it takes as many characters as possible to
    form a valid integer number representation and converts them to integer value.
    The valid integer value consists of the following parts:
        (optional) plus or minus sign
        numeric digits

    Parameters
        str	 -	 pointer to the null-terminated char string to be interpreted

    Return value: Integer value corresponding to the contents of str on success.
        If the converted value falls out of range of corresponding return type,
        the return value is undefined.
        If no conversion can be performed, 0 is returned.

*/

int myatoi(const char * ptr)
{
  int int_output;
  string output = "";
  string input = ptr;
  int i;

  for(i=0;i<input.length();i++)
  {
      if(isspace(input[i]))
      {
        if(output != "")
          break;

        i++;
      }
    if(input[i] == '+' || input[i] == '-')
    {
      if(input[i+1] == '+' || input[i+1] == '-')
      {
        output = '0';
        break;
      }
      if(output != "")
        break;

      if(isspace(input[i+1])){
        output = '0';
        break;
      }else{
        output += input[i];
      }
    }
    if(input[i] == '.')
      break;

    if(isdigit(input[i]))
      output += input[i];

    if(isalpha(input[i]))
      break;

  }
  if(output == "")
    output = '0';

  istringstream buffer(output);
  int real_output;
  buffer >> real_output;
  return real_output;
  
}

// DO NOT ADD MAIN() FUNCTION IN THIS FILE


// DO NOT ADD MAIN() FUNCTION IN THIS FILE
