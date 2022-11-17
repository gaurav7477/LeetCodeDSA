class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int i=0;
        int ans = 0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        while(i<nums.size()){
            sum += nums[i];
            
            int x = sum - k;
            if(mpp.find(x) != mpp.end()){
                ans += mpp[x];
            }
            mpp[sum]++;
            i++;
        }
        return ans;
    }
};