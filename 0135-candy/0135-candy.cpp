#define pi pair<int,int>
class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n=ratings.size(), ans=0;
        
        // [. . 1 4 6 5 2 7 8 3] so values assigned will be 1
        // [    1       1     1]
        // [    1 2 3 2 1 2 3 1]
        // If new values come 2 cases (i) Neighbour of visited element          
        // (ii) Neighbour of unvisited element
        // since we are picking element from smaller to high , just apply value 1 if there is no neighbour and min(neighbour) + 1 in case of neighbour
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        
        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
        }
        
        vector<int> visited(n,0);
        
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            int val = p.first;
            int i = p.second;
           
            int l=0,r=0;
            
            if(i-1>=0){
                if(ratings[i-1]==ratings[i] || ratings[i-1]>ratings[i]) l=0;
                else{
                    l = visited[i-1];
                }
            }
            
            if(i+1<n){
                if(ratings[i+1]==ratings[i] || ratings[i+1]>ratings[i]) r=0;
                else{
                    r = visited[i+1];
                }
            }
            
            visited[i] = max(l,r) + 1;
            ans += visited[i];
        }
        
        return ans;
    }
};