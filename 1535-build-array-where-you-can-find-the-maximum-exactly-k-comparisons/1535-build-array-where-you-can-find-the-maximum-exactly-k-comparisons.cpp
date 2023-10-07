long long dp[51][101][51];
int mod = 1e9+7;
class Solution {
public:
    int numOfArrays(int n, int m, int k) {

        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            dp[1][i][1] = 1;
        }

        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int p=1;p<=k;p++){
                    
                    long long s = 0;
                    // ways where p will be maximum element in previous iteration
                    
                    s = (s + j*dp[i-1][j][p])%mod;
                    // now search cost will be added as current element will be maximum one,

                    for(int u=1;u<=j-1;u++){
                        s = (s + dp[i-1][u][p-1])%mod;
                    }

                    dp[i][j][p] = (dp[i][j][p] + s)%mod;
                }
            }
        }

        long long ans = 0;
        for(int j=1;j<=m;j++){
            ans += dp[n][j][k];
            ans %= mod;
        }
        return ans;
    }         
};