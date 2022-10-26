/*CS515 Assignment 3P
File: image.cpp
Section: 01
Date: 2/26/19
colslaboration Declaration: cplusplus.com
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main( int argc, char **argv )
{
  int w, h, total;
  string input, hVal;

  //Check if number of args is correct
  if( argc != 4 )
    exit(1);

  string file = argv[1];   //Load up the file
  ifstream image( file );   //Put string file in ifstream

  //Does the file exist? If not, program fails
  if( !image.good() )
    exit(1);

  image >> input;   //pgm input

  //Needs to be a P2 image or else program fails
  if( input != "P2" )
    exit(1);

  image >> hVal;    //Get width

  //If it isn't a number, it's not a valid image
  if( !isdigit(hVal[0]) )
    exit(1);

  w = stoi(hVal); //string to int

  image >> hVal;  //Get width

  //If it isn't a number, it's not a valid image
  if( !isdigit(hVal[0]) )
    exit(1);

  h = stoi(hVal);
  image >> hVal;  //Max brightness

  //If it isn't a number, it's not a valid image
  if( !isdigit(hVal[0]) )
    exit(1);

  total = stoi( hVal ); //turns string into into

  //Make an array to store the image in
  int** imgarr = new int*[h];
  for(int i = 0; i < h; i++)
    imgarr[i] = new int[w];

  //Read each value and store it in the array
  for(int rows = 0; rows < h; rows++){
    for(int cols = 0; cols < w; cols++){
      image >> imgarr[rows][cols];

      if(imgarr[rows][cols] > total)
        exit(1);
    }
  }

  //Negative values of image
  ofstream imgOp( argv[2] );
  imgOp << input << "\n" << w << " " << h << "\n" << total << "\n";
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++)
      imgOp << total - imgarr[i][j] << " ";

    imgOp << endl;
  }

  //Rotate image 90 degrees
  ofstream imgOut( argv[3] );
  imgOut << input << "\n" << h << " " << w << "\n" << total << "\n";
  for(int i = 0; i < w; i++){
    for(int j = 0; j < h; j++)
      imgOut << imgarr[h - 1 - j][i] << " ";

    imgOut << endl;
  }

  for( int i = 0; i < h; i++ )
    delete[] imgarr[i];

  delete[] imgarr;
  image.close();
  imgOp.close();
  imgOut.close();

  return 0;
}
