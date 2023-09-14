class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        
        int n = nums.size();
        
        int l = 0;
        int ans = 1;
        int cnt = 0;
        
        multiset<int> s;


        for(int i=0;i<n;i++){
            s.insert(nums[i]); 
            
           
            int maxx = *s.rbegin();
            int minn = *s.begin();

            
            if(maxx-minn<=limit){
                cout<<"k "<<i-l+1<<endl;
                ans = max(ans,i-l+1);
            }
            else{
                while(maxx-minn>limit){
                    s.erase(s.find(nums[l++]));
                    maxx = *s.rbegin();
                    minn = *s.begin();
                } 
            }
        }
        
        return ans;
    }
};