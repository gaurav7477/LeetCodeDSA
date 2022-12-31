class Solution {
public:
  
    int solve(vector<vector<int>>& og,int i,int j){
        if(i<0 || i>= og.size() || j<0 || j>= og[0].size()) return 0;
        if(og[i][j]==2){
            og[i][j]=-1;
            for(int k=0;k<og.size();k++){
                for(int l=0;l<og[0].size();l++){
                    if(og[k][l]!=-1){
                        og[i][j]=2;
                        return 0;
                    }
                }
            }
            og[i][j]=2;
            return 1;
        }
        int count1=0,count2=0,count3=0,count4 = 0;
      
        if(og[i][j] == 0 || og[i][j]==1){
           og[i][j]=-1;
           count1 = solve(og,i+1,j);
           count2 = solve(og,i,j+1);
           count3 = solve(og,i-1,j);
           count4 = solve(og,i,j-1);
           og[i][j]=0;
           
        }
        return  count1 + count2 + count3 + count4;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return solve(grid,i,j);
                }
            }
        }
        return 0;
    }
};