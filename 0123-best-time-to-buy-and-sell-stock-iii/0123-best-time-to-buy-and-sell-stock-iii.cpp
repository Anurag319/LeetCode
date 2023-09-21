class Solution {
public:

    int dp[100005][3][2];
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(0,2,prices,1);
    }
    
    //buy flag=1 saying you have to buy now
    int f(int ind,int k,vector<int> &prices,int buy){
        if(ind>=prices.size() || k==0){
            return 0;
        }

        if(dp[ind][k][buy]!=-1){
            return dp[ind][k][buy];
        }
        int p=0;
        if(buy){
            p = max(-prices[ind] + f(ind+1,k,prices,0),f(ind+1,k,prices,1));
        }
        else{
            p = max( prices[ind] + f(ind+1,k-1,prices,1),f(ind+1,k,prices,0));
        }

        return dp[ind][k][buy] = p;
    }
};