#define ll long long
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        
        ll l=1,r=1e10,ans=0;

        while(l<=r){
            ll mid = (l+r)>>1;
            if(check(n,k,budget,composition,stock,cost,mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return ans;
    }

    bool check(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost,ll mid){

        for(int i=0;i<k;i++){
            ll sum=0;
            for(int j=0;j<n;j++){
                ll v = mid*composition[i][j];
                if(v>stock[j]){
                    sum += (ll)(v-stock[j])*(ll)cost[j];
                }
            }
            if(sum<=budget) return true; 
        }

        return false;
    }
};