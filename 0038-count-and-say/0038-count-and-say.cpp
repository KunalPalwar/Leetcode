class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string res = countAndSay(n-1);
        if(res == "1") return "11";
        string output = "";
        int count = 1;
        for(int i=1;i<res.length();i++){
            if(res[i-1] == res[i]){
                count++;
            }else{
                output+=(to_string(count));
                count=1;
                output.push_back(res[i-1]);
            }
        }
        
        
            output+=(to_string(count));
            output.push_back(res[res.length()-1]);
        
        return output;
    }
};