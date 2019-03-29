#include <iostream>
#include <vector>
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        display2dVector(board);
        std::cout <<"------------\n";
        std::vector<std::vector<bool>> rowTrueMatrix;//matrix to see if rows are true
        std::vector<std::vector<bool>> colTrueMatrix;//matrix to see if colums are true
        int rowndx = 0;
        int ndx =0;
        bool rowsValid = true;
        bool colsValid = true;
        int tmpRow[board.size()];
        for(auto itr = board.begin(); itr != board.end(); itr++){
            ndx = itr - board.begin();
            std::vector<bool> row;
            std::vector<bool> col;

            for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){

                rowndx = std::distance(itr->begin(),itr2);
                row.push_back(isUniqueRow(rowndx,*itr2,board[ndx]));
                col.push_back(isUniqueCol(ndx,*itr2,board));

            }
            colTrueMatrix.push_back(col);
            rowTrueMatrix.push_back(row);
        }
        std::cout <<"---ROWS VECTOR ---\n";
        display2dVectorbool(rowTrueMatrix);
        std::cout <<"---COLS VECTOR ---\n";
        display2dVectorbool(colTrueMatrix);
        return true;
    }
    bool isUniqueRow(int ndx,char x,std::vector<char> & row){
        int i = 0;
        for(auto itr = row.begin(); itr != row.end(); itr++){
            i = itr - row.begin();
            if(x == *itr && i != ndx){
                if(x != '.'){
                    return false;
                }
            }
        }
        return true;
    }
    bool isUniqueCol(int ndx,char x,std::vector<std::vector<char>> & row){

        if(x == '.')
            return true;

        std::vector<char> col;
        for(auto itr = row.begin(); itr != row.end(); itr++){
            int ndx2 = itr - row.begin();
            col.push_back(itr->at(ndx));
        }

        for(auto itr3 = col.begin(); itr3 != col.end();itr3++){
            int i = std::distance(col.begin(),itr3);
            if(*itr3 == x ){
                if(ndx != i ){
                    std::cout <<"ITR3 VALUE : "<< *itr3 << "\n";
                    std::cout <<"NDX VALUE : "<< ndx << "\n";
                    std::cout <<"i VALUE : "<< i << "\n";
                    return false;
                }

            }


        }

        return true;
    }


    void display2dVector(std::vector<std::vector<char>>& board){
        for(auto itr = board.begin(); itr != board.end(); itr++){
            for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
                std::cout << *itr2;
            }
            std::cout << "\n";
        }
    }
    void display2dVectorbool(std::vector<std::vector<bool>>& board){
        for(auto itr = board.begin(); itr != board.end(); itr++){
            for(auto itr2 = itr->begin(); itr2 != itr->end(); itr2++){
                std::cout << *itr2;
            }
            std::cout << "\n";
        }
    }
    void displayVector(std::vector<char>& board){
        for(auto itr = board.begin(); itr != board.end(); itr++){
            std::cout << *itr;
        }
        std::cout << "\n";
    }
    void displayVectorbool(std::vector<bool>& board){
        for(auto itr = board.begin(); itr != board.end(); itr++){
            std::cout << *itr;
        }
        std::cout << "\n";
    }

};
int main() {
    Solution answer;
    std::vector<std::vector<char>> board {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };

    answer.isValidSudoku(board);
    return 0;
}