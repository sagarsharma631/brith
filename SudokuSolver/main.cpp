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
    int rows;
    int cols;
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
    
    void applyNakedSingle(vector<vector<char>>& board){
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

    void applyLockedCandidateUtil(vector<vector<char>>& board, short int** tempSudoku, int xStart, int yStart){
        short int xEnd = xStart + 3;
        short int yEnd = yStart + 3;
        
        unordered_map<short int, pair <short int, pair<short int, short int> > > freqMap;
        for(int i=xStart;i<xEnd;++i){
            for(int j=yStart;j<yEnd;++j){
                if(board[i][j] != '.'){
                    tempSudoku[i][j] |= rowVec[i];
                    tempSudoku[i][j] |= colVec[j];
                    tempSudoku[i][j] |= boxVec[i/3][j/3];
                    for(int index=0;index<9;++index){
                        if((tempSudoku[i][j] & 1) == 0){
                            freqMap[index+1].first += 1;
                            freqMap[index+1].second = make_pair(i, j);
                        }
                        tempSudoku[i][j] >>= 1;
                    }
                }
            }
        }
        
        for(int i=0;i<9;++i){
            char num = 48 + i + 1;
            if(freqMap[i+1].first == 1){
                board[freqMap[i+1].second.first][freqMap[i+1].second.second] = num;
                rowVec[freqMap[i+1].second.first] |= ((1 << (board[freqMap[i+1].second.first]
                                                             [freqMap[i+1].second.second] - 48 - 1)));
                colVec[freqMap[i+1].second.second] |= ((1 << (board[freqMap[i+1].second.first]
                                                              [freqMap[i+1].second.second] - 48 - 1)));
                boxVec[freqMap[i+1].second.first/3][freqMap[i+1].second.second/3] |= ((1 << (board[freqMap[i+1].second.first] [freqMap[i+1].second.second] - 48 - 1)));
            }
        }
    }
    
    void applyLockedCandidate(vector<vector<char>>& board){
        short int** tempSudoku = new short int*[rows];
        for(int i=0;i<rows;++i){
            tempSudoku[i] = new short int[cols]{0};
        }
        short int boxXStart = 0;
        short int boxYStart = 0;
        for(int i=0;i<9;++i){
            applyLockedCandidateUtil(board,tempSudoku, boxXStart, boxYStart);
            boxYStart += 3;
            if(boxYStart > 8){
                boxXStart += 3;
                boxYStart = 0;
            }
        }
        return;
    }

    /*void applyBackTracking(vector<vector<char>>& board){
    
    }*/

public:

    void solveSudoku(vector<vector<char>>& board) {
        rows = (int)board.size();
        cols = (int)board[0].size();
        initData(board);
        // Now the row, column and box vectors have been initialized. Start applying the optimization.

        // 1. Apply Naked Single Optimization
        applyNakedSingle(board);
#ifdef DEBUG_DISPLAY
        displaySudoku(board);
#endif
        // 2. Apply Locked Candidate Optimization
        applyLockedCandidate(board);
    
        // 3. After both the optimizations, fall back to backtracking
        //applyBackTracking(board);
        
        return;
    }

    // Utility to display sudoku
    void displaySudoku(const vector<vector<char>>& board) const{
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
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
    });
    
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
    });*/

    ({
    {'.','7','.',  '.','6','.',  '.','.','.'},
    {'6','.','.',  '.','.','3',  '.','4','1'},
    {'9','.','3',  '5','.','.',  '.','6','.'},
     
    {'3','.','.',  '9','4','.',  '.','7','.'},
    {'.','.','4',  '.','2','.',  '3','.','.'},
    {'.','9','.',  '.','3','8',  '.','.','4'},
        
    {'.','2','.',  '.','.','6',  '7','.','5'},
    {'8','3','.',  '1','.','.',  '.','.','6'},
    {'.','.','.',  '.','5','.',  '.','8','.'}
    });
    Solution obj;
    obj.solveSudoku(board);
    obj.displaySudoku(board);
    return 0;
}
