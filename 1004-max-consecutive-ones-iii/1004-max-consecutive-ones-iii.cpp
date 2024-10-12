class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int first = 0;
        int answer = 0;
        int temp = k;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                if(temp <= 0){
                    while(first<=i){
                        if(nums[first] == 0){
                            //temp++;
                            first++;
                            break;
                        }
                        first++;
                                       
                    }
                }else{
                    temp--;
                }
            }
            answer = max(answer,i-first+1);
        }
        
        return answer;
        
    }
};