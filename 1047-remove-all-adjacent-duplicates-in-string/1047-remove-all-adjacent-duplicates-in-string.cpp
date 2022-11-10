class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i = 0; i < s.length();i++){
            st.push(s[i]);
            while(!st.empty() && st.top() == s[i+1]){
                st.pop();
                i++;
            }
           
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            // cout<<str <<" "<<endl;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;   
    }
};