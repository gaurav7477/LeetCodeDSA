class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int sum=0;
        int ans=1;
        int i=0,j=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            
            while((long long)nums[j]*(j-i+1) > k+sum){
                sum-=nums[i++];
            }
                
            
            ans=max(ans,j-i+1);
            
            j++;
        }
        return ans;
    }
};
