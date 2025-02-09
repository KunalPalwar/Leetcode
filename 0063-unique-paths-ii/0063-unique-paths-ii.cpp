class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& first) {
        vector<vector<int>> answer(first.size(),vector<int>(first[0].size(),0));
        for(int i=0;i<first.size();i++){
            for(int j=0;j<first[0].size();j++){
                if(first[i][j] == 1) continue;
                else if(i == 0 || j == 0) answer[i][j] = 1;
                else{
                    answer[i][j] = answer[i-1][j] + answer[i][j-1];
                }
            }
        }

        return answer[first.size()-1][first[0].size()-1];
        
    }
};