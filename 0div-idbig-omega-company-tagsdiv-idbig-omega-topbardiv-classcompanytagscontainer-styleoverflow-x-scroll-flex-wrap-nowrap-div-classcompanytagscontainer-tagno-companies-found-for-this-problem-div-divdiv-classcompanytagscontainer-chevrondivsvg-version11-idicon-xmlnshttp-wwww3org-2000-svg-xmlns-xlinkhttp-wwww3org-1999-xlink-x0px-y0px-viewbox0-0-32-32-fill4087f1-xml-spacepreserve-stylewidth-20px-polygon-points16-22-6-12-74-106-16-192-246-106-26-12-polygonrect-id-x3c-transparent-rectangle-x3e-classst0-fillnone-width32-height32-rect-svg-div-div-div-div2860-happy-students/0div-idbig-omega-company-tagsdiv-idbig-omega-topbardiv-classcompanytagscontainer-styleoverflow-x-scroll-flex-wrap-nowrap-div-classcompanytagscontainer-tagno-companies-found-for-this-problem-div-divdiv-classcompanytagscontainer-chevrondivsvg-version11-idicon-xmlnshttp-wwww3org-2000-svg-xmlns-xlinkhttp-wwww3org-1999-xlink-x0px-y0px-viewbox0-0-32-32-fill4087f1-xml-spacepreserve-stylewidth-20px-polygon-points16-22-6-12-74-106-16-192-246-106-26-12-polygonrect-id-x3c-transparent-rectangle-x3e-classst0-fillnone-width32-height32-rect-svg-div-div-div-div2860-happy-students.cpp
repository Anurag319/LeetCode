class Solution {
public:
    int countWays(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int ans = nums[0]==0?0:1; // Not selecting anyone
        
        int selected = 0;
        for(int i=0;i<n;i++){
            selected++;
            if(selected>nums[i]){
                if(i+1<n && selected<nums[i+1]){
                    ans++;
                }
                else if(i+1==n){
                    ans++;
                }
            }
        }

        return ans;
    }
};