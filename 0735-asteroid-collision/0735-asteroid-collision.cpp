class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> first;
        for(int i=0;i<asteroids.size();i++){
            if(first.empty()){
                first.push(asteroids[i]);
            }else{
                   int top = first.top();
                   
                    bool isValid = true;
                   if(top > 0 && asteroids[i] < 0){
                       while(!first.empty() && first.top()>0){
                           if(abs(first.top()) == abs(asteroids[i])){
                               isValid = false;
                               first.pop();
                               break;
                           }else if(abs(first.top()) > abs(asteroids[i])){
                               isValid = false;
                               break;
                           }else{
                               first.pop();
                               isValid = true;
                           }
                       }
                       if(isValid) first.push(asteroids[i]);
                       
                   }
                  else{
                      first.push(asteroids[i]);
                  }
            
                
            }
        }
        
        vector<int> temp,output;
        while(!first.empty()){
            temp.push_back(first.top());
            first.pop();
        }
        for(int i=temp.size()-1;i>=0;i--){
            output.push_back(temp[i]);
        }
        return output;
        
    }
};