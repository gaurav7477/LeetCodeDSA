class Solution {
public:
    void dfs(int node,vector<int>& visited,vector<int>adj_list[]){
        for(auto it: adj_list[node]){
            if(!visited[it]){
                visited[it] = 1;
                 dfs(it,visited,adj_list);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        vector<int>adj_list[n];
        
        // convert matrix into adjacency list
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
            
        }
        
        // start
        int count = 0;// how many times bfs call;
        for(int i = 0; i < n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj_list);
            }
        }
        return count;
    }
};