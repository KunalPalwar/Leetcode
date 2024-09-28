class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int count = nums.size();
        int pos = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val){
                count--;
            }else{
                swap(nums[i],nums[pos]);
                pos++;
                
            }
        }
        return count;
    }
    
    
};