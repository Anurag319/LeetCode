#define ll long long
class Solution {
public:
    ll dp[501][501]; 
    const int mod = 1e9+7;
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return f(0,steps,arrLen)%mod;
    }

    ll f(int ind,int steps,int n){
        if(steps == 0){
            if(ind==0) return 1;
            return 0;
        }

        if(dp[ind][steps] != -1) return dp[ind][steps]%mod;

        ll a = 0;
        ll b = 0;
        ll c = 0;
        if(ind<n-1){
            a = f(ind+1,steps-1,n)%mod;
        }
        if(ind>0){
            b = f(ind-1,steps-1,n)%mod;
        }
        c = f(ind,steps-1,n)%mod;

        return dp[ind][steps] = (a+b+c)%mod;
    }
};