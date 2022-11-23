//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
            // traverse its neighbour mark them if it is island
            for(int detrow = -1;detrow <= 1;detrow++){
                for(int detcol = -1;detcol <= 1;detcol++){
                    int neigh_row = row + detrow;
                    int neigh_col = col + detcol;
                    if(neigh_row >= 0 && neigh_row < n && neigh_col >=0 && neigh_col < m && grid[neigh_row][neigh_col] == '1' && !visited[neigh_row][neigh_col]){
                            visited[neigh_row][neigh_col] = 1;
                            q.push({neigh_row,neigh_col});
                    }
                }
                    
            }
            
        }
    }
  
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends