class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        
        int rowStart = 0;
        int rowEnd = n-1;
        int colStart = 0;
        int colEnd = n-1;
        int count = 1;
        
        while(rowStart <= rowEnd && colStart <= colEnd){
            if(rowStart <= rowEnd){
                for(int i=colStart;i<=colEnd;i++){
                    result[rowStart][i] =  count++;
                }
                rowStart++;
            }
            if(colStart <= colEnd){
                for(int i=rowStart;i<=rowEnd;i++){
                    result[i][colEnd] = count++;
                }
                colEnd--;
            }
            
            if(rowStart <= rowEnd){
                for(int i=colEnd;i>=colStart;i--){
                    result[rowEnd][i] = count++;
                }
                rowEnd--;
            }
            if(colStart <= colEnd){
                for(int i=rowEnd;i>=rowStart;i--){
                    result[i][colStart] = count++;
                }
                colStart++;
            }
            
            
        }
        return result;
        
    }
};