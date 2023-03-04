#include<iostream>
#include<vector>
#define validSudoku

using namespace std;

#ifdef validSudoku
class Solution {
#define SETMASK(mask, x) (1 << x-1) | mask
#define GETMASK(mask, x) (1 << x-1) & mask
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9]{0};
        int cols[9]{0};
        int sudBoxes[3][3]{0};
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j] != '.'){
                    if(GETMASK(rows[i], board[i][j]-48)) {
                        return false;
                    }
                    if(GETMASK(cols[j], board[i][j]-48)){
                        return false;
                    }
                    if(GETMASK(sudBoxes[i/3][j/3], board[i][j]-48)){
                        return false;
                    }
                    rows[i] = SETMASK(rows[i], board[i][j]-48);
                    cols[j] = SETMASK(cols[j], board[i][j]-48);
                    sudBoxes[i/3][j/3] = SETMASK(sudBoxes[i/3][j/3], board[i][j]-48);
                }
            }
        }
        return true;
    }
};
#endif

int main(int argc, char *argv[]){
    vector<vector<char>> sudoku({
        {'5','3','.','.','.','7','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    });
    Solution obj;
    obj.isValidSudoku(sudoku);
  return 0;
}
