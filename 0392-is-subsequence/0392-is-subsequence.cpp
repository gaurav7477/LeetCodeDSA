class Solution {
public:
    int lcs(string str1, string str2,int n,int m){
        // base condition
        int dp[n+1][m+1];
        for(int i = 0; i < n+1; i++){
            for (int j = 0; j< m+1;j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < n+1; i++){
            for (int j = 1; j< m+1;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n][m];
    }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int len_lcs = lcs(s,t,n,m);
        if(len_lcs == n) return true;
        return false;
    }
};