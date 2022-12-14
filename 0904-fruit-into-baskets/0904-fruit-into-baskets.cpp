class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i=0, j=0;
        
        
        
        int mx=0;
        int k = 2;
        
        while(j<fruits.size()){
            mp[fruits[j]]++;
            
            if(mp.size()<k){
                mx=max(mx, j-i+1);
                j++;
            }else if(mp.size()==k){
                mx=max(mx, j-i+1);
                j++;
            }else{
                while(mp.size()>k){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                        mp.erase(fruits[i]);
                    
                    i++;
                }
                j++;
            }
        }
        
        return mx;
        
    }
};