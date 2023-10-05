class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = -1;
        int el2 = -1;
        int c1 = 0;
        int c2 = 0;
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(el1==nums[i]) c1++;
            else if(el2==nums[i]) c2++;
            else if(c1==0){
                el1 = nums[i];
                c1 = 1;
            }
            else if(c2==0){
                el2 = nums[i];
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        c1 = c2 = 0;
        for(auto &z : nums){
            if(el1==z) c1++;
            else if(el2==z) c2++;
        }
        
        if(c1>n/3) ans.push_back(el1);
        if(c2>n/3) ans.push_back(el2);
        return ans;
    }
};