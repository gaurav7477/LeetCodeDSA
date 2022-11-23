class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col){
        int num = board[row][col];
        board[row][col] = '.';
        // check for row
        for(int i = 0; i < 9; i++){
            if(board[row][i] == num) return false;
        }
        
         // check for column
        for(int i = 0; i < 9; i++){
            if(board[i][col] == num) return false;
        }
        
         // check for 3*3 matrix
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[row/3*3 + i][col/3*3 + j] == num)
                    return false;
            }
        }
        board[row][col] = num;
        return true;
        
     }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && !isValid(board,i,j)){
                    return false;
                }
            }
        }
        return true;
        
    }
};
