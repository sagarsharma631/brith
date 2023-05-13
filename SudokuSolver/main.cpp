//
//  main.cpp
//  SudokuSolver
//
//  Created by Sagar Sharma on 10/04/23.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    int rows = 9;
    int cols = 9;
    short int rowVec[9]{0};
    short int colVec[9]{0};
    short int boxVec[3][3]{0};
    
    void initData(vector<vector<char>>& board){
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] != '.'){
                    rowVec[i] = rowVec[i] | (1 << (board[i][j] - 48 - 1));
                    colVec[j] = colVec[j] | (1 << (board[i][j] - 48 - 1));
                    boxVec[i/3][j/3] = boxVec[i/3][j/3] | ((1 << (board[i][j] - 48 - 1)));
                }
            }
        }
    }

    bool tryPlacing(vector<vector<char>>& board, int rowIndex, int colIndex){
        short int mask = 0;
        mask |= rowVec[rowIndex];
        mask |= colVec[colIndex];
        mask |= boxVec[rowIndex/3][colIndex/3];
        short int found = 0;
        char num = '\0';
        for(int i = 0;i < 9;++i){
            if(found <= 1 && ((mask & 1) == 0)){
                found += 1;
                num = 48 + i + 1;
            }
            mask >>= 1;
        }
        if(found == 1){
            board[rowIndex][colIndex] = num;
            rowVec[rowIndex] |= ((1 << (board[rowIndex][colIndex] - 48 - 1)));
            colVec[colIndex] |= ((1 << (board[rowIndex][colIndex] - 48 - 1)));
            boxVec[rowIndex/3][colIndex/3] |= ((1 << (board[rowIndex][colIndex] - 48 - 1)));
            return true;
        }
        else{
            return false;
        }
    }
    
    void solveSudokuUtil(vector<vector<char>>& board){
        bool canContinue = true;
        while(canContinue){
            canContinue = false;
            for(int i = 0; i < rows; ++i){
                for(int j = 0; j < cols; ++j){
                    if(board[i][j] == '.'){
                        if(tryPlacing(board, i,j)){
                            canContinue = true;
                        }
                    }
                }
            }
        }
    }
    
public:
    
    void solveSudoku(vector<vector<char>>& board) {
        rows = (int)board.size();
        cols = (int)board[0].size();
        initData(board);
        solveSudokuUtil(board);
        return;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> board
    /*({
    {'5','3','.','.','7','.', '.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','.','.','.','.','.','.','6','.'},

    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    });*/
    
    ({
    {'.','.','9','7','4','8','.','.','.'},
    {'7','.','.','.','.','.','.','.','.'},
    {'.','2','.','1','.','9','.','.','.'},
     
    {'.','.','7','.','.','.','2','4','.'},
    {'.','6','4','.','1','.','5','9','.'},
    {'.','9','8','.','.','.','3','.','.'},
        
    {'.','.','.','8','.','3','.','2','.'},
    {'.','.','.','.','.','.','.','.','6'},
    {'.','.','.','2','7','5','9','.','.'}
    });
    Solution obj;
    obj.solveSudoku(board);
    return 0;
}
