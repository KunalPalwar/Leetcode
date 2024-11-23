class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> answer(size);
        stack<int> temp;
        for(int i=temperatures.size()-1;i>=0;i--){
            if(size-1==i){
                answer[i] = 0;
                temp.push(i);
            } 
            else{
                while(!temp.empty() && temperatures[temp.top()]<=temperatures[i]){
                    temp.pop();
                }
                if(!temp.empty()){
                    answer[i] = temp.top() - i;
                }else{
                    answer[i] = 0;
                }
                temp.push(i);
            }
            
            
        }
        
        return answer;
        
    }
};