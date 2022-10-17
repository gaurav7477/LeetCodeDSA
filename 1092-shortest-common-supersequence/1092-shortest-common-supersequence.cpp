class Solution {
public:
    string lcs(string str1, string str2,int n,int m){
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
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        int i = n, j = m;  //Starting from the last block
        string s;
        while(i > 0 && j > 0){
            //Loop until i and j are not out of bound
            if(str1[i-1] == str2[j-1]){
                //Concatinating LCS Part moving diagonal
                s += str1[i - 1];
                i--;
                j--;
            }
            else
            {
               if(dp[i][j-1] > dp[i-1][j]){
                    s += str2[j - 1];
                    j--;
                }
                else{
                    s += str1[i - 1];
                    i--;
                }
            }
        }
        
        //Adding left out characters
        while(i > 0){
            s.push_back(str1[i-1]);
            i--;
        }

        while(j > 0){
            s.push_back(str2[j-1]);
            j--;
        }
        
	reverse(s.begin(), s.end());
	return s;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        string ans = lcs(str1,str2,n,m);
        return ans;
    }
};