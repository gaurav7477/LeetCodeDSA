class Solution {
public:
    
    // recursive code
//     int solve(string text1, string text2,int n,int m){
//         // base condition => smallest valid input
//         if(n == 0 || m == 0) return 0;
        
//         // recursive code
//         if(text1[n-1] == text2[m-1]){
//             return 1 + solve(text1,text2,n-1,m-1); 
//         }
//         else{
//             return max(solve(text1,text2,n-1,m),solve(text1,text2,n,m-1));
//         }
//     }
    
//     // memoization code
//     int solve(string text1, string text2,int n,int m){
        
//         int dp[1002][1002];
//         memset(dp,-1,sizeof(dp));
//         // base condition => smallest valid input
//         if(n == 0 || m == 0) return 0;
        
//         // memoization code
//         if(dp[n][m] != -1){
//             return dp[n][m];
//         }
//         if(text1[n-1] == text2[m-1]){
//             dp[n][m] =  1 + solve(text1,text2,n-1,m-1); 
//         }
//         else{
//             dp[n][m] =  max(solve(text1,text2,n-1,m),solve(text1,text2,n,m-1));
//         }
//         return dp[n][m];
//     }
    
        // dp code
    int solve(string text1, string text2,int n,int m){
        
        int dp[n+1][m+1];
        
        // initialization => smallest valid input
        for(int i =0;i<n+1;i++){
            for(int j =0;j<m+1;j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 0;
            }
        }
        
        // dp code
        for(int i =1;i<n+1;i++){
            for(int j =1;j<m+1;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] =  1 + dp[i-1] [j-1];
                }
                else{
                    dp[i][j] =  max(dp[i-1] [j],dp[i] [j-1]);
                }
            }
        }
      
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        return solve(text1,text2,n,m);     
    }
};