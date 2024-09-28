class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> first,second;
        
        for(int i=0;i<s.length();i++){
            if(first.find(s[i])!=first.end()){
               if(t[first[s[i]]]!=t[i]) return false;
            }
            if(second.find(t[i])!=second.end()){
                if(s[second[t[i]]]!=s[i]) return false;
            }
            
            first[s[i]] = i;
            second[t[i]] = i;
        }
        
        return true;
        
    }
};