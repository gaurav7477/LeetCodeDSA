class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        vector<int>ans;
        list<int>cal;
        
        while(j < nums.size()){
            if(nums[j] > cal.back()){
                while(cal.size() > 0 && nums[j] > cal.back()){
                    cal.pop_back();
                }
            }
           
            cal.push_back(nums[j]);
            if(j - i + 1 < k){
                j++;
            }
            else if(j - i + 1 == k){
                
                ans.push_back(cal.front());
                if(nums[i] == cal.front()){
                    cal.pop_front();
                }
                i++;
                j++;
            }
            
        }
        return ans;
    }
};