class Solution {
public:
    
    int find(int n,vector<int> &par){
        if(par[n]==n) return n;
        return par[n] = find(par[n],par);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(),i,j,ans = 0;
        vector<pair<int,pair<int,int>>> adj;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj.push_back({d,{i,j}});
            }
        }
        
        sort(adj.begin(),adj.end());
        vector<int> par((n*(n-1))/2+1),size((n*(n-1))/2+1,1);
        for(i=0;i<par.size();i++){
            par[i] = i;
        }
 
        for(i=0;i<adj.size();i++){
            int cost = adj[i].first;
            
            int a = adj[i].second.first;
            int b = adj[i].second.second;
            int c = find(a,par);
            int d = find(b,par);
            
            if(c!=d){
                ans += cost;
                if(size[c] < size[d])
                {
                    par[c] = par[d];
                    size[d] += size[c];
                }
                else
                {
                    par[d] = par[c];
                    size[c] += size[d];
                }
            } 
        }
        
        return ans;
    }
};