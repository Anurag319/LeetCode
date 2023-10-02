class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int cnt = 1,alice=0,bob=0;
        char temp = colors[0];
        for(int i=1;i<n;i++)
        {
            if(colors[i]==temp){
                cnt++;
            }
            else{
                temp = colors[i];
                cnt = 1;
            }
            if(cnt>=3){
                if(temp=='A') alice++;
                else bob++;
            }
        }

        return alice>bob;
    }
};