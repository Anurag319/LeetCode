#define ll long long 
class Solution {
public:
    
    ll ans = 0;
    bool mp[100005];
    ll dp[100001][2];
    
    void makeprime(){    // true - not a prime number 
        for(int i=1;i<=100000;i++){
            mp[i] = false;
        }
        mp[1] = true; 
        for(int i=2;i<=sqrt(100000) + 5;i++){
            if(mp[i] == false){
                for(int d=i*i;d<=100000;d+=i){
                    mp[d] = true;
                }
            }
        }
    }
    
    
    long long countPaths(int n, vector<vector<int>>& edges) {
        
        makeprime();
        vector<vector<int>> adj(n+1);
        
        for(auto c : edges){
            int a = c[0];
            int b = c[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        memset(dp,0,sizeof(dp));

        dfs(1,-1,adj);

        return ans;
    }

    // child[0] - prime
    // child[1] - nonprime
    void dfs(int node,int parent,vector<vector<int>> &adj){ 
        
        //valid answer considering that node 
        dp[node][0] = !mp[node];
        dp[node][1] = mp[node];

        for(auto c : adj[node]){
            if(c==parent) continue;

            dfs(c,node,adj); 

            ans += dp[node][0]*dp[c][1];
            ans += dp[node][1]*dp[c][0];

            if(mp[node]==false){ // node is a prime
                dp[node][0] += dp[c][1]; //prime 
            }
            else{ // node is nonprime 
                dp[node][1] += dp[c][1];
                dp[node][0] += dp[c][0];
            }
        }

        return;
    }
};