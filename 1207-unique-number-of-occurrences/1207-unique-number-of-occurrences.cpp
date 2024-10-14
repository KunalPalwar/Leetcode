class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int> hash;
        unordered_set<int> first;
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        
        for(auto i:hash){
            if(first.find(i.second)!=first.end()) return false;
            first.insert(i.second);
        }
        
        return true;
        
    }
};