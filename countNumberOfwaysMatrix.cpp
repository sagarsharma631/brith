#include<iostream>
#include<queue>

using namespace std;

template<typename T>
class matrix{
    private:
    int m_rows;
    int m_cols;
    T **mainPtr;
    void initMatrix();
    
    public:
    matrix(int rows = 3, int cols = 3){
        m_rows = rows;
        m_cols = cols;
        initMatrix();
    }
    matrix(const matrix &other){
        this->m_rows = other.m_rows;
        this->m_cols = other.m_cols;
        initMatrix();
    }
    int getRows() const;    // returns the number of rows
    int getCols() const;    // returns the number of columns
    T* operator[](int rowIndex);
    void setRows(int rows);
    void setCols(int cols);
    
    protected:
};

template<typename T>
T* matrix<T>::operator[](int rowIndex){
    return mainPtr[rowIndex];
}

template<typename T>
void matrix<T>::initMatrix(){
    mainPtr = new T*[m_rows];
    for(int i=0;i<m_rows;++i){
        mainPtr[i] = new T[m_cols];
    }
    return;
}

template<typename T>
int matrix<T>::getCols() const{
    return m_cols;
}

template<typename T>
int matrix<T>::getRows() const{
    return m_rows;
}

template<typename T>
void matrix<T>::setRows(int rows){
    m_rows = rows;
    return;
}

template<typename T>
void matrix<T>::setCols(int cols){
    m_cols = cols;
    return;
}

void initQueryGrid(matrix<int> &myMatrix, bool isDPMatrix = false){
    for(int i=0;i<myMatrix.getRows();++i){
        for(int j = 0;j<myMatrix.getCols();++j){
            myMatrix[i][j] = 0;
            if((i == 1 && j ==1) || (i == 2 && j == 0) && !isDPMatrix){
                myMatrix[i][j] = -1;
            }
            else{
                myMatrix[i][j] = 0;
            }
        }
    }
}

void createDPMatrix(matrix<int> &dpMatrix, const matrix<int> &other){
    dpMatrix.setRows(other.getRows());
    dpMatrix.setCols(other.getCols());
}

int calculatePath(const matrix<int> &queryGrid, matrix<int> &dpMatrix){
    std::queue<pair<int,int>> travQ;
    int i = 0;
    int j = 0;
    dpMatrix[0][0] = 1;
    while(i != queryGrid.getRows() - 1 && j != queryGrid.getCols() - 1){
        if(dpMatrix[i+1][j] != -1){
            travQ.push(pair<int,int>(i+1,j));
        }
        if(dpMatrix[i+1][j] != -1){
            travQ.push(pair<int,int>(i,j+1));
        }
    }
    return 5;
}

int main(int argc, char *argv[]){
    // Obstacles are kept at (1,1) and (2,0)
    matrix<int> myMatrix(4,4);
    initQueryGrid(myMatrix);    
    matrix<int> dpMatrix;
    initQueryGrid(dpMatrix, true);
    calculatePath(myMatrix, dpMatrix);
    return 0;
}
