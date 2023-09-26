class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26,0),visited(26,0);
        int i,n = s.length();
        for(i=0;i<n;i++){
            lastIndex[s[i] - 'a'] = i;
        }
        
        stack<int> stk;
        for(i=0;i<n;i++){
            int c = s[i] - 'a';
            if(visited[c]) continue;
            
            visited[c] = 1;
            
            while(!stk.empty() and stk.top()>c and lastIndex[stk.top()]>i){
                visited[stk.top()] = 0;
                stk.pop();
            }
            
            stk.push(c);
        }
        
        string ans = "";
        while(!stk.empty()){
            ans += (stk.top() + 'a') ;
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};