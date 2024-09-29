class Solution {
public:
    vector<vector<int>> check(vector<vector<int>> &image,int first,int second,int color,int  currentColor){
        
          if(first<0 || first>=image.size() || second<0 || second >= image[0].size() || image[first][second] != currentColor) return image;
        
         image[first][second] = color;
        check(image,first+1,second,color,currentColor);
        check(image,first-1,second,color,currentColor);
        check(image,first,second+1,color,currentColor);
        check(image,first,second-1,color,currentColor);
        
        return image;
        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int first, int second, int color) {
        
        if(image[first][second] == color) return image;
       return check(image,first,second,color,image[first][second]);
        
       
        
    }
};