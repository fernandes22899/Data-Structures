#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;
int med(int arra[], int values);

string file, sty, tem, t;
int w, h, total;
int hB = -1, wB = -1, totalB = -1;

int main( int argc, char **argv )
{
  //Array of strings containing image data
  string* imgFiles = new string[argc - 2];

  for( int i = 0; i < argc - 2; i++ )
    imgFiles[i] = "";

  //Check if number of args is correct
  if( argc < 4 || argc > 11 )
    exit(1);

  int count = 1;

  //check all imgFiles except last argument
  while( count < argc - 1 )
  {
    file = argv[count];
    ifstream image(file);

    //Check if thefile actually exists
    if( !image.good() )
      exit(1);

    //Get the PGM sty
    image >> sty;

    //If it isn't P2, it's not a valid image
    if( sty != "P2" )
      exit(1);

    image >> tem;
    //If it isn't a number, it's not a valid image
    if( !isdigit(tem[0]) )
      exit(1);

    w = stoi( tem );
    image >> tem;
    //If it isn't a number, it's not a valid image
    if( !isdigit( tem[0]) )
      exit(1);

    h = stoi(tem);

    image >> tem;

    //If it isn't a number, it's not a valid image
    if( !isdigit( tem[0] ) )
      exit(1);

    total = stoi( tem );
    //Checks for right values
    if( totalB == -1 && hB == -1 && wB == -1 ){
      totalB = total;
      hB = h;
      wB = w;
    }
    //Send errors for wrong values
    else{
      if( totalB != total )
        exit(1);
      if( wB != w )
        exit(1);
      if( hB != h )
        exit(1);
    }
    //image values into a string
    while( !image.fail() ){
      t = "";
      image >> t;
      imgFiles[count - 1] += " " + t;
    }
    count++;
  }
  //Initializing 3D array
  int lenarr = argc - 2;
  int*** imarr = new int**[lenarr];

  //Initializing 2D array
  for( int i = 0; i < lenarr; i++ ){
    imarr[i] = new int*[h];

    for( int j = 0; j < h; j++ )
      imarr[i][j] = new int[w];
  }

  //Looping through the array to begin adding images
  for( int i = 0; i < count - 1; i++ ){
    stringstream stream;
    stream << imgFiles[i];
    for( int rows = 0; rows < h; rows++ ){
      for( int cols = 0; cols < w; cols++ ){
        stream >> imarr[i][rows][cols];
      }
    }
  }

  //Double array to store outputs
  int** output = new int*[h];
  for( int i = 0; i < h; i++ )
    output[i] = new int[w];

  int* values = new int[count - 1];
  for( int cols = 0; cols < w; cols++ ){
    for( int rows = 0; rows < h; rows++ ){
      for( int i = 0; i < count - 1; i++ )
        values[i] = imarr[i][rows][cols];

      output[rows][cols] = med( values, count - 1 );
    }
  }

  ofstream out( argv[argc - 1] );
  out << "P2\n" << w << " " << h << "\n" << total << endl;

  for( int rows = 0; rows < h; rows++ ){
    for( int cols = 0; cols < w; cols++ )
      out << output[rows][cols] << " ";

    out << endl;
  }


  delete[] imgFiles;
  delete[] imarr;
  delete[] values;
  delete[] output;
  return 0;
}

/*
takes an array and int formal parameters.
returns the median value
*/
int med( int arra[], int values )
{
  sort( arra, arra + values );
  if(values % 2 == 0)
    return ( arra[values / 2] + arra[(values / 2) - 1] ) / 2;

  return arra[values / 2];
}
