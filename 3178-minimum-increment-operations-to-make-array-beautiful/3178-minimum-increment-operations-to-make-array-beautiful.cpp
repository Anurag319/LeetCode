#define ll long long
class Solution {
public:
    ll ans = 0;
    long long minIncrementOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<ll> dp(n+1,0);

        dp[0] = max(k-nums[0],0);
        dp[1] = max(k-nums[1],0);
        dp[2] = max(k-nums[2],0);

        for(int i=3;i<n;i++){
            dp[i] = max(0,k-nums[i]) + min({dp[i-1],dp[i-2],dp[i-3]});
        }

        ll ans = LONG_MAX;
        for(int i=n-1;i>=n-3;i--){
            ans = min(ans,dp[i]);
        }

        return ans;
    }
    
};