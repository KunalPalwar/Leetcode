class StockSpanner {
public:
    vector<int> answer;
    StockSpanner() {
        
    }
    
    int next(int price) {
       answer.push_back(price);
        int count = 0;
        for(int i=answer.size()-1;i>=0 && answer[i]<=price;i--){
            count++;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */