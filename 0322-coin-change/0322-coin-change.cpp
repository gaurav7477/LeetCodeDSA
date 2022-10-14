class Solution {
public:
    int solve(vector<int>& coins,int n,int amount) {
        int dp[n+1][amount+1];
        
        for(int i =0;i<n+1;i++){
            for(int j = 0;j<amount+1;j++){
                if(i == 0) dp[i][j] = INT_MAX-1;
                if(j == 0) dp[i][j] = 0;
                // secon row initialization
                if(j == 1){
                    if(j % coins[0] == 0) {
                        dp[i][j] = j/coins[0];
                    }
                    else{
                        dp[i][j] = INT_MAX-1;
                    }
                }
                
            }
        }
        
         for(long i =1;i<n+1;i++){
            for(long j = 1;j<amount+1;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                    
                }
                else{
                   dp[i][j] = dp[i-1][j];  
                }
            }
        }
        
        return dp[n][amount] == (INT_MAX-1)? -1 : dp[n][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        long ans = solve(coins,n,amount);
        
        return ans;
        
        
    }
};