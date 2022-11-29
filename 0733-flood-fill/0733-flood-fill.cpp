class Solution {
public:
    void dfs(int iniColor,int row, int col, int color,vector<vector<int>> &visited,vector<vector<int>>&image,vector<int> newRow,vector<int> newCol){
        visited[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++){
            int rowNeigh = row + newRow[i];
            int colNeigh = col + newCol[i];
            
            if(rowNeigh >= 0 && rowNeigh < n && colNeigh >= 0 && colNeigh < m && image[rowNeigh][colNeigh] == iniColor && visited[rowNeigh][colNeigh] != color){
                visited[rowNeigh][colNeigh]  = color;
                dfs(iniColor,rowNeigh,colNeigh,color,visited,image,newRow,newCol);
            }
        }
        
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // dfs
        int iniColor = image[sr][sc];
        
        vector<vector<int>> visited = image;
        vector<int>newRow = {0,0,1,-1};
        vector<int>newCol = {1,-1,0,0};
        dfs(iniColor,sr,sc,color,visited,image,newRow,newCol);
        return visited;
    }
};