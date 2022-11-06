class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string s1=s;
        int n=s.length();
        sort(s1.begin(),s1.end());
        char c=s1[0];
        vector<string>v;
        
        for(int i=0; i<n; i++){
            if(s[0]==c) v.push_back(s);
            char c1=s[0];
            s.erase(s.begin());
            s.push_back(c1);
        }
        sort(v.begin(),v.end());
        return v[0];
        
    }
};