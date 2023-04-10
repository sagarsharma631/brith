//
//  main.cpp
//  SudokuSolver
//
//  Created by Sagar Sharma on 10/04/23.
//

#include "solver.hpp"
#include<vector>

#define SET_NUM(x, y) x & (1 << (y - 1))
#define GET_NUM(x, y)

using namespace std;

class Solution {
    int nums = 0;
    vector<vector<char>> solved{
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
    };
    
    void initData(vector<vector<char>>& board){
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                SET_NUM(board[i][j], board[i][j] - 48);
                //solved[i][j] = 1 << ( ( board[i][j] - 48 ) - 1 );
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        initData(board);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
