class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        int third = INT_MAX;
        
        for(int i = 0;i < nums.size();i++){
            int curr = nums[i];
            if(curr < first){
                first = curr;
            }
            else if(curr < second && curr > first){
                second = curr;
            }
            else if(curr > second){
                third = curr;
                return true;
            }
        }
        return false;
    }
};