//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<int>mp(26,0);
		    string ans = "";
		    vector<char>v;
		    for(int i = 0; i < A.size();i++){
		        if(mp[A[i] - 'a'] == 0){
		            v.push_back(A[i]);
		        }
		        mp[A[i]-'a']++;
		        
		        int check = 0;
		        for(int j = 0; j < v.size();j++){
		            if(mp[v[j] - 'a'] == 1){
		                ans.push_back(v[j]);
		                check = 1;
		                break;
		            }
		        }
		        if(check == 0){
		            ans.push_back('#');
		        }
		        
		    }
		    return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends