class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp1;
        string ans = "";
        for(int i = 0; i < s.size();i++){
            mp1[s[i]]++;
        }
        priority_queue<pair<int,char>>mx_heap;
        
        for(auto it: mp1){
            mx_heap.push({it.second,it.first});
        }
        
        while(!mx_heap.empty()){
            int t = mx_heap.top().first;
            while(t--){
                ans += mx_heap.top().second;
            }
            
            mx_heap.pop();
        }
        return ans;
    }
};