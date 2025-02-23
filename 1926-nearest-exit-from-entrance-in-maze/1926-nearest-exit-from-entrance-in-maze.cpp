class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        vector<vector<int>> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int answer = 0;
        int row = maze.size();
        int column = maze[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]]=true;
        while (!que.empty()) {

            for (int y = 0; y < que.size(); y++) {
                pair<int, int> p = que.front();
                que.pop();

                if(!(p.first == entrance[0] && p.second == entrance[1]) && (p.first == 0 || p.second == 0 || p.first == row-1 || p.second == column-1)){
                    return answer;
                }

                for (int i = 0; i < 4; i++) {
                    int directionX = p.first + direction[i][0];
                    int directionY = p.second + direction[i][1];

                    if(directionX < 0 || directionX >= row || directionY < 0 || directionY >= column || visited[directionX][directionY] || maze[directionX][directionY] != '.' ){
                        continue;
                    }else{
                        visited[directionX][directionY] = true;
                        if(directionX == 0 || directionY == 0){
                            return answer+1;
                        }
                        que.push({directionX,directionY});
                    }
                }
            }
            answer++;
        }

        return -1;
    }
};