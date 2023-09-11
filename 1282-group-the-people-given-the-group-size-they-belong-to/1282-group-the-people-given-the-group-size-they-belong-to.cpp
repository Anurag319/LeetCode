class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n = groupSizes.size();
        
        vector<bool> visited(n+1,0);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                int sz = groupSizes[i];
                int j = i, cnt = 0;
                vector<int> p;
                while(j<n && cnt<sz){
                    if(visited[j]==0 && groupSizes[j]==sz){
                        visited[j] = 1;
                        cnt++;
                        p.push_back(j);
                    }
                    j++;
                }
                ans.push_back(p);
            }
        }
        
        return ans;
    }
};