//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{  
    
public:

    // bool solve(vector<int>arr, int sum,int n){
    //     bool dp[n+1][sum+1];
    //     // base case
    //     for (int i = 0; i <= n; i++)
    //         dp[i][0] = true;
    //      for (int i = 1; i <= sum; i++)
    //         dp[0][i] = false;

    //     for(int i =1; i< n + 1;i++){
    //         for(int j =1; j< sum + 1;j++){
    //             if(arr[i-1] > j){
    //                 dp[i][j] = dp[i-1][j];
                    
                    
    //             }
    //             else{
    //                 dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
    //             }
    //         }
            
    //     }
    //     return dp[n][sum];
    
        
    // }

        
    bool isSubsetSum(vector<int>& nums,int sum){
        int n = nums.size();
        bool t[n + 1][sum + 1];
        
        // initialization ->> base condition
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+ 1;j++){
                if(i == 0) t[i][j] = false;
                if(j == 0) t[i][j] = true;
                
            }
        }
        
          for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
                } else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
     
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends