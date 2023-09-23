class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        int l=0,r=0;

        vector<int> ans;
        while(1){
            while(l<n && nums[l]<0){
                l++;
            }
            ans.push_back(nums[l]);

            while(r<n && nums[r]>0){
                r++;
            }
            ans.push_back(nums[r]);
            l++;
            r++;
            if(l>=n || r>=n) break;
        }

        return ans;
    }
};