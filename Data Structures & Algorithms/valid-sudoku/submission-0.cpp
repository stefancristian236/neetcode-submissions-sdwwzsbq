class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> rows;
        std::vector<std::unordered_set<char>> columns;

        for (size_t i = 0; i < 9; ++i) {
            std::unordered_set<char> aux;
            for (size_t j = 0; j < 9; ++j) {
                if (board[i][j] == '.'){
                    continue;
                }
                if (!aux.insert(board[i][j]).second){
                    return false;
                }
            }
            rows.push_back(aux);
            aux.clear();
        }

        for (size_t i = 0; i < 9; ++i) {
            std::unordered_set<char> aux;
            for (size_t j = 0; j < 9; ++j) {
                if (board[j][i] == '.'){
                    continue;
                }
                if (!aux.insert(board[j][i]).second){
                    return false;
                }
            }
            rows.push_back(aux);
            aux.clear();
        }

        for (size_t i = 0; i < 9; i += 3) {
            for (size_t j = 0; j < 9; j +=3 ) {
                std::unordered_set<char> cell;
                for (size_t cell_row = 0; cell_row < 3; cell_row++){
                    for (size_t cell_col = 0; cell_col < 3; cell_col++) {
                        if(board[i + cell_row][j + cell_col] == '.') {
                            continue;
                        } else {
                            if(!cell.insert(board[cell_row + i][cell_col + j]).second){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
