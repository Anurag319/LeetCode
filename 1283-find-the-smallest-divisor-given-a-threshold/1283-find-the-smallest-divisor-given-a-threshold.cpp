class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int maxx = *max_element(nums.begin(),nums.end());
        int l = 1, r =  maxx, ans=1;
        
        while(l<=r){
            
            int mid = (l+r)/2;
            int cnt = 0;
            for(int i=0;i<n;i++){
                cnt += (nums[i]+mid-1)/mid;
            }
            
            if(cnt<=threshold){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        return ans;
    }
};