class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jobDifficulty, int n, int idx, int d) {
        if(d == 1){
            int maxi = jobDifficulty[idx];
            for(int i = idx + 1; i < n; i++){
                maxi = max(maxi, jobDifficulty[i]);
            }
            return maxi;
        }
        if(t[idx][d] != -1)
            return t[idx][d];
    
        
        int maxi = INT_MIN;
        int result = INT_MAX;
        
        for(int i = idx; i<=n-d; i++) {
            maxi = max(maxi, jobDifficulty[i]);
            result = min(result, maxi + solve(jobDifficulty, n, i+1, d-1));
        }
        return t[idx][d] = result;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        memset(t, -1, sizeof(t));
        return solve(jobDifficulty, n, 0, d);
    }
};