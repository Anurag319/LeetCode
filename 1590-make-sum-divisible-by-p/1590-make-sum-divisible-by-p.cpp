class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size(), ans = n;
        
        long long sum=0;
        
        for(auto c : nums) sum += c;
        
        // subarray of "req" value need to be removed
        int req = sum%p;
        if(req==0) return 0;
        // Or, find subarray whose subarray%p==req, sum=50, p=6, req=2---> subarray_sum = 2,8,14
        
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            sum = sum%p;
            // cout<<"sum "<<sum<<endl;
            // cout<<"s .."<<(sum+p-req)%p<<endl;
            if(mp.find((sum+p-req)%p)!=mp.end()){
                ans = min(ans,i-mp[(sum+p-req)%p]);
                // cout<<"mp "<<mp[sum+p-req]<<ans<<endl;
            }
            mp[sum] = i;
        }
        
        return ans>=n?-1:ans;
    }
};