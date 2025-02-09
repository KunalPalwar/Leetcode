class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])!=hash.end()){
                if(hash[nums[i]]>=2) continue;
                hash[nums[i]]++;
            }else{
                hash[nums[i]]++;
            }
        }
        int answer = 0;
        int index = 0;
        for(auto i:hash){
            //cout<<i.first<<" "<<i.second;
            for(int j=0;j<i.second;j++){
                nums[index] = i.first;
                index++;
                answer++;
            }
        }

        return answer;
    }
};