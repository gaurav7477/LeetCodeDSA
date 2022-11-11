class Solution {
public:
    int dp[101][101];
    int solveRec(vector<int>& v , int i , int j){
        // base case
        if(i == j || i+1 == j) 
            return 0;

        int ans = INT_MAX;
        for(int k =i+1 ; k<j ; k++){

            ans = min( ans , v[i]*v[k]*v[j] + solveRec(v,i,k) + solveRec(v,k,j) );
        }

        return ans;
    }

    int solveMem(vector<int>& v , int i , int j){
        // base case
        if(i == j || i+1 ==j) 
            return 0;

        if(dp[i][j] != -1 )
            return dp[i][j];

        int ans = INT_MAX;
        for(int k =i+1 ; k<j ; k++){

            ans = min( ans , v[i]*v[k]*v[j] + solveMem(v,i,k) + solveMem(v,k,j) );
        }
        dp[i][j] = ans;

        return dp[i][j];
    }

    int solveTab(vector<int>& v ){
        int n = v.size();
        vector<vector<int>> dp(n , vector<int>(n , 0) );


        for(int i =n-1 ; i>=0 ; i--){
            for(int j=i+2 ; j<n ; j++){ 

                int ans=INT_MAX;
                for(int k =i+1 ; k<j ; k++){
                    ans = min( ans , v[i]*v[k]*v[j] + dp[i][k] + dp[k][j] );
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n-1];  
    }


    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // return solveRec(values,0,n-1);
        
        memset(dp,-1,sizeof(dp));
        return solveMem(values,0,n-1);

        // return solveTab(values);
    }
};