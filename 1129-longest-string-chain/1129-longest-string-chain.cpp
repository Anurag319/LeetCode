class Solution {
public:
    static bool cmp(string &a,string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {

       int n = words.size();

       sort(words.begin(),words.end(),cmp);

       vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(same(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        } 

        return *max_element(dp.begin(),dp.end());
    }


    bool same(string a,string b){
        int n = a.size();
        int m = b.size();

        if(m-n!=1) return false;
        int j=0,cnt=0;
        for(int i=0;i<n && j<m; ){
            if(a[i]!=b[j]){
                cnt++;
            }
            else{
                i++;
            }
            j++;
        }

        return cnt<=1;
    }
};