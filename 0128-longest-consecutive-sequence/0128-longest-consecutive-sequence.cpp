class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest_sequences = 0;
        for(auto &num : s){
            // if element's left number is not present in the set means sequences should be start from here
            if(!s.count(num-1)){
                int length = 1;
                while(s.count(num + length)){
                    ++length;
                }
                longest_sequences = max(longest_sequences,length);
            }
        }
        return longest_sequences;
    }
     
};