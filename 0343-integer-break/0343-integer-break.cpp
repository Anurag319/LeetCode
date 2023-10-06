class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1,n,dp);
    }
    
    int f(int ind,int n,vector<vector<int>> &dp){
        if(n==1) return 1;
        
        if(dp[ind][n] != -1) return dp[ind][n];
        int l = n;
        for(int i=ind;i<=n-1;i++){
            l = max(l,i*f(1,n-i,dp));
        }
        
        return dp[ind][n] = l;
    }
};