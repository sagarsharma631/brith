#include<iostream>

using namespace std;

class Matrix{
  private:
  int **m_ptr;
  public:
  Matrix(int row = 3, int column = 3){
      m_ptr = new int*[column];
      for(int i=0;i<column;i++){
          m_ptr[i] = new int[row];
      }
  }
  
  int* operator[](int index);
  
  protected:
  
};

int* Matrix::operator[](int index){
    return m_ptr[index];
}

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
