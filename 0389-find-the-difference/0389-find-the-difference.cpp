class Solution {
public:
    char findTheDifference(string s, string t) {
        int i,n = s.length();
        unordered_map<char,int> mp,mp2;
        for(i=0;i<n;i++){
            mp[s[i]]++;
            mp2[t[i]]++;
        }
        mp2[t[n]]++;
        for(i='a';i<='z';i++){
            if(mp[i]!=mp2[i]){
                return i;
            }
        }
        return 'a';
    }
};