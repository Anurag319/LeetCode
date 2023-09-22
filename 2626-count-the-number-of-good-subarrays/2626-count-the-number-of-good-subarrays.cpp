#define ll long long 
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<ll,ll> mp;

        ll sum=0,ans=0,l=0;
        for(int i=0;i<n;i++){
            sum += mp[nums[i]];
            mp[nums[i]]++;
            if(sum>=k){
                while(sum>=k){
                    ans += n-i;
                    mp[nums[l]]--;
                    sum-=mp[nums[l]];
                    l++;
                }
            }
        }

        return ans;
    }
};