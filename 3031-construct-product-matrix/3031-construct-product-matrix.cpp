

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        long long p = 1;
        vector<vector<int>> prefix(n+1,vector<int>(m+1));
        vector<vector<int>> suffix(n+1,vector<int>(m+1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j] = p;
                p *= grid[i][j];
                p %= 12345;
            }
        }

        p=1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suffix[i][j] = p;
                p*= grid[i][j];
                p %= 12345;
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long k = prefix[i][j] * suffix[i][j];
                k %= 12345;
                grid[i][j] = k;
            }
        }

        return grid;
        
    }
};