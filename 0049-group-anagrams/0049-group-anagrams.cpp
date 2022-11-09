class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        // aet  ->> eat,tea,ate
        vector<vector<string>>ans;
        
        for(int i = 0;i < strs.size();i++){
            string s = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(s);
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};