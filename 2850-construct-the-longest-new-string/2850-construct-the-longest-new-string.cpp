class Solution {
public:
    int longestString(int x, int y, int z) {
        
        int minn = min(x,min(y,z));

        x = max(0,x-minn);
        y = max(0,y-minn);
        z = max(0,z-minn);

        minn *= 3;
        if(z<=0){
            if(x!=y){
                minn += 2*min(x,y) + 1;
            }
            else minn += 2*min(x,y);
        }
        else{
            if(x<=0){
                if(y) minn = minn + z + 1;
                else minn = minn + z;
            }
            else{
                if(x) minn = minn + z + 1;
                else minn = minn + z;
            }
        }
        
        return 2*minn;
    }
};