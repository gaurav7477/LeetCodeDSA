//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{  
    
public:

    bool solve(vector<int>arr, int sum,int n){
        bool dp[n+1][sum+1];
        // base case
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
         for (int i = 1; i <= sum; i++)
            dp[0][i] = false;

        for(int i =1; i< n + 1;i++){
            for(int j =1; j< sum + 1;j++){
                if(arr[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                    
                    
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
            
        }
        return dp[n][sum];
    
        
    }

    int isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        if(solve(arr,sum,n)) return 1;
        else return 0;
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