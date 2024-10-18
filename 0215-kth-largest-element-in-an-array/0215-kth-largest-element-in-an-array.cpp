class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.size() == k){
                if(hash.top() < nums[i]){
                    hash.pop();
                hash.push(nums[i]);
                }
                
            }else{
                hash.push(nums[i]);
            }
        }
       
        int answer = 0;
        // while(!hash.empty()){
        //     answer = hash.top();
        //     hash.pop();
        // }
        
        return hash.top();
        
    }
};