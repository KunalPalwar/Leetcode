class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double answer = INT_MIN;
        int first = 0;
        int second = 0;
        double temp = 0;
        while(second<nums.size()){
            if(second<=k-1){
                while(second<=k-1){
                    temp+=nums[second];
                    second++;
                }
            }else{
                temp-=nums[first];
                temp+=nums[second];
                first++;
                second++;
            }
            
            answer = max(answer,temp/k);
        }
        return answer;
        
    }
};