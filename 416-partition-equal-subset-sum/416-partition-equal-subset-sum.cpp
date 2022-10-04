class Solution {
public:
    
    bool subsetSum(vector<int>& nums, int n,int sum){
        bool t[n + 1][sum + 1];
        
        // initialization ->> base condition
        
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
        int sum = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        else return subsetSum(nums,n,sum/2);
        
    }
};