class Solution {
public:

// its like a knapsack problem with little trick 
// pick item, reduce item and weight (W-weight[i],item-1)
// not pick, reduce item (W,item-1)

//  Similarly
//  bottom up n-1...n-2...n-3....1
// ind ---> total element and second parameter is total time , maximum can be n
//  Paint the wall, reduce item and time cost[ind] + f(ind-1,n-(1+time[ind]))
// Not paint, reduce just 1 unit of time f(ind-1,n-1);

// chances that element is < 0 , then it means free painter has been used more than paid painter, which is not possible because free painter can only be used when paid painter is busy , so return INT_MAX in that case 


    int dp[501][501];
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        memset(dp,-1,sizeof(dp));
        // f(current element or ind , , ,Time left) since n can be maximum time
        return f(n-1,cost,time,n);
    }

    long long f(int ind,vector<int>&cost,vector<int> &time,int t){

        if(t<=0) return 0;

        if(dp[ind][t] != -1 ) return dp[ind][t];
        if(ind==0){
            long long k = t - (1+time[ind]);
            if(k>0) return dp[ind][t] = INT_MAX;
            return dp[ind][t] = cost[ind];
        }


        long long take = cost[ind] + f(ind-1,cost,time,t-(1+time[ind]));
        long long nottake = f(ind-1,cost,time,t);

        return dp[ind][t] = min(take,nottake);
    }
};