class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> result;
        for(int i=0;i<spells.size();i++){
            int num = spells[i];
            int start = 0;
            int end = potions.size()-1;
            int answer = 0;
            while(start<=end){
                int mid = start + (end-start)/2;
                if((num *1ll* potions[mid]) >= success){
                    answer = mid;
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }
            int a = end;
            result.push_back(start>=potions.size()?0:potions.size() - start);

        }
        return result;
    }
};