class Solution {
public:

    int dp[1000 + 1][1000 + 1];
    // memoization code ->> TLE
    int solve(string &text1, string &text2,int n,int m){
        // base condition => smallest valid input
        if(n == 0 || m == 0) return 0;
        
        // memoization code
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        if(text1[n-1] == text2[m-1]){
            dp[n][m] =  1 + solve(text1,text2,n-1,m-1); 
        }
        else{
            dp[n][m] =  max(solve(text1,text2,n-1,m),solve(text1,text2,n,m-1));
        }
        return dp[n][m];
    }
    
//         // dp code ->> ACCEPTED
//     int solve(string text1, string text2,int n,int m){
        
//         int dp[n+1][m+1];
        
//         // initialization => smallest valid input
//         for(int i =0;i<n+1;i++){
//             for(int j =0;j<m+1;j++){
//                 if(i == 0) dp[i][j] = 0;
//                 if(j == 0) dp[i][j] = 0;
//             }
//         }
        
//         // dp code
//         for(int i =1;i<n+1;i++){
//             for(int j =1;j<m+1;j++){
//                 if(text1[i-1] == text2[j-1]){
//                     dp[i][j] =  1 + dp[i-1] [j-1];
//                 }
//                 else{
//                     dp[i][j] =  max(dp[i-1] [j],dp[i] [j-1]);
//                 }
//             }
//         }
      
        // return dp[n][m];
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        memset(dp,-1,sizeof(dp));
        return solve(text1,text2,n,m);     
    }
};