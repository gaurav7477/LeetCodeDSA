class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //source 
        int s=0;
        //size of the graph
        int n=graph.size()-1;
        //to store path
        vector<int>path;
        path.push_back(s);
        //ans vector
        vector<vector<int>>ans;
        
        //creating queue for bfs traversal
        queue<vector<int>>q;
        q.push(path);
        while(!q.empty()){
            path=q.front();
            q.pop();
            
            int val=path.back();
            //checking if we have reached to our destination or not
            if(val==n){
                //if we are at our destination means 
                //this is a valid path between source and destination.
                ans.push_back(path);
            }
            for(int &i:graph[val]){
                vector<int>v(path);
                v.push_back(i);
                q.push(v);
            }
        }
        return ans;
    }
};