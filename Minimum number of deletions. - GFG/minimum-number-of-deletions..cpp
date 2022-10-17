//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int lcs(string str1, string str2,int n,int m){
        // base condition
        int dp[n+1][m+1];
        for(int i = 0; i < n+1; i++){
            for (int j = 0; j< m+1;j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < n+1; i++){
            for (int j = 1; j< m+1;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    string reverse_(string s){
    int i = 0;
    int j = s.length()-1;
    while(i < j){
        swap(s[i++],s[j--]);
    }
    return s;
    }
int minDeletions(string str, int n) { 
    //complete the function here 
    string s1 = reverse_(str);
        int m = s1.length();
        int lcs_length =lcs(str,s1,n,m);
        return n-lcs_length;
} 