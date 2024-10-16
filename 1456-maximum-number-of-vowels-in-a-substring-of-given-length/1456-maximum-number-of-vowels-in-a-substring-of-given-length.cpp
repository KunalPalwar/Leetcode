class Solution {
public:
    int maxVowels(string s, int k) {
        int answer = 0;
        unordered_set<char> hash;
        int count = 0;
        hash.insert('a');
        hash.insert('e');
        hash.insert('i');
        hash.insert('o');
        hash.insert('u');
        for(int i=0;i<k;i++){
            if(hash.find(s[i])!=hash.end()){
                count++;
            }
        }
        answer = count;
        int first = 0;
        int second = k;
        while(second < s.length()){
            if(hash.find(s[second])!=hash.end()){
                count++;
            }
           if(hash.find(s[first])!=hash.end()){
               count--;
           }
            first++;
            second++;
            answer = max(answer,count);
        }
        
        return answer;
    }
};