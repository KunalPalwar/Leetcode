class Solution {
public:


    pair<int,int> GetPalindromic(int start ,int end,string &s){
       pair<int,int> p = {0,0};
       while(start>=0 && end<s.length()){
        if(s[start]!=s[end]) return p;
        p.first = start;
        p.second = end;
        start--;
        end++;
       }
       return p;
    }
    string longestPalindrome(string s) {
        string answer = "";
        int stringLength = 0;

        for(int i=0;i<s.length();i++){
            pair<int,int> p = GetPalindromic(i-1,i+1,s);
            pair<int,int> p2 = GetPalindromic(i,i+1,s);
            int start = p.first;
            int end = p.second;
            if((p2.second - p2.first) > (p.second-p.first)){
                start = p2.first;
                end = p2.second;
            }
            if((end-start+1) > stringLength){
                stringLength = end-start +1;
                answer = s.substr(start,end-start+1);
            }
        }

        return answer;
        
    }
};