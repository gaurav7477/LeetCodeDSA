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
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int length_lcs = lcs(word1,word2,n,m);
        // if(n>m){
        //     return n-length_lcs;
        // }
        // else if(m>n){
        //     return m-length_lcs;
        // }
	    int insertion = m - length_lcs;
	    int deletion = n - length_lcs;
	    int ans = insertion + deletion;
	    // return 2*(m-length_lcs);
        return ans;
    }
};