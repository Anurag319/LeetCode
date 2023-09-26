#define ll long long
class Solution {
public:
    ll  ans = 0;
    long long maximumSumOfHeights(vector<int>& h) {
        ll n = h.size();
        
        // initialise a stack
        // (i) when you get smaller value - change value by dp[ind] = h[i]*(ind+1);
        // (ii) when get higher value , pop until get smaller value than current value 
        stack<pair<ll,ll>> stk;
        vector<ll> left(n,0),right(n,0);
        left[0] = h[0];

        for(ll i=0;i<n;i++){
            while(!stk.empty() && stk.top().first>=h[i]){
                stk.pop();
            }

            if(stk.empty()){
                left[i] = h[i]*(i+1);
            }
            else{
                int val = stk.top().second;
                left[i] = left[val] + (i-val)*h[i];
            }
            stk.push({h[i],i});
        }

        while(!stk.empty()) stk.pop();

        right[n-1] = h[n-1];
        for(ll i=n-1;i>=0;i--){
            while(!stk.empty() && stk.top().first>=h[i]){
                stk.pop();
            }

            if(stk.empty()){
                right[i] = h[i]*(n-i);
            }
            else{
                ll val = stk.top().second;
                right[i] = right[val] + (val-i)*h[i];
            }
            stk.push({h[i],i});
        }

        ll ans = n;
        for(ll i=0;i<n;i++){
            ans = max(ans,left[i]+right[i]-h[i]);
        }

        return ans;
    }
};