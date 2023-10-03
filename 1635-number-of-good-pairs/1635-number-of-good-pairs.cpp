class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto k : nums){
            ans += mp[k];
            mp[k]++;
        }
        return ans;
    }
};