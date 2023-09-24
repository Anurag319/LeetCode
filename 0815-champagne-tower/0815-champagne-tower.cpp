class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {  

        vector<double> curr(query_row+1,0.0),prev(query_row+1,0.0);
        prev[0] = poured;

        for(int i=1;i<=query_row;i++){
            curr[0] = max(0.0,(prev[0]-1)/2.0);
            for(int j=1;j<i;j++){
                curr[j] = max(0.0,(prev[j-1]-1)/2.0) + max(0.0,(prev[j]-1)/2.0);
            }
            curr[i] = max(0.0,(prev[i-1]-1)/2.0);
            prev = curr;
        }

        return min(1.00000,prev[query_glass]);
    }
};