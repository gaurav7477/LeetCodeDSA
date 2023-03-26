//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void solve(int ind,vector<int> &arr,vector<int>&output,int sum,int N){
        if(ind == N){
            output.push_back(sum);
            return;
        }
        
        sum += arr[ind];
        solve(ind+1,arr,output,sum,N);
        sum -= arr[ind];
        solve(ind+1,arr,output,sum,N);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>output;
        
        solve(0,arr,output,0,N);
        return output;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends