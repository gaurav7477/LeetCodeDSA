class Solution {
public:
   
    void solve(string s, int i, string temp, vector<string> &ans){
    
    // Base case
    if(i == s.length()){
        ans.push_back(temp);
        return;
    }
    
    if(s[i] >= '0' && s[i] <= '9'){
        temp.push_back(s[i]);
        solve(s, i+1, temp, ans);
    }
    else{
        temp.push_back(tolower(s[i]));
        solve(s, i+1, temp, ans);
        
        // backtrack
        temp.pop_back();
        
        temp.push_back(toupper(s[i]));
        solve(s, i+1, temp, ans);
    }
}

    
    vector<string> letterCasePermutation(string s) {
        
        vector<string>ans;
        
        solve(s, 0, "", ans);
        
        return ans;
        
    }
    
};