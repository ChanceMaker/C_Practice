#include <iostream>
#include <vector>
class Solution {
public:
    const int BOARD_SIZE = 9;
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<char>> row_free(BOARD_SIZE,std::vector<char>(BOARD_SIZE+1,0));
        std::vector<std::vector<char>> col_free(BOARD_SIZE,std::vector<char>(BOARD_SIZE+1,0));
        std::vector<std::vector<char>> sq_free(BOARD_SIZE,std::vector<char>(BOARD_SIZE+1,0));

        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - 48;

                // store in row_free
                if(row_free[i][num] != 0) return false;
                else row_free[i][num] = 1;

                // store in col_free
                if(col_free[j][num] != 0) return false;
                else col_free[j][num] = 1;

                // store in sq_free
                if(sq_free[(i/3)*3+(j/3)][num] != 0) return false;
                else sq_free[(i/3)*3+(j/3)][num] = 1;
            }
        }

        return true;
    }
};
int main() {
    Solution answer;
    std::vector<std::vector<char>> board {
            {'.','.','.','.','5','.','.','1','.'},
            {'.','4','.','3','.','.','.','.','.'},
            {'.','.','.','.','.','3','.','.','1'},
            {'8','.','.','.','.','.','.','2','.'},
            {'.','.','2','.','7','.','.','.','.'},
            {'.','1','5','.','.','.','.','.','.'},
            {'.','.','.','.','.','2','.','.','.'},
            {'.','2','.','9','.','.','.','.','.'},
            {'.','.','4','.','.','.','.','.','.'}
    };

    std::cout <<"ANSWER = " <<answer.isValidSudoku(board);
    return 0;
}