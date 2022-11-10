class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int count = 1;
        for(int i = 0; i < s.length();i++){
            if(st.empty()){
                st.push({s[i],1});
                continue;
            }
            else if(st.top().first == s[i]){
                if(st.top().second == k-1){
                    for(int j = 0; j < k-1; j++){
                        st.pop();
                    }
                }
                else{
                    st.push({s[i],st.top().second+1});
                }
            }
            else if(st.top().first != s[i]){
                 st.push({s[i],1});
            }
           
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top().first;
            // cout<<str <<" "<<endl;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;   
    }
};