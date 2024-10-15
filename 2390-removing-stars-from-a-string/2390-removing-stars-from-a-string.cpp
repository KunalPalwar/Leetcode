class Solution {
public:
    string removeStars(string s) {
        stack<char> first;
        int count = 0;
        string answer = "";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '*'){
                count++;
            }else{
                if(count > 0){
                    count--;
                }else{
                    first.push(s[i]);
                }
            }
        }
        while(!first.empty()){
            answer.push_back(first.top());
            first.pop();
        }
        return answer;
        
    }
};