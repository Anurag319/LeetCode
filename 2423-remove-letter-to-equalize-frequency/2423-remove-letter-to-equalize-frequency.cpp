class Solution {
public:
    bool equalFrequency(string word) {
        
        int n = word.size();
        
        vector<int> freq(26,0);
        
        // a--> 1 b--> 1 c--> 2 
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }
        
        for(int i=0;i<n;i++){
            
            // for every index, choose letter and remove from word by decrementing 
            freq[word[i]-'a']--;
            set<int> s;
            
            for(int i=0;i<26;i++){
                if(freq[i]>0){
                    s.insert(freq[i]);
                }
            }
            if(s.size()==1) return true;
            freq[word[i]-'a']++;
        }
        
        return false;
    }
};