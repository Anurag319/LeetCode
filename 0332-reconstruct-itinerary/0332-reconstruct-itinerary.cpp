class Solution {
public:
    
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> mp;
    vector<string> ans;
    
    void dfs(string s){
        
        
        // & is required to delete it from actual map also
        auto & pq = mp[s];

        while(!pq.empty()){
            string str = pq.top();
            pq.pop();
            dfs(str);
        }

        ans.push_back(s);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        
        // Concept of Euler Circuit and Euler Path
        
        // Make a graph that is lexicographically sorted 
        
        // JKF ---> ATL,SFO
        // ATL ---> JKF,SFO
        // SFO ---> ATL
            
        // use map---> string, priority_queue
        
        
        for(auto c : tickets){
            mp[c[0]].push(c[1]);
        }

        dfs("JFK");
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
    
};