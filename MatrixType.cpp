//
//  MatrixType.cpp
//  asdf
//
//  Created by Joshua Peckham on 1/16/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "MatrixType.h"

MatrixType::MatrixType() {
    numRows = 0;
    numCols = 0;
}
int MatrixType::getRow() const{
    return numRows;
}
int MatrixType::getCols() const{
    return numCols;
}
void MatrixType::MakeEmpty(){
    for (int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            values[i][j] = 0;
        }
    }
    
}
void MatrixType::SetSize(int rowsSize, int colSize) {
    numRows = rowsSize;
    numCols = colSize;
}
void MatrixType::StoreItem(int item, int row, int col){
    values[row][col] = item;
}
void MatrixType::Add(MatrixType otherOperand, MatrixType& result){
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            result.values[i][j] = values[i][j] + otherOperand.values[i][j];
        }
    }
}

void MatrixType::Sub(MatrixType otherOperand, MatrixType& result){
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            result.values[i][j] = values[i][j] - otherOperand.values[i][j];
        }
    }
}

void MatrixType::Mult(MatrixType otherOperand, MatrixType& result){
    for (int i = 0; i < numRows; i++){
        for ( int j = 0; j < otherOperand.numCols; j++){
            for( int m = 0; m < otherOperand.numRows; m++){
                result.values[i][j] += (values[i][m] * otherOperand.values[m][j]);
            }
        }
    }
    result.PrintMatrix();
}
void MatrixType::Print(ofstream& outFile) const{
    outFile << "Printing File Info" << endl;
    for ( int i = 0; i < numRows; i++){
        for( int j = 0; j < numCols; j++){
            outFile << values[i][j] << " ";
        }
        outFile << endl;
    }
    outFile << "End Print \n\n";
}
void MatrixType::PrintMatrix() const{
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            cout << this->values[i][j] << " ";
        }
        cout << endl;
    }
}

bool MatrixType::AddSubCompatible(MatrixType otherOperand) const{
    return ( numRows == otherOperand.numRows && numCols == otherOperand.numCols );
}
bool MatrixType::MultCompatible(MatrixType otherOperand) const{
    return ( numCols == otherOperand.numRows);
}
bool MatrixType::SizeCheck(int rowsSize, int colSize) const{
    return ( numRows >= MAX_ROWS && numCols >= MAX_COLS );
}
bool MatrixType::InactiveElement () const{
    return (numRows == 0 && numCols == 0 );
}
MatrixType MatrixType::operator +(const MatrixType otherOperand){
    MatrixType result;
    result.SetSize(numRows, numCols);
    if(AddSubCompatible(otherOperand)){
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                result.values[i][j] = values[i][j] + otherOperand.values[i][j];
            }
        }
    }
    return result;
}
MatrixType MatrixType::operator -(const MatrixType otherOperand){
    MatrixType result;
    result.SetSize(numRows, numCols);
    if(AddSubCompatible(otherOperand)){
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                result.values[i][j] = values[i][j] - otherOperand.values[i][j];
            }
        }
    }
    else
        cout << "Not Compatible" << endl;
    return result;
}
MatrixType MatrixType::operator *(const MatrixType otherOperand){
    MatrixType result;
    result.SetSize(numRows, otherOperand.numCols);
    if (MultCompatible(otherOperand)){
        for (int i = 0; i < numRows; i++){
            for ( int j = 0; j < otherOperand.numCols; j++){
                for( int m = 0; m < otherOperand.numRows; m++){
                    result.values[i][j] += (values[i][m] * otherOperand.values[m][j]);
                }
            }
        }
    }
    return result;
}
