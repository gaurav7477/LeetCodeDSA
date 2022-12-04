class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long mini_avg_diff = INT_MAX;
        long long prefix = 0;
        long long suffix = 0;
        long long range = 0;
        long long mini = INT_MAX;
        int index = 0;
        for(int i = 0; i < n;i++){
            range += nums[i];
        }
        long long sum = 0;
        for(int i = 0; i < n;i++){
            sum += nums[i];
            prefix = sum;
            if( i == n-1) {
                if(abs(prefix/(i+1) - 0) < mini){
                    mini = abs(prefix/(i+1) - 0);
                    index = i;  
                    break;
                }
                break;
                
            }
            suffix = range-sum;
            
            if(abs(prefix/(i+1) - suffix/(n-i-1)) < mini){
                mini = abs(prefix/(i+1) - suffix/(n-i-1));
                index = i;          
            }
        }
        return index;
        
    }
};