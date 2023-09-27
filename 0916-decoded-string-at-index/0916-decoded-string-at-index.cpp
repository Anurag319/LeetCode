class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long sz=0,n = s.length();
        
        for(int i = 0;i<n;i++){
            if(isdigit(s[i])){
                sz *= (s[i] - '0');
            }else{
                sz++;
            }
        }
        
        
        for(int i=n-1;i>=0;i--){
            k %= sz;
            if(k==0 and isalpha(s[i])){
                return (string)"" + s[i];
            }
            
            if(isdigit(s[i])){
                sz /= (s[i]-'0');
            }
            else sz--;    
        }
        
        return s.substr(k,1);
    }
};