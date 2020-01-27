/*

AUTHOR - SAGAR SHARMA 

DATE CREATED(DD/MM/YYYY) - 26/01/2020 

Question - 

There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at the top-left corner

and getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:

Right, then down

Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.

*/

#include<iostream>
#include<queue>
#include<map>

using namespace std;

namespace util{
    enum MatrixState{
        MATRIX_INVALID = 0,
        MATRIX_ROW_SET,
        MATRIX_COL_SET,
        MATRIX_INIT_DONE,
        MATRIX_END_STATE,
    };
    class Matrix{
        private:
        int m_rows;
        int m_cols;
        bool isInitDone;
        enum MatrixState m_currState;
        // Initializes the matrix
        void init(){

        }
        public:
        Matrix(int rows = 0, int cols = 0):m_rows(rows),m_cols(cols){
            if((rows == 0) || (cols == 0)){
                // do not do anything
                m_currState = MATRIX_INVALID;
            }
            else{
                init();
            }
        }
        ~Matrix(){

        }
        int getRows() const{
            return m_rows;
        }
        int getCols() const{
            return m_cols;
        } 
        bool setRows(int rows){
            bool retVal = false;
            // If the rows have already been set than do not reset the rows.
            if(m_currState < MatrixState::MATRIX_ROW_SET){
                m_rows = rows;
                retVal = true;
            }
            return retVal;
        }
        bool setCols(int cols){
            bool retVal = false;
            // If the cols have already been set than do not reset the rows.
            if(m_currState < MatrixState::MATRIX_COL_SET){
                m_cols = cols;
                retVal = true;
            }
            return retVal;
        }
        enum MatrixState getState() const{
            return m_currState;
        }
    };
};

bool isInBounds(const util::Matrix &ref, const pair<int,int> &cellNo){
    bool retVal = false;
    if(cellNo.first <= ref.getRows()-1 && cellNo.second <= ref.getCols()-1){
        retVal = true;
    }
    return retVal;
}

int calcWays(const util::Matrix &matrix){
    int retVal = 0;
    map<pair<int,int>,int> waysMap;
    queue<pair<int,int>> nodeQ;
    nodeQ.push(make_pair(0,0));
    while(!nodeQ.empty()){
        pair<int,int> temp = nodeQ.front();
        ++waysMap[temp];
        nodeQ.pop();
        // check down node is inBounds or not.
        if(isInBounds(matrix,make_pair(temp.first+1,temp.second))){
            nodeQ.push(make_pair(temp.first+1,temp.second));
        }
        // check right node is inBounds or not.
        if(isInBounds(matrix,make_pair(temp.first,temp.second+1))){
            nodeQ.push(make_pair(temp.first,temp.second+1));
        }
    }
    retVal = waysMap[make_pair(matrix.getRows()-1,matrix.getCols()-1)];
    return retVal;
}

int main(int argc, char *argv[]){
    util::Matrix obj(5,5);
    cout<<calcWays(obj)<<endl;
    return 0;
}
