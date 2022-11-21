class Solution {
public:
    bool isvalid(int n,int m,int row,int col){
        
        if(row>=0 && row<n && col>=0 && col<m){
            return true;
        }
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n=maze.size();
        int m=maze[0].size();

        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});  
        
        maze[entrance[0]][entrance[1]]='+';

        int steps = 0;
        
        while(!q.empty())
        {
            int q_size = q.size();
            while(q_size--){
            
                pair<int,int>p = q.front();
                q.pop();

                int i = p.first;  
                int j = p.second; 
              
                if((i==0 || j==0 || i==n-1 || j==m-1)){
                    if((i!=entrance[0] || j!=entrance[1])){
                        return steps;
                    }
                }

                if(isvalid(n,m,i+1,j) && maze[i+1][j]!='+'){
                    maze[i+1][j]='+';
                    q.push({i+1,j});
                }
                if(isvalid(n,m,i-1,j) && maze[i-1][j]!='+'){
                    maze[i-1][j]='+';
                    q.push({i-1,j});
                }
                if(isvalid(n,m,i,j+1) && maze[i][j+1]!='+'){
                    maze[i][j+1]='+';
                    q.push({i,j+1});
                }
                if(isvalid(n,m,i,j-1) && maze[i][j-1]!='+'){
                    maze[i][j-1]='+';
                    q.push({i,j-1});
                }
            }
            steps++;
        }
        
        
        return -1;
    }
    
    
    
};