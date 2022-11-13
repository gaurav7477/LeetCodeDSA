class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return " ";
       stack<string>st;
        
        for(int i = 0; i<s.length();i++){
            string words;
            if(s[i] == ' ') continue;
            while(i < s.size() && s[i] != ' ')
            {
                words += s[i];
                i++;
            }
            st.push(words);
        }
        
        string ans;
        while(!st.empty()){
            ans += st.top();
             st.pop();
            if(!st.empty()){
                 ans += ' ';
            }
        }
        return ans;
    }
};