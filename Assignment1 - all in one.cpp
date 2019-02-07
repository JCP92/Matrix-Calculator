#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;
class MatrixType {
private:
    int **values;
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
    values = new int* [numRows];
    for ( int i = 0; i < numRows; ++i){
        values[i] = new int [numCols];
    }
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
void MatrixType::Print(ofstream& 
                       ) const{
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




int main()
{
    using namespace std;
    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output
    string inFileName;     // input file external name
    string outFileName;    // output file external name
    string outputLabel;
    string command, second;        // operation to be executed
    int numCommands;
    MatrixType M[10]; // set the matrix array for multiple matricies
    
    inFile.open("MatrixDriver.txt"); // call driver prog
    if(inFile.is_open()) // verification the document opened
        cout << "File Opened Success" << endl;
    else
        cout << "fail" << endl;
    
    outFile.open(inFileName);
    if(outFile.is_open())
        cout << "Success" << endl;
    else
        cout << "fail" << endl;
    
    cout << "Enter name of test run; press return." << endl;
    cin  >> outputLabel;
    outFile << outputLabel << endl;
    
    inFile >> command; // executible command
    numCommands = 0;
    while (command != "Quit")
    {
        cout << command << endl;
        if (command == "GetNewMatrix")
        {
            int row, column, element;
            inFile >> element;
            inFile  >> row;
            inFile  >> column;
            
            M[element].SetSize(row, column);
            for (int i = 0; i < row; i++){
                for (int j = 0; j < column; j++){
                    int item;
                    inFile >> item;
                    M[element].StoreItem(item, i, j);
                }
            }
            M[element].PrintMatrix();
            cout << endl;
            
        }
        else if(command == "AddMatricies"){
            int element1, element2, result;
            inFile >> element1;
            inFile >> element2;
            inFile >> result;
            
            if (M[element1].AddSubCompatible(M[element2])){
                M[result].SetSize(M[element1].getRow(), M[element1].getCols());
                M[element1].Add(M[element2], M[result]);
                M[result].PrintMatrix();
                M[result].MakeEmpty();
                cout << "Cleared Matrix" << endl << endl;
            }
            else
                cout << "Not Compatible. " << endl << endl;
        }
        else if(command == "SubMatricies"){
            int element1, element2, result;
            inFile >> element1;
            inFile >> element2;
            inFile >> result;
            
            if (M[element1].AddSubCompatible(M[element2])){
                M[result].SetSize(M[element1].getRow(), M[element1].getCols());
                M[element1].Sub(M[element2], M[result]);
                M[result].PrintMatrix();
                M[result].MakeEmpty();
                cout << "Cleared Matrix" << endl << endl;
            }
            else
                cout << "Not Compatible. " << endl << endl;
        }
        else if(command == "MultMatricies"){
            int element1, element2, result;
            inFile >> element1;
            inFile >> element2;
            inFile >> result;
            
            if (M[element1].MultCompatible(M[element2])){
                M[result].SetSize(M[element1].getRow(), M[element2].getCols());
                M[element1].Mult(M[element2], M[result]);
                M[result].MakeEmpty();
                cout << "Cleared Matrix" << endl << endl;
            }
            else
                cout << "Not Compatible. " << endl << endl;
        }
        else if (command == "PrintMatrix"){
            int element;
            inFile >> element;
            if(!M[element].InactiveElement() && element < MAX_COLS){
                M[element].Print(outFile);
            }
        }
        numCommands++;
        cout << "Command number " << numCommands << " completed." << endl;
        inFile >> command;
    }
    M[9] = M[1] + M[0]; //operator overlaoding
    M[9].PrintMatrix();
    cout << endl;
    M[9] = M[1] - M[0];
    M[9].PrintMatrix();
    M[9] = M[4] * M[5];
    M[9].PrintMatrix();
    cout << "\nTesting completed."  << endl << endl;
    return 0;
}






