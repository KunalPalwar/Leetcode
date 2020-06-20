class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int column=matrix[0].size();
        
        vector<vector<int> > answer(row,vector<int>(column,INT_MAX));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if(matrix[i][j]==0)
                    answer[i][j]=0;
                else
                {
                    for(int k=0;k<row;k++)
                    {
                        for(int l=0;l<column;l++)
                        {
                            if(matrix[k][l]==0)
                            {
                                int distance=abs(k-i)+abs(l-j);
                                answer[i][j]=min(answer[i][j],distance);
                            }
                        }
                    }
                }
            }
        }
        return answer;

    }
   //BFS solution
   class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int column=matrix[0].size();
        
        vector<vector<int> > answer(row,vector<int>(column,INT_MAX));
        queue<pair<int,int> > q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
                if(matrix[i][j]==0)
                   { answer[i][j]=0;
                     q.push({i,j});
                    
                   }
            
        }
        int arr[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_i=p.first+arr[i][0];
                int new_j=p.second+arr[i][1];
                
                if(new_i>=0&&new_i<row&&new_j>=0&&new_j<column)
                {
                    if(answer[new_i][new_j]>answer[p.first][p.second]+1)
                    {
                        answer[new_i][new_j]=answer[p.first][p.second]+1;
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        return answer;

    }
   
    
    
    
};
//Dp Solution

		class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int row=matrix.size();
        int column=matrix[0].size();
        
       vector<vector<int> > answer(row,vector<int>(column,INT_MAX-10000));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if(matrix[i][j]==0)
                    answer[i][j]=0;
                else
                {
                    if(i>0)
                        answer[i][j]=min(answer[i][j],answer[i-1][j]+1);
                    if(j>0)
                        answer[i][j]=min(answer[i][j],answer[i][j-1]+1);
                }
            }
        }
        
        for(int i=row-1;i>=0;i--)
        {
            for(int j=column-1;j>=0;j--)
            {
                if(matrix[i][j]==0)
                    answer[i][j]=0;
                else
                {
                    if(i<row-1)
                        answer[i][j]=min(answer[i][j],answer[i+1][j]+1);
                    if(j<column-1)
                        answer[i][j]=min(answer[i][j],answer[i][j+1]+1);
                }
            }
        }
        return answer;

    }
   
    
    
    
};
    
    
    
};