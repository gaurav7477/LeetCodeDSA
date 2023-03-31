//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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
    int numProvinces(vector<vector<int>> adj, int V) {
        int n = adj.size();
        
        vector<int>vis(n,0);
        vector<int>adj_list[n];
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(adj[i][j] == 1 && i != j){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,adj_list);
            }
                
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends