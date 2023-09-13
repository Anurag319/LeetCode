class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        // eqn --> j-i == nums[j]-nums[i] --> nums[j] - j == nums[i] - i;
        long long n = nums.size(),cnt = 0;
   
        unordered_map<long long,long long> mp;
        mp[nums[0]] = 1;
        for(int i=1;i<n;i++){
            cnt += mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        return ((long long)n*(long long)(n-1))/2 - (long long)cnt;
    }
};