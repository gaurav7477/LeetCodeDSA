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
        int grid_row = (row/3)*3;
        int grid_col = (col/3)*3;
        for(int x=grid_row;x<grid_row+3;x++){
            for(int y = grid_col;y<grid_col+3;y++){
                   if(board[x][y]==num){
                        return false;
                }
                
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
