class Solution {
public:
    int row, col;

    int solve(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp){
        // base case
        if(x == row){
            return y;
        }

        // dp
        int &ans = dp[x][y];
        if(ans != -2){
            return ans;
        }

        if(grid[x][y] == 1){
            if(y+1<col and grid[x][y+1] == 1){
                return ans = solve(x+1,y+1,grid,dp);
            }
        }
        if(grid[x][y] == -1){
            if(y>0 and grid[x][y-1] == -1){
                return ans = solve(x+1,y-1,grid,dp);
            }
        }
        return ans = -1;        
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        row = grid.size();
        col = grid[0].size();

        vector<vector<int>>dp(row,vector<int>(col,-2));

        for(int i=0;i<col;i++){
            ans.push_back(solve(0,i,grid,dp));
        }
        return ans;
    }
};