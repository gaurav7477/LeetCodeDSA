class Solution {
public:
     int solve(const vector<int> &piles, int k)
    {
        int h = 0;
        if(k == 0) return INT_MAX;
        for(int i : piles)
        {
            if(i % k != 0)
            {
                h++;
            }
            h += (i / k);
        }
        return h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int range = INT_MIN;
        int ans;
        long long sum = 0;
        for(int i = 0;i<piles.size();i++){
            sum += piles[i];
            if(range < piles[i])
                range = piles[i];
        }
        int left = sum/h;;
        int right = range;
        while(left < right){
            int mid = left + (right - left)/2;
            ans = solve(piles,mid);
            
            if(ans > h){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};