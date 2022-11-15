class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        int prefixProduct = 1;
        for(int i = 0; i < nums.size();i++){
            result[i] = prefixProduct;
            prefixProduct *= nums[i];
        }
        
        int postfixProduct = 1;
        for(int i = nums.size()-1; i >= 0;i--){
            result[i] *= postfixProduct;
            postfixProduct *= nums[i];
        }
        
        return result;
    }
};