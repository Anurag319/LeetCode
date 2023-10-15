class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<long long> square;
        square.push_back(1);

        int cnt = 2;

        while(cnt!=101){
            square.push_back(cnt*cnt);
            cnt++;
        }

        long long ans = 0;
        for(int i=0;i<n;i++){
            long long now = 0;
            for(int j=0;j<100;j++){

                if((i+1)*square[j]-1>=n) break;
                now = now + nums[(i+1)*square[j]-1];
            }
            ans = max(ans,now);
        }

        return ans;
    }
};