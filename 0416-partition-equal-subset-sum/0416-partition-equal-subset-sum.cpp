class Solution {
public:
    
    // memoization
    // int dp[201][20001];
    bool solve(vector<int> &nums, int n, int sum)
    {
//         if (sum == 0)
//             return 1;
//         if (n == 0 && sum > 0)
//             return 0;
//         if (dp[n][sum] != -1)
//             return dp[n][sum];
        
//         if (nums[n-1] > sum)
//             return dp[n][sum] = solve(nums, n-1, sum);
//         else
//             return dp[n][sum] = solve(nums, n-1, sum) || solve(nums, n-1, sum-nums[n-1]);
//     }
    
    // DP solution
        bool t[n+1][sum+1];
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+ 1;j++){
                if(i == 0) t[i][j] = false;
                if(j == 0) t[i][j] = true;
                
            }
        }
        
          for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
                } else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
     
    }
    bool canPartition(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        int sum = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        else return solve(nums,n,sum/2);
        
    }
};