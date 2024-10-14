class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int height = 0;
        for(int i=0;i<gain.size();i++){
            height+=gain[i];
            maxi = max(maxi,height);
        }
        return maxi;
        
    }
};