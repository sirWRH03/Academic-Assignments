#include <iostream> // inclusion of header files
#include <string>
#include <fstream>

using namespace std; // namespace declaration

void LoadImage(const string imagefile, int image[MAXROWS][MAXCOLS]) // load function definition
{
    ifstream inFile; // filestream declaraiton
    
    inFile.open(imagefile.c_str()); // open filestream
    inFile.ignore(50, '\n'); // skipping the initial information for the image files
    inFile.ignore(1); // skipping initial information for the image files
    
    for (int i = 0; i < MAXROWS; i++) // for each row
    {
        for (int j = 0; j < MAXCOLS; j++) // for each column
        {
        inFile >> image[i][j]; // from the in filestream, read the next value
        inFile.ignore(1); // skips the whitespace between values
        }
    }
}

void FlipHorizontal(int image[MAXROWS][MAXCOLS]) // horizontal flip function definition
{
    int flipImage[MAXROWS][MAXCOLS]; // flipped image reference
    for (int i = 0; i < MAXROWS; i++) // for each row
    {
        for (int j = 0; j<MAXCOLS; j++) // for each column
        {
            flipImage[i][j] = image[i][MAXCOLS-1-j]; // set flipped image equal to the flip of the original image (image[i][last column minus j value])
        }
    }

    for (int i = 0; i < MAXROWS; i++) // for each row
    {
        for (int j = 0; j < MAXCOLS; j++) // for each column
        {
            image[i][j] = flipImage[i][j]; // sets the image value at [i][j] to be the flipped images value
        }
    }
}

void FlipVertical(int image[MAXROWS][MAXCOLS]) // vertical flip function definition
{
    int flipImage[MAXROWS][MAXCOLS]; // flipped image reference
    
    for (int i = 0; i < MAXROWS; i++) // for each row
    {
        for (int j = 0; j<MAXCOLS; j++) // for each column
        {
        flipImage[i][j] = image[MAXROWS-1-i][j]; // set flipped image equal to the flip of the orignial image (image[last row minus i value][j])
        }
    }

    for (int i = 0; i < MAXROWS; i++) // for each row
    {
        for (int j = 0; j < MAXCOLS; j++) // for each column
        {
            image[i][j] = flipImage[i][j]; // sets the image value at [i][j] to be the flipped images value
        }
    }
}

void Transpose(int image[MAXROWS][MAXCOLS]) // transposition fucntion definition
{
    int flipImage[MAXROWS][MAXCOLS]; // flipped image reference
    for (int i = 0; i < MAXROWS; i++) // for each row
    {
        for (int j = 0; j<MAXCOLS; j++) // for each column
        {
            flipImage[MAXROWS-1-i][j] = image[j][MAXCOLS-1-i]; // set flipped image equal the flip of the original image (image[last row minus i value][last column minus j value])
        }
    }

    for (int i = 0; i < MAXROWS; i++) // for each row
    {
        for (int j = 0; j < MAXCOLS; j++) // for each column
        {
            image[i][j] = flipImage[i][j]; // sets the image value at [i][j] to be the flipped images value
        }
    }
}

void RotateCW(int image[MAXROWS][MAXCOLS]) // clockwise rotation function definition
{
    Transpose(image);
    FlipHorizontal(image);
}

void RotateCCW(int image[MAXROWS][MAXCOLS]) // counter clockwise rotation funciton definition
{
    Transpose(image);
    FlipVertical(image);
}