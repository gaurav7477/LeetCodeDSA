class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int prefix_sum = 0;
        for(int i = 0; i < nums.size();i++){
            prefix_sum += nums[i];
            prefix_sum %= k;
            
            if(prefix_sum == 0 && i) return true;
            
            if(mp.find(prefix_sum) != mp.end()){
                if(i - mp[prefix_sum] > 1){
                    return true;
                }
            }
            else{
                mp[prefix_sum] = i;
            }
        }
        return false;
    }
};