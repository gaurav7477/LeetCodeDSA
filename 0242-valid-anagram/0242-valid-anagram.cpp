class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if( t == s)
        //     return true;
        // else return false;
        unordered_map<char,int>mp;
        if(s.length() != t.length()) return false;
        for(int i = 0;i<s.length();i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for(auto i: mp){
            if(i.second) return false;
        }
        
        return true;
    }
};