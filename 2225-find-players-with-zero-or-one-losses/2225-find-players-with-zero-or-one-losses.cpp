class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        
        unordered_map<int,pair<int,int>>win_lose;
        for(auto it : matches){
            win_lose[it[0]].first++;
            win_lose[it[1]].second++;
        }
        for(auto it : win_lose){
            if(it.second.second == 0) ans[0].push_back(it.first);
            if(it.second.second == 1) ans[1].push_back(it.first);
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};