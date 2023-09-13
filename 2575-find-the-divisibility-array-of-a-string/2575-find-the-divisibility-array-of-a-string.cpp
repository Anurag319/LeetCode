class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans;
        
        long long val = 1,carry = 0;
        for(int i=0;i<n;i++){
            val = (word[i]-'0') + carry*10;
            if(val%m==0) ans.push_back(1);
            else ans.push_back(0);
            carry = val%m;
        }
        
        return ans;
    }
};