class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        
        int n = nums.size();
        
        // map for frequency of elements
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        // map for frequency of frequency of elements
        map<int,int> freq;
        for(auto c : mp){
            freq[c.second]++;
        }

        for(int i=n-1;i>=0;i--){

            if(freq.size()==1){
                for(auto c : freq){
                    
                    int p = c.second; // [4,4,4,4,4,4]  {6,1}
                    int q = c.first;  // [3,4,5,6,7,8]  {1,6}
                    if(p==1 || q==1) return i+1;
                }
            }
            else if(freq.size()==2){
                
                if(freq.find(1) != freq.end()){
                    if(freq[1]==1) return i+1;
                }
                auto a = freq.begin();
                auto b = freq.rbegin();
                
                // [2,2,2,3,3,3,4,4,4,4] || [4,5,5,5,6,6,6]
                if((b->first)-(a->first)==1 && (b->second)==1) return i+1;
            }

            if(freq[mp[nums[i]]]==1)freq.erase(mp[nums[i]]);
            else{
                freq[mp[nums[i]]]--;
            }
            
            mp[nums[i]]--;     
            if(mp[nums[i]] == 0){
                mp.erase(nums[i]);
            }
            else{
                freq[mp[nums[i]]]++;
            }
            
        }
        
        return 2;
    }
};