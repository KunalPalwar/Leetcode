class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber == 0){
            return "";
        }
        int first = (columnNumber-1)%26;
        int index =  (int)'A' + first;
        char a = (char)(index);
       // cout<<index<<endl;
        return convertToTitle((columnNumber-1)/26) + a;
        
        
    }
};