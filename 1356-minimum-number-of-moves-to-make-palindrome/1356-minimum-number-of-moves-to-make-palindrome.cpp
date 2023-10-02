class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int i,n = s.length();

        int l = 0;
        int r = n-1;
        int center = -1;
        int count = 0;

        while(l<r){
            

            // iterate over left and right end points
            // Fixing right point and find left index where 
            // s[left] = s[right]
            for(i=l;i<=r;i++){
                if(s[i]==s[r]){
                    break;
                }
            }

            if(i==r){
                center = i;
                r--;
                continue;
            }

            for(int j=i;j>l;j--){
                swap(s[j],s[j-1]);
                count++;
            }

            l++;
            r--;
        }


        if(center != -1){
            count += abs(center-n/2);
        }

        return count;
    }
};