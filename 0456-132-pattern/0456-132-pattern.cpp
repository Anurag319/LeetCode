class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int l = nums[0];
        multiset<int> st;
        for(int i=1;i<n;i++){
            st.insert(nums[i]);
        }

        for(int i=1;i<n;i++){
            if(st.size()==1) return false;
            st.erase(st.find(nums[i]));
            if(nums[i]>l){
                auto it = st.upper_bound(l);
                if(it!=st.end()){
                    int val = *it;
                    if(l<val && val<nums[i]) return true;
                }
            }
            else{
                l = min(nums[i],l);
            }
        }

        return false;
    }
};