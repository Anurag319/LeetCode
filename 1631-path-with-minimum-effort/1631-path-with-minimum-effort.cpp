#define pi pair<int,pair<int,int>> 
int row[] = {0,1,0,-1,0};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        vector<vector<int>> visited(n+1,vector<int>(m+1,1e9));
        
        pq.push({0,{0,0}});
        visited[0][0] = 0;
        
        int ans = 0;
        // Minimum value will be maintained at each cell by priorty_queue
        
        while(!pq.empty()){
            
            auto k = pq.top();
            int a = k.first;
            int b = k.second.first;
            int c = k.second.second;
            pq.pop();
            
            if(b==n-1 && c==m-1){
                return a;
            }
            
            for(int i=0;i<4;i++){
                int x = b + row[i];
                int y = c + row[i+1];
                
                if(valid(x,y,n,m)){
                    int val = max(a,abs(heights[x][y]-heights[b][c]));
                    if(visited[x][y]>val){
                        visited[x][y] = val;
                        pq.push({val,{x,y}});
                    }
                }
            }
        }
        
        return 0;
    }
    
    bool valid(int x,int y,int n,int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
};