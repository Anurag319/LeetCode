class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();

        map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[flowers[i][0]]++;
            mp[flowers[i][1]+1]--;
        }

        auto it = mp.begin();
        int prev = it->second;

        it++;
        for(;it!=mp.end();it++){
            int currInd = it->first;
            int currValue = it->second;
            mp[currInd] = currValue + prev;
            prev = mp[currInd];
        }


        set<int> s;
        for(auto c : mp){
            s.insert(c.first);
        }


        vector<int> ans;

        for(auto c : people){
            auto k = s.upper_bound(c);
            if(k==s.begin()){
                ans.push_back(0);
            }
            else{
                k--;
                int p = *k;
                ans.push_back(mp[p]);
            }
        }

        return ans;
    }
};