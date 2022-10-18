class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        // Move left to right and fix
        for (int i = 1; i < n - 1; i++) {

            if (2*nums[i] == (nums[i-1] + nums[i+1]))
                swap(nums[i], nums[i+1]);
        }
        
        // Move right to left and fix
        for (int i = nums.size() - 2; i > 0; i--) {

            if (2*nums[i] == (nums[i-1] + nums[i+1]))
                swap(nums[i], nums[i-1]);
        }
        return nums;
        
    }
};