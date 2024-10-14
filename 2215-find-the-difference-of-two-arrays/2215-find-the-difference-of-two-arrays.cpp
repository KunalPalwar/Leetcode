class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> first,second;
        vector<vector<int> > answer;
        for(int i=0;i<nums1.size();i++){
            first[nums1[i]] = false;
        }
        for(int i=0;i<nums2.size();i++){
            second[nums2[i]] = false;
        }
        vector<int> temp,temp1;
        for(int i=0;i<nums1.size();i++){
            if(second.find(nums1[i]) == second.end()){
                if(first[nums1[i]] == false){
                    temp.push_back(nums1[i]);
                }
                
            }
            first[nums1[i]] = true;
        }
        
        for(int i=0;i<nums2.size();i++){
            if(first.find(nums2[i]) == first.end()){
                if(second[nums2[i]] == false){
                    temp1.push_back(nums2[i]);
                }
            }
            second[nums2[i]] = true;
        }
        
        answer.push_back(temp);
        answer.push_back(temp1);
        
        return answer;
    }
};