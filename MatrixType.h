C//
//  MatrixType.h
//  asdf
//
//  Created by Joshua Peckham on 1/16/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//
#include <iostream>
#include <fstream>
#ifndef MatrixType_h
#define MatrixType_h
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
class MatrixType {
private:
    int values[10][10];
    int numRows;
    int numCols;
public:
    MatrixType();
    // Function: Initialize Matrix to max standard
    // Precondition: n/a
    // Postcondition: will active array and set elements to 0
    void MakeEmpty();
    // Function: empty array
    // Precondition:Must have an array available
    // Postcondition: will clear each element of array
    int getRow() const;
    // Function: Return Row Size
    // Precondition: n/a
    // Postcondition: n/a
    int getCols() const;
    // Function: Return Row Size
    // Precondition: n/a
    // Postcondition: n/a
    void SetSize(int rowsSize, int colSize);
    // Function:Allocate array and set size of it
    // Precondition:must have an activated array, pass whole numbers, size must be within the max
    // Postcondition: will set size of array and activate array
    void StoreItem(int item, int row, int col);
    // Function: Move the integer into an element of the array
    // Precondition:must have an active array, must be an integer, must be within the parameters of nxm
    // Postcondition: will store value in correct element
    void Add(MatrixType otherOperand, MatrixType& result);
    // Function: Will add two matricies together and store them into another one
    // Precondition:matricies must be same size, must must bew two matricies
    // Postcondition: will add matricies togehter element by element in another matrix
    void Sub(MatrixType otherOperand, MatrixType& result);
    // Function: Will sub two matricies together and store them into another one
    // Precondition:matricies must be same size, must must bew two matricies
    // Postcondition: will sub matricies togehter element by element in another matrix
    void Mult(MatrixType otherOperand, MatrixType& result);
    // Function: Will multiply two matrixes together
    // Precondition: matricies must match (n*m ; m*p)
    // Postcondition: will multiply matricies together and store in different matrix
    void Print(ofstream& outfile) const;
    // Function: Will print matrix onto text file
    // Precondition: must have a matrix availble to transfer to file
    // Postcondition: will print matrix in file
    bool AddSubCompatible(MatrixType otherOperand)const;
    // Function: Will verify if they are able to perform the function
    // Precondition:Must have matricies available
    // Postcondition: will check compatabilities by comparying n*m and p*k
    bool MultCompatible(MatrixType otherOperand) const;
    // Function: Test if matricies are multipliable
    // Precondition:Must have matricies available
    // Postcondition: will check compatabilities
    bool SizeCheck(int rowsSize, int colSize) const;
    // Function: verify the size is correct before establishing the matrix
    // Precondition: must pass correct variables
    // Postcondition: determines if it will execute the set size function
    bool InactiveElement ()const;
    // Function: check to see if the array has been activated
    // Precondition: Array must be established
    // Postcondition: Will return if it is or isn't
    void PrintMatrix()const;
    // Function: print matrix
    // Matrix must have established size and elements
    // display whats in the matrix
    MatrixType operator +(const MatrixType otherOperand);
    MatrixType operator -(const MatrixType otherOperand);
    MatrixType operator *(const MatrixType otherOperand);
    
};


#endif /* MatrixType_h */
