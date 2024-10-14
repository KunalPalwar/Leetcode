class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int currentSum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            currentSum+=nums[i];
            if(sum-currentSum == currentSum-nums[i]){
                return i;
            }
        }
        return -1;
        
    }
};