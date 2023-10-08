class Solution {
public:
    int dp[501][501];
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        memset(dp,-1,sizeof(dp));

        int maxx = INT_MIN;

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                maxx = max(maxx,nums1[i]*nums2[j]);
            }
        }

        bool ok = false;
        for(int i=0;i<n1;i++){
            if(nums1[i]==0) ok=1;
        }
        for(int i=0;i<n2;i++){
            if(nums2[i]==0) ok=1;
        }       

        int k = f(0,0,n1,n2,nums1,nums2);
        if(ok){
            return k;
        }

        if(maxx<0) return maxx;
        return k;
    }

    int f(int ind1,int ind2,int n1,int n2,vector<int>& nums1, vector<int>& nums2){

        if(ind1>=n1 || ind2>=n2){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        int a = f(ind1+1,ind2+1,n1,n2,nums1,nums2);
        int b = nums1[ind1]*nums2[ind2] + f(ind1+1,ind2+1,n1,n2,nums1,nums2);
        int c = f(ind1,ind2+1,n1,n2,nums1,nums2);
        int d = f(ind1+1,ind2,n1,n2,nums1,nums2);

        return dp[ind1][ind2] = max({a,b,c,d});
    }
};