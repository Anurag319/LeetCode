class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = (int)log2(n) + 1, C = 27;
        
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n-1;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }

        // fa[i][j] ---> 2^i-th father of vertex j;
        // fa[0][1]-->1st par,fa[1][1]-->2nd par,fa[2][1]-->4th par,fa[3][1]-->8th par
        vector<vector<int>> fa(m,vector<int>(n));

        // w[i][j] ---> count of j from root to vertex i;
        vector<vector<int>> w(n,vector<int>(C,0));

        // d[i] ---> depth of vertex i;
        vector<int> d(n,0);

        dfs(0,0,0,fa,w,d,adj);

        //binary lifting
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                fa[i][j] = fa[i-1][fa[i-1][j]];
            }
            cout<<endl;
        }

        vector<int> res;

        for(auto &q : queries){
            int x = q[0];
            int y = q[1];
            int l = lca(x,y,m,fa,d);

            int len = d[x] + d[y] - 2*d[l];

            int maxx = 0;

            for(int i=1;i<C;i++){
                int num = w[x][i] + w[y][i]  - 2*w[l][i];
                maxx = max(maxx,num);
            }

            res.push_back(len-maxx);
        }

        return res;
    }
    
    void dfs(int node,int par,int depth,vector<vector<int>> &fa,vector<vector<int>> &w, vector<int> &d,vector<vector<pair<int,int>>> &adj){
        fa[0][node] = par;
        d[node] = depth;
        for(auto &[c,weight] : adj[node]){
            if(c==par) continue;
            w[c] = w[node];
            w[c][weight]++;
            dfs(c,node,depth+1,fa,w,d,adj);
        }
    }


    int lca(int x,int y,int m,vector<vector<int>> &fa,vector<int> &d){
        if(d[x]>d[y]) swap(x,y);

        int diff = d[y]-d[x];
        while(diff>0){
            int k = log2(diff);
            y = fa[k][y];
            diff = diff-(1<<k);
        }

        for(int i=m-1;i>=0;i--){
            if(fa[i][x]!=fa[i][y]){
                x = fa[i][x];
                y = fa[i][y];
            }
        }

        return x==y ? x : fa[0][x];
    }
};