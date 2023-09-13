class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int,int> mp;
        
        mp[0] = 1;
        
        int sum = 0, ans = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            sum %= k; // if sum = -9 --> sum%5 = -4, thats why need to mod again with +k
            sum = (sum+k)%k; 
            ans += mp[sum];
            
            mp[sum]++;
        }
        
        return ans;
    }
};