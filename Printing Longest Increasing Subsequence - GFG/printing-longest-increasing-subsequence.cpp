//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        
        for(int i = 0; i <= n-1; i++){
            hash[i] = i;
            for(int prev_index = 0;prev_index <= i-1;prev_index++){
                if(arr[prev_index] < arr[i] && 1 + dp[prev_index] > dp[i]){
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }
        int ans = -1;
        int last_index = -1;
        for(int i = 0; i <= n-1; i++){
            if(dp[i] > ans){
                ans = dp[i];
                last_index = i;
            }
        }
        
        vector<int>temp;
        temp.push_back(arr[last_index]);
        while(hash[last_index] != last_index){
            last_index = hash[last_index];
            temp.push_back(arr[last_index]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends