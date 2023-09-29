class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int c1=0,c2=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) c1++;
            if(nums[i]>nums[i-1]) c2++;
        }

        return c1==0 || c2==0;
    }
};