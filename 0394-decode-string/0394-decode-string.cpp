class Solution {
public:
    string decodeString(string s) {
        stack<char> first;
        string answer = "";
        
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == ']'){
                first.push(s[i]);
            }else if(s[i] == '['){
                string temp = "";
                while(!first.empty()){
                    if(first.top() == ']'){
                        first.pop();
                        break;
                    }else{
                        temp.push_back(first.top());
                        first.pop();
                    }
                }
                int index = i-1;
                string number = "";
                while(index>=0 && s[index]>='0' && s[index]<='9'){
                    number = s[index] + number;
                    index--;
                }
                int n = stoi(number);
                for(int i=0;i<n;i++){
                    for(int j=temp.length()-1;j>=0;j--){
                        first.push(temp[j]);
                    }
                }
                i = index+1;
                
            }else{
                first.push(s[i]);
            }
        }
        
        while(!first.empty()){
            answer.push_back(first.top());
            first.pop();
        }
        return answer;
    }
};