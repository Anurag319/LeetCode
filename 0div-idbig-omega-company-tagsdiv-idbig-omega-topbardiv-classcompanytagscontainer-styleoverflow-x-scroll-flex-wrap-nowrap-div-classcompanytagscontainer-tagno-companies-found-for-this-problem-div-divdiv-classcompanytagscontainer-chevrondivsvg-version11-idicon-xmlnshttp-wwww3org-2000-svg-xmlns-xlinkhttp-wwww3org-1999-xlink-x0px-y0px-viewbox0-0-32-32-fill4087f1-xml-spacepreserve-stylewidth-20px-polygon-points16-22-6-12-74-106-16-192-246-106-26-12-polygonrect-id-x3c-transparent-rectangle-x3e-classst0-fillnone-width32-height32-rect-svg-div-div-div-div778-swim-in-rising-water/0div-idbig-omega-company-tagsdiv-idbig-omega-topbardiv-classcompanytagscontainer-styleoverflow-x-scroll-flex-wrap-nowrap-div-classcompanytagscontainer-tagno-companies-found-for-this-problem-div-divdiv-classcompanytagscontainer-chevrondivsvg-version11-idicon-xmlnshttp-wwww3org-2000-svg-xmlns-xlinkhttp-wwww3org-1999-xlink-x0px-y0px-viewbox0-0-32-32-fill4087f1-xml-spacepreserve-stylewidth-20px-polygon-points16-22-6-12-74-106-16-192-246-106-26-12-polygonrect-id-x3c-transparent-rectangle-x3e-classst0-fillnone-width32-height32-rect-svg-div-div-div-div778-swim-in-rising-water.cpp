#define pi pair<int,pair<int,int>>
int d[] = {0,1,0,-1,0};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        vector<vector<int>> dist(n+1,vector<int>(m+1,1e9));
        dist[0][0] = 0;
        pq.push({grid[0][0],{0,0}});
        
        while(!pq.empty()){
            
            auto k = pq.top();
            int cost = k.first;
            int a = k.second.first;
            int b = k.second.second;
            pq.pop();
            
            if(a==n-1 && b==m-1){
                return cost;
            }
            
            for(int i=0;i<4;i++){
                int x = a+d[i];
                int y = b+d[i+1];

                if(x<0 || y<0 || x>=n || y>=m) continue;
                if(dist[x][y]<cost) continue;

                int val = max(cost,grid[x][y]);
                if(val==dist[x][y]) continue;
                dist[x][y] = val;
                pq.push({val,{x,y}});
            }
        }
        
        return 0;
    }
};