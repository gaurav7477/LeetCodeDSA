#include<bits/stdc++.h>
class Solution {
public:

     void solve(vector<int>nums, vector<int>output,int index, vector<vector<int>> &ans)
    {
        // base condition 
        if(index == nums.size())
        {
            sort(output.begin(),output.end());
            ans.push_back(output);
            return;
        }
        
        // exclude 
        solve(nums, output, index + 1, ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        
        int index = 0;
        
        solve(nums, output, index, ans);
        set<vector<int>> s;
        vector<vector<int>> f_ans;
                //cheking for duplicate vectors
        for(int i=0;i<ans.size();i++){
            if(s.find(ans[i])==s.end()){
                s.insert(ans[i]);
                f_ans.push_back(ans[i]);
            }
        }
        
        return f_ans;
    }
};