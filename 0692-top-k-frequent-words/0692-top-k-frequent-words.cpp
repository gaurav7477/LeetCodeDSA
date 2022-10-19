class Solution {
public:
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        priority_queue <pair<int, string>, vector<pair<int, string>> ,MyComp> min_heap;
        // priority_queue< pair<int, string>, vector<pair<int, string>, greater<pair<int, string>>>> mx_heap;
        vector<string>s;
        
        for(auto i : words){
            mp[i]++;
        }
        for(auto i : mp){
            min_heap.push({i.second,i.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        
        while(!min_heap.empty()){
            s.insert(s.begin(),min_heap.top().second);
            min_heap.pop();
        }
        return s;
        
    }
};