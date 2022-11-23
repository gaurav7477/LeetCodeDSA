class Solution {
public:
    void bfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>>& grid){
        visited[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
       
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<int> rows = {0,0,1,-1};
            vector<int> cols = {1,-1,0,0};
            // traverse its neighbour mark them if it is island
            for(int k = 0;k<4;k++){
                int neigh_row = row + rows[k];
                int neigh_col = col + cols[k];
                if(neigh_row >= 0 && neigh_row < n && neigh_col >=0 && neigh_col < m && grid[neigh_row][neigh_col] == '1' && !visited[neigh_row][neigh_col]){
                        visited[neigh_row][neigh_col] = 1;
                        q.push({neigh_row,neigh_col});
                    }
                    
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        // create same viisited matrix
        vector<vector<int>> visited(n,vector<int>(m,0));
        // call bfs -> how many times call = ans
        for(int row = 0; row < n;row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == '1' && !visited[row][col]){
                    ans++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        return ans;
    }
};