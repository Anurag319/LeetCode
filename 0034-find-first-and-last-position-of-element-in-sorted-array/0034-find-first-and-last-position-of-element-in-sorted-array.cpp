class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int a = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int b = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        
        if(target>nums[nums.size()-1] || target<nums[0]){
            return {-1,-1};
        }
        if(nums[b-1]!=target){
            return {-1,-1};
        }
        
        return {a,b-1};
    }
};