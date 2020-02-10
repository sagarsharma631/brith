/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 10/02/2020

This class is abstracts the normal 2D array, this will be use full when passing 2D arrays to a function.

*/
#include<iostream>

using namespace std;

class Matrix{
  private:
  int **m_ptr;
  int m_rows;
  int m_cols;
  public:
  // Rows and Cols cannot be changed once the constructor is called.
  Matrix(int row = 3, int column = 3){
      m_ptr = new int*[column];
      for(int i=0;i<column;i++){
          m_ptr[i] = new int[row];
      }
  }
  
  int getRows() const{
    return m_rows;
  }
  
  int getCols() const{
    return m_cols;
  }
  
  int* operator[](int index);
  
  // Need to properly clean the stuff. No memory leaks should be present.
  ~Matrix(){
  }
  
  protected:
  
};

// Overloading for accessing our matrix.
int* Matrix::operator[](int index){
    return m_ptr[index];
}

#ifdef DEBUG
int main(int argc, char *argv[]){
    Matrix mat(4,5);
    for(int i = 0;i < 4;i++){
        for(int j=0;j < 5;j++){
            mat[i][j] = i*j;
        }
    }
    
    cout<< mat[3][3]<<endl;
    
    return 0;
}
#endif
