class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int second_max = INT_MIN;
        stack<int>st;
       
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < second_max ) return true;
            
            while( !st.empty() && nums[i] > st.top() ){ 
              second_max = st.top(); 
              st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;
    }
};